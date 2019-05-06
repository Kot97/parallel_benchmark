#include "parameters1.hpp"
#include "../src/1/c/serial_.h"
#include "../src/1/c/pthread_.h"
#include "../src/1/c/openmp_.h"

// clang++ -o benchmark1c.out benchmark1c.cpp -lbenchmark -lbenchmark_main -fopenmp -lpthread
// ./benchmark1c.out --benchmark_out="../data/1/benchmark1c.json" --benchmark_out_format=json --benchmark_report_aggregates_only=true

BENCHMARK_VECTOR_MULT(BM_serial, c1_serial)
BENCHMARK_VECTOR_MULT(BM_pthread, c1_pthread)
BENCHMARK_VECTOR_MULT(BM_openmp_parallel, c1_openmp_parallel)
BENCHMARK_VECTOR_MULT(BM_openmp_parallel_for, c1_openmp_parallel_for)
BENCHMARK_VECTOR_MULT(BM_openmp_parallel_for_simd, c1_openmp_parallel_for_simd)