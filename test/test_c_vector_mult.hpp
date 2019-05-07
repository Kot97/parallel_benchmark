#ifndef PARALLEL_BENCHMARK_TEST_C_VECTOR_MULT
#define PARALLEL_BENCHMARK_TEST_C_VECTOR_MULT

#include "../src/1/c/openmp_.h"
#include "../src/1/c/pthread_.h"
#include "test_vector_mult.hpp"

TEST_NULL_INPUT(Pthread, c1_pthread)
TEST_NULL_INPUT(OpenmpParallel, c1_openmp_parallel)
TEST_NULL_INPUT(OpenmpParallelFor, c1_openmp_parallel_for)
TEST_NULL_INPUT(OpenmpParallelForSimd, c1_openmp_parallel_for_simd)

TEST_VECTOR_MULT(Pthread, c1_pthread)
TEST_VECTOR_MULT(OpenmpParallel, c1_openmp_parallel)
TEST_VECTOR_MULT(OpenmpParallelFor, c1_openmp_parallel_for)
TEST_VECTOR_MULT(OpenmpParallelForSimd, c1_openmp_parallel_for_simd)

#endif // !1PARALLEL_BENCHMARK_TEST_C_VECTOR_MULT