#ifndef PARALLEL_BENCHMARK_BENCHMARK_PARAMETERS_2_HPP
#define PARALLEL_BENCHMARK_BENCHMARK_PARAMETERS_2_HPP

#include "spec.hpp"
#include <benchmark/benchmark.h>
#include <cstdlib>

#ifdef PARALLEL_BENCHMARK_LOW_SPEC

constexpr int max = 10000000;
constexpr int run_num = 3;

#endif // PARALLEL_BENCHMARK_LOW_SPEC

#ifdef PARALLEL_BENCHMARK_MID_SPEC

constexpr int max = 100000000;
constexpr int run_num = 5;

#endif // PARALLEL_BENCHMARK_MID_SPEC

#ifdef PARALLEL_BENCHMARK_HIGH_SPEC

constexpr int max = 1000000000; // require more than 4 GB RAM
constexpr int run_num = 8;

#endif // PARALLEL_BENCHMARK_HIGH_SPEC

constexpr int multiplier = 10;
constexpr int min = 10;
constexpr auto unit = benchmark::kMicrosecond;

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

#define MPI_BENCHMARK_SEARCH(benchmark_name, function_name) \
static void benchmark_name(benchmark::State& state) \
{\
    for (auto _ : state)\
    {\
        state.PauseTiming();\
        unsigned long size = state.range(0);\
        double *a = (double*)malloc(sizeof(double)*size);\
        double *max = (double*)malloc(sizeof(double));\
        state.ResumeTiming();\
        function_name(MPI_COMM_WORLD, max, a, a + size);\
        state.PauseTiming();\
        free(a);\
        free(max);\
        state.ResumeTiming();\
    }\
}\
BENCHMARK(benchmark_name)->RangeMultiplier(multiplier)->Range(min, max)->Unit(unit)->UseRealTime()->Repetitions(run_num);

#endif