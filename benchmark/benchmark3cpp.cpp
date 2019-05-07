#include "parameters3.hpp"
#include "../src/3/cpp/serial_.hpp"
#include "../src/3/cpp/std_.hpp"
#include "../src/3/cpp/tbb_.hpp"

// clang++ -o benchmark3cpp.out benchmark3cpp.cpp -lbenchmark -lbenchmark_main -lpthread -ltbb
// ./benchmark3cpp.out --benchmark_out="../data/1/benchmark3cpp.json" --benchmark_out_format=json --benchmark_report_aggregates_only=true

BENCHMARK_SEARCH(BM_serial, cpp3_serial)
BENCHMARK_SEARCH(BM_async, cpp3_async)
BENCHMARK_SEARCH(BM_task, cpp3_task)
BENCHMARK_SEARCH(BM_tbb_reduce, cpp3_tbb_reduce)
BENCHMARK_SEARCH(BM_tbb_task, cpp3_tbb_task)