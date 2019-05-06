#include "parameters3.hpp"
#include "../src/3/c/serial_.h"
#include "../src/3/c/openmp_.h"
#include <cstdlib>

// clang++ -o benchmark3c.out benchmark3c.cpp -lbenchmark -lbenchmark_main -fopenmp -lpthread
// ./benchmark3c.out --benchmark_out="../data/1/benchmark3c.json" --benchmark_out_format=json --benchmark_report_aggregates_only=true

BENCHMARK_SEARCH(BM_serial, c3_serial)
BENCHMARK_SEARCH(BM_openmp_for, c3_openmp_parallel_for)
BENCHMARK_SEARCH(BM_openmp_task, c3_openmp_task)