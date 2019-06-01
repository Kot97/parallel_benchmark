#ifndef PARALLEL_BENCHMARK_MPI_1_H
#define PARALLEL_BENCHMARK_MPI_1_H

#include <mpi.h>
#include <stdlib.h>
#include "openmp_.h"

void _c1_mpi_rank0(const MPI_Comm comm, double *result, const double *a, const double *b, unsigned long size);
void _c1_mpi_others(const MPI_Comm comm);
void c1_mpi(const MPI_Comm comm, double *result, const double *a, const double *b, unsigned long size);

void _c1_mpi_rank0_openmp(const MPI_Comm comm, double *result, const double *a, const double *b, unsigned long size);
void _c1_mpi_others_openmp(const MPI_Comm comm);
void c1_mpi_openmp(const MPI_Comm comm, double *result, const double *a, const double *b, unsigned long size);

#endif