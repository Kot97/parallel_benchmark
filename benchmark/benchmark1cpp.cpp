#include "parameters1.hpp"
#include "../src/1/cpp/serial_.hpp"
#include "../src/1/cpp/std_.hpp"
#include "../src/1/cpp/tbb_.hpp"

// clang++ -o benchmark1cpp.out benchmark1cpp.cpp -lbenchmark -lbenchmark_main -lpthread -ltbb
// ./benchmark1cpp.out --benchmark_out="../data/1/benchmark1cpp.json" --benchmark_out_format=json --benchmark_report_aggregates_only=true

BENCHMARK_VECTOR_MULT(BM_serial, cpp1_serial)
BENCHMARK_VECTOR_MULT(BM_std, cpp1_thread)
BENCHMARK_VECTOR_MULT(BM_tbb, cpp1_tbb)