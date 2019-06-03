#ifndef PARALLEL_BENCHMARK_MPI_3_H
#define PARALLEL_BENCHMARK_MPI_3_H

#include <mpi.h>
#include <stdlib.h>
#include "serial_.h"
#include "openmp_.h"

#ifdef __cplusplus
extern "C" {
#endif

void _c3_mpi_rank0(const MPI_Comm comm, double *max, const double *a, const double *b);
void _c3_mpi_others(const MPI_Comm comm);
void c3_mpi(const MPI_Comm comm, double *max, const double *a, const double *b);

void _c3_mpi_rank0_openmp(const MPI_Comm comm, double *max, const double *a, const double *b);
void _c3_mpi_others_openmo(const MPI_Comm comm);
void c3_mpi_openmp(const MPI_Comm comm, double *max, const double *a, const double *b);

#ifdef __cplusplus
}
#endif

#endif