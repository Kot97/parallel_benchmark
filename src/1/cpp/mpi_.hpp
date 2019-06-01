#ifndef PARALLEL_BENCHMARK_MPI_1_HPP
#define PARALLEL_BENCHMARK_MPI_1_HPP

#include <boost/mpi.hpp>
#include <cstdlib>
#include "serial_.hpp"
#include "tbb_.hpp"

namespace mpi = boost::mpi;

void _cpp1_mpi_rank0(const mpi::communicator& comm, double *result, const double *a, const double *b, unsigned long size);
void _cpp1_mpi_others(const mpi::communicator& comm);
void cpp1_mpi(const mpi::communicator& comm, double *result, const double *a, const double *b, unsigned long size);

void _cpp1_mpi_rank0_tbb(const mpi::communicator& comm, double *result, const double *a, const double *b, unsigned long size);
void _cpp1_mpi_others_tbb(const mpi::communicator& comm);
void cpp1_mpi_tbb(const mpi::communicator& comm, double *result, const double *a, const double *b, unsigned long size);
#endif