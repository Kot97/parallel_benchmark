#include "mpi_.h"

void _c3_mpi_rank0(const MPI_Comm comm, double *max, const double *a, const double *b)
{
    int num;
    MPI_Comm_size(comm, &num);

    const unsigned long inc = (b - a)/num;     //size of work per node
    const unsigned long rest = (b - a) % num;

    MPI_Request *req = (MPI_Request*)malloc(sizeof(MPI_Request) * (num - 1));
    MPI_Request *temp = req;

    const double *a_ = a + inc;
    for(int i = 1; i < num - 1; ++i, a_+=inc, ++temp)
        MPI_Isend(a_, inc, MPI_DOUBLE, i, 0, comm, temp);

    MPI_Isend(a_, inc + rest, MPI_DOUBLE, num-1, 0, comm, temp);
    *max = c3_serial(a, a + inc);
    
    MPI_Waitall(num-1, req, MPI_STATUS_IGNORE);

    MPI_Reduce(MPI_IN_PLACE, max, 1, MPI_DOUBLE, MPI_MAX, 0, comm);
    free(req);
}

void _c3_mpi_others(const MPI_Comm comm)
{
    int size;
    MPI_Status stat;
    MPI_Probe(0, 0, comm, &stat);
    MPI_Get_count(&stat, MPI_DOUBLE, &size);

    double *a = (double*)malloc(sizeof(double)*size);
    MPI_Recv(a, size, MPI_DOUBLE, 0, 0, comm, MPI_STATUS_IGNORE);

    double max = c3_serial(a, a + size);
    MPI_Reduce(&max, &max, 1, MPI_DOUBLE, MPI_MAX, 0, comm);
    free(a);
}

void c3_mpi(const MPI_Comm comm, double *max, const double *a, const double *b)
{
    int rank;
    MPI_Comm_rank(comm, &rank);
    const unsigned long size = b - a;

    if(size < CUTOFF3)
    {
        if(rank == 0) *max = c3_serial(a, b);
        return;
    }
    if(rank == 0) _c3_mpi_rank0(comm, max, a, b);
    else _c3_mpi_others(comm);
}

void _c3_mpi_rank0_openmp(const MPI_Comm comm, double *max, const double *a, const double *b)
{
    int num;
    MPI_Comm_size(comm, &num);

    const unsigned long inc = (b - a)/num;     //size of work per node
    const unsigned long rest = (b - a) % num;

    MPI_Request *req = (MPI_Request*)malloc(sizeof(MPI_Request) * (num - 1));
    MPI_Request *temp = req;

    const double *a_ = a + inc;
    for(int i = 1; i < num - 1; ++i, a_+=inc, ++temp)
        MPI_Isend(a_, inc, MPI_DOUBLE, i, 0, comm, temp);

    MPI_Isend(a_, inc + rest, MPI_DOUBLE, num-1, 0, comm, temp);
    *max = c3_openmp_parallel_for(a, a + inc);
    
    MPI_Waitall(num-1, req, MPI_STATUS_IGNORE);

    MPI_Reduce(MPI_IN_PLACE, max, 1, MPI_DOUBLE, MPI_MAX, 0, comm);
    free(req);
}

void _c3_mpi_others_openmp(const MPI_Comm comm)
{
    int size;
    MPI_Status stat;
    MPI_Probe(0, 0, comm, &stat);
    MPI_Get_count(&stat, MPI_DOUBLE, &size);

    double *a = (double*)malloc(sizeof(double)*size);
    MPI_Recv(a, size, MPI_DOUBLE, 0, 0, comm, MPI_STATUS_IGNORE);

    double max = c3_openmp_parallel_for(a, a + size);
    MPI_Reduce(&max, &max, 1, MPI_DOUBLE, MPI_MAX, 0, comm);
    free(a);
}

void c3_mpi_openmp(const MPI_Comm comm, double *max, const double *a, const double *b)
{
    int rank;
    MPI_Comm_rank(comm, &rank);
    const unsigned long size = b - a;

    if(size < CUTOFF3)
    {
        if(rank == 0) *max = c3_serial(a, b);
        return;
    }
    if(rank == 0) _c3_mpi_rank0_openmp(comm, max, a, b);
    else _c3_mpi_others_openmp(comm);
}