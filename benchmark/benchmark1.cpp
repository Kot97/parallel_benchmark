#include "parameters1.hpp"
#include "../src/1/serial_.h"
#include "../src/1/c/pthread_.h"
#include "../src/1/c/openmp_.h"
#include "../src/1/cpp/std_.hpp"
#include "../src/1/cpp/tbb_.hpp"

// clang++ -o benchmark1.out benchmark1.cpp -lbenchmark -lbenchmark_main -fopenmp -lpthread -ltbb
// ./benchmark1.out --benchmark_out="../data/1/benchmark1.json" --benchmark_out_format=json --benchmark_report_aggregates_only=true

// ---- C ----

BENCHMARK_VECTOR_MULT(BM_serial, c1_serial)
BENCHMARK_VECTOR_MULT(BM_pthread, c1_pthread)
BENCHMARK_VECTOR_MULT(BM_openmp_parallel, c1_openmp_parallel)
BENCHMARK_VECTOR_MULT(BM_openmp_parallel_for, c1_openmp_parallel_for)
BENCHMARK_VECTOR_MULT(BM_openmp_parallel_for_simd, c1_openmp_parallel_for_simd)

// --- C++ ---

BENCHMARK_VECTOR_MULT(BM_std, cpp1_thread)
BENCHMARK_VECTOR_MULT(BM_tbb, cpp1_tbb)
