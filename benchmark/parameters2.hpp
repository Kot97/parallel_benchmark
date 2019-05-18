#ifndef PARALLEL_BENCHMARK_BENCHMARK_PARAMETERS_2_HPP
#define PARALLEL_BENCHMARK_BENCHMARK_PARAMETERS_2_HPP

#include "spec.hpp"
#include <benchmark/benchmark.h>

#ifdef PARALLEL_BENCHMARK_LOW_SPEC

constexpr int max1 = 35;
constexpr int max2 = 70;
constexpr int run_num = 3;

#endif // PARALLEL_BENCHMARK_LOW_SPEC

#ifdef PARALLEL_BENCHMARK_MID_SPEC

constexpr int max1 = 45;
constexpr int max2 = 80;
constexpr int run_num = 5;

#endif // PARALLEL_BENCHMARK_MID_SPEC

#ifdef PARALLEL_BENCHMARK_HIGH_SPEC

constexpr int max1 = 50;
constexpr int max2 = 85;
constexpr int run_num = 8;

#endif // PARALLEL_BENCHMARK_HIGH_SPEC

constexpr int step = 5;
constexpr int min = 5;
constexpr auto unit = benchmark::kMicrosecond;

static void args1(benchmark::internal::Benchmark* b) 
{
    for (int i = min; i <= max1; i+=step) b->Args({i});
};

static void args2(benchmark::internal::Benchmark* b) 
{
    for (int i = min; i <= max2; i+=step) b->Args({i});
};

#define BENCHMARK_FIBONACCI(benchmark_name, function_name)\
static void benchmark_name(benchmark::State& state) \
{\
    for (auto _ : state)\
    {\
        function_name(state.range(0));\
    }\
}\
BENCHMARK(benchmark_name)->Apply(args1)->Unit(unit)->UseRealTime()->Repetitions(run_num);

#define BENCHMARK_FIBONACCI_DICT(benchmark_name, function_name)\
static void benchmark_name(benchmark::State& state)\
{\
    for (auto _ : state)\
    {\
        state.PauseTiming();\
        for(int i = 0; i < DCACHE_SIZE; ++i) dictionary[i] = 0;\
        state.ResumeTiming();\
        function_name(state.range(0));\
    }\
}\
BENCHMARK(benchmark_name)->Apply(args2)->Unit(unit)->UseRealTime()->Repetitions(run_num);

#define BENCHMARK_FIBONACCI_MAP(benchmark_name, function_name, map_name)\
static void benchmark_name(benchmark::State& state)\
{\
    for (auto _ : state)\
    {\
        state.PauseTiming();\
        map_name.clear();\
        state.ResumeTiming();\
        function_name(state.range(0));\
    }\
}\
BENCHMARK(benchmark_name)->Apply(args2)->Unit(unit)->UseRealTime()->Repetitions(run_num);

#define BENCHMARK_FIBONACCI_MAP_LOW(benchmark_name, function_name, map_name)\
static void benchmark_name(benchmark::State& state)\
{\
    for (auto _ : state)\
    {\
        state.PauseTiming();\
        map_name.clear();\
        state.ResumeTiming();\
        function_name(state.range(0));\
    }\
}\
BENCHMARK(benchmark_name)->Apply(args1)->Unit(unit)->UseRealTime()->Repetitions(run_num);



#endif // !1PARALLEL_BENCHMARK_BENCHMARK_PARAMETERS_2_HPP