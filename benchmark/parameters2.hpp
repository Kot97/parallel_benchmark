#ifndef PARALLEL_BENCHMARK_BENCHMARK_PARAMETERS_2_HPP
#define PARALLEL_BENCHMARK_BENCHMARK_PARAMETERS_2_HPP

#include <benchmark/benchmark.h>

constexpr int step = 5;
constexpr int min = 5;
constexpr int max1 = 35;
constexpr int max2 = 85;
constexpr auto unit = benchmark::kMicrosecond;
constexpr int run_num = 3;

static void args1(benchmark::internal::Benchmark* b) 
{
    for (int i = min; i <= max1; i+=step) b->Args({i});
};

static void args2(benchmark::internal::Benchmark* b) 
{
    for (int i = min; i <= max2; i+=step) b->Args({i});
};

#endif // !1PARALLEL_BENCHMARK_BENCHMARK_PARAMETERS_2_HPP