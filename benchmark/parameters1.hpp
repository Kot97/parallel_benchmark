#ifndef PARALLEL_BENCHMARK_BENCHMARK_PARAMETERS_1_HPP
#define PARALLEL_BENCHMARK_BENCHMARK_PARAMETERS_1_HPP

#include <benchmark/benchmark.h>

constexpr int multiplier = 10;
constexpr int min = 100;
constexpr int max = 100000000;
constexpr auto unit = benchmark::kMicrosecond;
constexpr int run_num = 10;

#define BENCHMARK_VECTOR_MULT(benchmark_name, function_name)\
static void benchmark_name(benchmark::State& state) \
{\
    for (auto _ : state)\
    {\
        state.PauseTiming();\
        double* result = (double*)malloc(sizeof(double)*state.range(0));\
        double* a = (double*)malloc(sizeof(double)*state.range(0));\
        double* b = (double*)malloc(sizeof(double)*state.range(0));\
        state.ResumeTiming();\
        function_name(result, a, b, state.range(0));\
        state.PauseTiming();\
        free(result); free(a); free(b);\
        state.ResumeTiming();\
    }\
}\
BENCHMARK(benchmark_name)->RangeMultiplier(multiplier)->Range(min, max)->Unit(unit)->UseRealTime()->Repetitions(run_num);


#endif // !1PARALLEL_BENCHMARK_BENCHMARK_PARAMETERS_1_HPP