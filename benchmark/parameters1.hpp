#ifndef PARALLEL_BENCHMARK_BENCHMARK_PARAMETERS_1_HPP
#define PARALLEL_BENCHMARK_BENCHMARK_PARAMETERS_1_HPP

#include <benchmark/benchmark.h>

constexpr int multiplier = 10;
constexpr int min = 100;
constexpr int max = 100000000;
constexpr auto unit = benchmark::kMicrosecond;
constexpr int run_num = 10;

#endif // !1PARALLEL_BENCHMARK_BENCHMARK_PARAMETERS_1_HPP