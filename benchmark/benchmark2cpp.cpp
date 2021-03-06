#include "parameters2.hpp"
#include <2/cpp/serial_.hpp>
#include <2/cpp/std_.hpp>
#include <2/cpp/tbb_.hpp>

// ./benchmark2cpp --benchmark_out="../../data/x/benchmark2cpp.json" --benchmark_out_format=json --benchmark_report_aggregates_only=true

BENCHMARK_FIBONACCI(BM_cpp_serial_rec, cpp2_serial_rec)
BENCHMARK_FIBONACCI_MAP(BM_cpp_serial_rec_dict, cpp2_serial_rec_dict, map)
BENCHMARK_FIBONACCI(BM_cpp_serial_iter, cpp2_serial_iter)

BENCHMARK_FIBONACCI(BM_std_async, cpp2_async)
BENCHMARK_FIBONACCI_MAP_LOW(BM_std_async_dict, cpp2_async_dict, map2)

BENCHMARK_FIBONACCI(BM_std_task, cpp2_task)
BENCHMARK_FIBONACCI_MAP_LOW(BM_std_task_dict, cpp2_task_dict, map2)

BENCHMARK_FIBONACCI(BM_tbb, cpp2_tbb)
BENCHMARK_FIBONACCI_MAP(BM_tbb_dict, cpp2_tbb_dict, cache)