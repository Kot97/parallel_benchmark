#include "parameters3.hpp"
// #include "../src/3/c/serial_.h"
// #include "../src/3/c/openmp_.h"
// #include "../src/3/cpp/serial_.hpp"
// #include "../src/3/cpp/std_.hpp"
// #include "../src/3/cpp/tbb_.hpp"
#include <3/c/serial_.h>
#include <3/c/openmp_.h>
#include <3/cpp/serial_.hpp>
#include <3/cpp/std_.hpp>
#include <3/cpp/tbb_.hpp>

// clang++ -o benchmark3.out benchmark3.cpp -lbenchmark -lbenchmark_main -fopenmp -lpthread -ltbb
// ./benchmark3.out --benchmark_out="../data/x/benchmark3.json" --benchmark_out_format=json --benchmark_report_aggregates_only=true

// ---- C ----

BENCHMARK_SEARCH(BM_c_serial, c3_serial)
BENCHMARK_SEARCH(BM_openmp_for, c3_openmp_parallel_for)
BENCHMARK_SEARCH(BM_openmp_task, c3_openmp_task)

// --- C++ ---

BENCHMARK_SEARCH(BM_cpp_serial, cpp3_serial)
BENCHMARK_SEARCH(BM_async, cpp3_async)
BENCHMARK_SEARCH(BM_task, cpp3_task)
BENCHMARK_SEARCH(BM_tbb_reduce, cpp3_tbb_reduce)
BENCHMARK_SEARCH(BM_tbb_task, cpp3_tbb_task)