#include "parameters2.hpp"
#include "../src/2/c/serial_.h"
#include "../src/2/c/openmp_.h"

// clang++ -o benchmark2c.out benchmark2c.cpp -lbenchmark -lbenchmark_main -fopenmp -lpthread
// ./benchmark2c.out --benchmark_out="../data/1/benchmark2c.json" --benchmark_out_format=json --benchmark_report_aggregates_only=true

BENCHMARK_FIBONACCI(BM_serial_rec, c2_serial_rec)
BENCHMARK_FIBONACCI_DICT(BM_serial_rec_dict, c2_serial_rec_dict)
BENCHMARK_FIBONACCI(BM_serial_iter, c2_serial_iter)

BENCHMARK_FIBONACCI(BM_openmp_task_rec, c2_openmp_task_rec)
BENCHMARK_FIBONACCI_DICT(BM_openmp_task_rec_dict_lock, c2_openmp_task_rec_dict_lock)
BENCHMARK_FIBONACCI_DICT(BM_openmp_task_rec_dict_critical, c2_openmp_task_rec_dict_critical)