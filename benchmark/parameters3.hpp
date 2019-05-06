#ifndef PARALLEL_BENCHMARK_BENCHMARK_PARAMETERS_2_HPP
#define PARALLEL_BENCHMARK_BENCHMARK_PARAMETERS_2_HPP

#include <benchmark/benchmark.h>

constexpr int multiplier = 10;
constexpr int min = 10;
constexpr int max = 10000000;
constexpr auto unit = benchmark::kMicrosecond;
constexpr int run_num = 5;

#define BENCHMARK_SEARCH(benchmark_name, function_name) \
static void benchmark_name(benchmark::State& state) \
{\
    for (auto _ : state)\
    {\
        state.PauseTiming();\
        unsigned long size = state.range(0);\
        double *a = (double*)malloc(sizeof(double)*size);\
        state.ResumeTiming();\
        function_name(a, a + size);\
        state.PauseTiming();\
        free(a);\
        state.ResumeTiming();\
    }\
}\
BENCHMARK(benchmark_name)->RangeMultiplier(multiplier)->Range(min, max)->Unit(unit)->UseRealTime()->Repetitions(run_num);

#endif // !1PARALLEL_BENCHMARK_BENCHMARK_PARAMETERS_2_HPP