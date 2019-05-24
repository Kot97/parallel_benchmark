#ifndef PARALLEL_BENCHMARK_MPI_1_HPP
#define PARALLEL_BENCHMARK_MPI_1_HPP

#include <boost/mpi.hpp>
#include <vector>
#include "../serial_.h"

namespace mpi = boost::mpi;

void _cpp1_mpi_rank0(const mpi::communicator& comm, double *result, const double *a, const double *b, unsigned long size)
{
    int num = comm.size();
    int rest = size % num;

    mpi::request **req = new mpi::request*[3];
    for(int i = 0; i < 3; ++i) req[i] = new mpi::request[num-1];

    unsigned long inc = size/num;   // increment : size of block per node

    const double *a_ = a + inc, *b_ = b + inc;

    for(int i = 1; i < num - 1; ++i, a_+= inc, b_+=inc)
    {
        req[0][i-1] = comm.isend(i, 0, inc);
        req[1][i-1] = comm.isend(i, 1, a_, inc);
        req[2][i-1] = comm.isend(i, 2, b_, inc);
    }

    req[0][num-2] = comm.isend(num-1, 0, inc + rest);
    req[1][num-2] = comm.isend(num-1, 1, a_, inc + rest);
    req[2][num-2] = comm.isend(num-1, 2, b_, inc + rest);

    c1_serial(result, a, b, inc);

    mpi::wait_all(req[0], req[0] + num - 1); 
    mpi::wait_all(req[1], req[1] + num - 1); 
    mpi::wait_all(req[2], req[2] + num - 1); 

    double *result_ = result + inc;

    for(int i = 1; i < num - 1; ++i, result_+=inc)
        req[0][i-1] = comm.irecv(i, 3, result_, inc);

    req[0][num-2] = comm.irecv(num-1, 3, result_, inc + rest);

    mpi::wait_all(req[0], req[0] + num - 1);

    for(int i = 0; i < 3; ++i) delete[] req[i];
    delete[] req;
}

void _cpp1_mpi_others(const mpi::communicator& comm)
{
    unsigned long size;
    comm.recv(0, 0, size);

    double *result = (double*)std::malloc(sizeof(double) * size);
    double *a = (double*)std::malloc(sizeof(double) * size);
    double *b = (double*)std::malloc(sizeof(double) * size);

    mpi::request req[2];
    req[0] = comm.irecv(0, 1, a, size);
    req[1] = comm.irecv(0, 2, b, size);
    mpi::wait_all(req, req+2);

    c1_serial(result, a, b, size);
    comm.send(0, 3, result, size);
    free(result); free(a); free(b);
}

void cpp1_mpi(const mpi::communicator& comm, double *result, const double *a, const double *b, unsigned long size)
{
    if(size < CUTOFF1) 
    { 
       if(comm.rank() == 0) c1_serial(result, a, b, size);
       return;
    }
    if(comm.rank() == 0) _cpp1_mpi_rank0(comm, result, a, b, size);
    else _cpp1_mpi_others(comm);
}

#endif