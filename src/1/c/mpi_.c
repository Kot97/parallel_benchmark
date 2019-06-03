#include "mpi_.h"

void _c1_mpi_rank0(const MPI_Comm comm, double *result, const double *a, const double *b, unsigned long size)
{
    int num;
    MPI_Comm_size(comm, &num);

    MPI_Request **req = (MPI_Request**)malloc(sizeof(MPI_Request*) * 2);
    for(int i = 0; i < 2; ++i) req[i] = (MPI_Request*)malloc(sizeof(MPI_Request) * (num-1));

    unsigned long inc = size/num;   // increment : size of block per node
    unsigned int rest = size % num;
    const double *a_ = a + inc, *b_ = b + inc;

    for(int i = 1; i < num - 1; ++i, a_+= inc, b_+=inc)
    {
        MPI_Isend(a_, inc, MPI_DOUBLE, i, 1, comm, &(req[0][i-1]));
        MPI_Isend(b_, inc, MPI_DOUBLE, i, 2, comm, &(req[1][i-1]));
    }

    unsigned long inc_rest = inc + rest;
    MPI_Isend(a_, inc_rest, MPI_DOUBLE, num-1, 1, comm, &(req[0][num-2]));
    MPI_Isend(b_, inc_rest, MPI_DOUBLE, num-1, 2, comm, &(req[1][num-2]));

    c1_serial(result, a, b, inc);

    MPI_Waitall(num-1, req[0], MPI_STATUS_IGNORE);
    MPI_Waitall(num-1, req[1], MPI_STATUS_IGNORE);


    double *result_ = result + inc;

    for(int i = 1; i < num - 1; ++i, result_+=inc)
        MPI_Irecv(result_, inc, MPI_DOUBLE, i, 3, comm, &(req[0][i-1]));

    MPI_Irecv(result_, inc_rest, MPI_DOUBLE, num-1, 3, comm, &(req[0][num-2]));

    MPI_Waitall(num-1, req[0], MPI_STATUS_IGNORE);

    for(int i = 0; i < 2; ++i) free(req[i]);
    free(req);
}

void _c1_mpi_others(const MPI_Comm comm)
{
    int size;
    MPI_Status status;
    MPI_Probe(0, 1, comm, &status);
    MPI_Get_count(&status, MPI_DOUBLE, &size);

    double *result = (double*)malloc(sizeof(double) * size);
    double *a = (double*)malloc(sizeof(double) * size);
    double *b = (double*)malloc(sizeof(double) * size);

    MPI_Request req[2];
    MPI_Irecv(a, size, MPI_DOUBLE, 0, 1, comm, req);
    MPI_Irecv(b, size, MPI_DOUBLE, 0, 2, comm, req+1);
    MPI_Waitall(2, req, MPI_STATUS_IGNORE);

    c1_serial(result, a, b, size);
    MPI_Send(result, size, MPI_DOUBLE, 0, 3, comm);
    free(result); free(a); free(b);
}

void c1_mpi(const MPI_Comm comm, double *result, const double *a, const double *b, unsigned long size)
{
    int rank;
    MPI_Comm_rank(comm, &rank);
    if(size < CUTOFF1) 
    { 
       if(rank == 0) c1_serial(result, a, b, size);
       return;
    }
    if(rank == 0) _c1_mpi_rank0(comm, result, a, b, size);
    else _c1_mpi_others(comm);
}

void _c1_mpi_rank0_openmp(const MPI_Comm comm, double *result, const double *a, const double *b, unsigned long size)
{
    int num;
    MPI_Comm_size(comm, &num);

    MPI_Request **req = (MPI_Request**)malloc(sizeof(MPI_Request*) * 2);
    for(int i = 0; i < 2; ++i) req[i] = (MPI_Request*)malloc(sizeof(MPI_Request) * (num-1));

    unsigned long inc = size/num;   // increment : size of block per node
    int rest = size % num;
    const double *a_ = a + inc, *b_ = b + inc;

    for(int i = 1; i < num - 1; ++i, a_+= inc, b_+=inc)
    {
        MPI_Isend(a_, inc, MPI_DOUBLE, i, 1, comm, &(req[0][i-1]));
        MPI_Isend(b_, inc, MPI_DOUBLE, i, 2, comm, &(req[1][i-1]));
    }

    unsigned long inc_rest = inc + rest;
    MPI_Isend(a_, inc_rest, MPI_DOUBLE, num-1, 1, comm, &(req[0][num-2]));
    MPI_Isend(b_, inc_rest, MPI_DOUBLE, num-1, 2, comm, &(req[1][num-2]));

    c1_openmp_parallel_for_simd(result, a, b, inc);

    MPI_Waitall(num-1, req[0], MPI_STATUS_IGNORE);
    MPI_Waitall(num-1, req[1], MPI_STATUS_IGNORE);

    double *result_ = result + inc;

    for(int i = 1; i < num - 1; ++i, result_+=inc)
        MPI_Irecv(result_, inc, MPI_DOUBLE, i, 3, comm, &(req[0][i-1]));

    MPI_Irecv(result_, inc_rest, MPI_DOUBLE, num-1, 3, comm, &(req[0][num-2]));

    MPI_Waitall(num-1, req[0], MPI_STATUS_IGNORE);

    for(int i = 0; i < 2; ++i) free(req[i]);
    free(req);
}

void _c1_mpi_others_openmp(const MPI_Comm comm)
{
    int size;
    MPI_Status status;
    MPI_Probe(0, 1, comm, &status);
    MPI_Get_count(&status, MPI_DOUBLE, &size);

    double *result = (double*)malloc(sizeof(double) * size);
    double *a = (double*)malloc(sizeof(double) * size);
    double *b = (double*)malloc(sizeof(double) * size);

    MPI_Request req[2];
    MPI_Irecv(a, size, MPI_DOUBLE, 0, 1, comm, req);
    MPI_Irecv(b, size, MPI_DOUBLE, 0, 2, comm, req+1);
    MPI_Waitall(2, req, MPI_STATUS_IGNORE);

    c1_openmp_parallel_for_simd(result, a, b, size);
    MPI_Send(result, size, MPI_DOUBLE, 0, 3, comm);
    free(result); free(a); free(b);
}

void c1_mpi_openmp(const MPI_Comm comm, double *result, const double *a, const double *b, unsigned long size)
{
    int rank;
    MPI_Comm_rank(comm, &rank);
    if(size < CUTOFF1) 
    { 
       if(rank == 0) c1_serial(result, a, b, size);
       return;
    }
    if(rank == 0) _c1_mpi_rank0_openmp(comm, result, a, b, size);
    else _c1_mpi_others_openmp(comm);
}