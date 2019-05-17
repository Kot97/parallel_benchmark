#include "parameters2.hpp"
#include "../src/2/c/serial_.h"
#include "../src/2/c/openmp_.h"
#include "../src/2/cpp/serial_.hpp"
#include "../src/2/cpp/std_.hpp"
#include "../src/2/cpp/tbb_.hpp"

// clang++ -o benchmark2.out benchmark2.cpp -lbenchmark -lbenchmark_main -fopenmp -lpthread -ltbb
// ./benchmark2.out --benchmark_out="../data/1/benchmark2.json" --benchmark_out_format=json --benchmark_report_aggregates_only=true

// ---- C ----

BENCHMARK_FIBONACCI(BM_serial_rec, c2_serial_rec)
BENCHMARK_FIBONACCI_DICT(BM_serial_rec_dict, c2_serial_rec_dict)
BENCHMARK_FIBONACCI(BM_serial_iter, c2_serial_iter)

BENCHMARK_FIBONACCI(BM_openmp_task_rec, c2_openmp_task_rec)
BENCHMARK_FIBONACCI_DICT(BM_openmp_task_rec_dict_lock, c2_openmp_task_rec_dict_lock)
BENCHMARK_FIBONACCI_DICT(BM_openmp_task_rec_dict_critical, c2_openmp_task_rec_dict_critical)

// --- C++ ---

BENCHMARK_FIBONACCI(BM_serial_rec, cpp2_serial_rec)
BENCHMARK_FIBONACCI_MAP(BM_serial_rec_dict, cpp2_serial_rec_dict, map)
BENCHMARK_FIBONACCI(BM_serial_iter, cpp2_serial_iter)

BENCHMARK_FIBONACCI(BM_std_async, cpp2_async)
BENCHMARK_FIBONACCI_MAP(BM_std_async_dict, cpp2_async_dict, map2)

BENCHMARK_FIBONACCI(BM_std_task, cpp2_task)
BENCHMARK_FIBONACCI_MAP(BM_std_task_dict, cpp2_task_dict, map2)

BENCHMARK_FIBONACCI(BM_tbb, cpp2_tbb)
BENCHMARK_FIBONACCI_MAP(BM_tbb_dict, cpp2_tbb_dict, cache)