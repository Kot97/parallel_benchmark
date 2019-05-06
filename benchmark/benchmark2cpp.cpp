#include "parameters2.hpp"
#include "../src/2/cpp/serial_.hpp"
#include "../src/2/cpp/std_.hpp"
#include "../src/2/cpp/tbb_.hpp"

// clang++ -o benchmark2cpp.out benchmark2cpp.cpp -lbenchmark -lbenchmark_main -lpthread -ltbb
// ./benchmark2cpp.out --benchmark_out="../data/1/benchmark2cpp.json" --benchmark_out_format=json --benchmark_report_aggregates_only=true

BENCHMARK_FIBONACCI(BM_serial_rec, cpp2_serial_rec)
BENCHMARK_FIBONACCI_MAP(BM_serial_rec_dict, cpp2_serial_rec_dict, map)
BENCHMARK_FIBONACCI(BM_serial_iter, cpp2_serial_iter)

BENCHMARK_FIBONACCI(BM_std_async, cpp2_async)
BENCHMARK_FIBONACCI_MAP(BM_std_async_dict, cpp2_async_dict, map2)

BENCHMARK_FIBONACCI(BM_std_task, cpp2_task)
BENCHMARK_FIBONACCI_MAP(BM_std_task_dict, cpp2_task_dict, map2)

BENCHMARK_FIBONACCI(BM_tbb, cpp2_tbb)
BENCHMARK_FIBONACCI_MAP(BM_tbb_dict, cpp2_tbb_dict, cache)