#ifndef PARALLEL_BENCHMARK_MPI_3_HPP
#define PARALLEL_BENCHMARK_MPI_3_HPP

#include <boost/mpi.hpp>
#include <boost/mpi/collectives/reduce.hpp>
#include <cstdlib>
#include "serial_.hpp"
#include "tbb_.hpp"

namespace mpi = boost::mpi;

template<typename T> void _cpp3_mpi_rank0(const mpi::communicator& comm, T *max, const T *a, const T *b);
template<typename T> void _cpp3_mpi_others(const mpi::communicator& comm);
template<typename T> void cpp3_mpi(const mpi::communicator& comm, T *max, const T *a, const T *b);

template<typename T> void _cpp3_mpi_rank0_tbb(const mpi::communicator& comm, T *max, const T *a, const T *b);
template<typename T> void _cpp3_mpi_others_tbb(const mpi::communicator& comm);
template<typename T> void cpp3_mpi_tbb(const mpi::communicator& comm, T *max, const T *a, const T *b);
#endif