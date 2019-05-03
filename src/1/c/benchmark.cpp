#include <benchmark/benchmark.h>
#include "serial_.h"
#include "pthread_.h"
#include "openmp_.h"

// clang++ -o benchmark.out benchmark.cpp -lbenchmark -lbenchmark_main -fopenmp -lpthread
// ./benchmark.out --benchmark_out="../../../data/1/c/benchmark.json" --benchmark_out_format=json --benchmark_report_aggregates_only=true

constexpr int multiplier = 10;
constexpr int min = 100;
constexpr int max = 100000000;
constexpr auto unit = benchmark::kMicrosecond;
constexpr int run_num = 10;

static void BM_serial(benchmark::State& state) 
{
    for (auto _ : state)
    {
        state.PauseTiming();
        double* result = (double*)malloc(sizeof(double)*state.range(0));
        double* a = (double*)malloc(sizeof(double)*state.range(0));
        double* b = (double*)malloc(sizeof(double)*state.range(0));
        state.ResumeTiming();
        c1_serial(result, a, b, state.range(0));
        state.PauseTiming();
        free(result); free(a); free(b);
        state.ResumeTiming();
    }
}

BENCHMARK(BM_serial)->RangeMultiplier(multiplier)->Range(min, max)->Unit(unit)->UseRealTime()
                        ->Repetitions(run_num);
static void BM_pthread(benchmark::State& state) 
{
    for (auto _ : state)
    {
        state.PauseTiming();
        double* result = (double*)malloc(sizeof(double)*state.range(0));
        double* a = (double*)malloc(sizeof(double)*state.range(0));
        double* b = (double*)malloc(sizeof(double)*state.range(0));
        state.ResumeTiming();
        c1_pthread(result, a, b, state.range(0));
        state.PauseTiming();
        free(result); free(a); free(b);
        state.ResumeTiming();
    }
}
BENCHMARK(BM_pthread)->RangeMultiplier(multiplier)->Range(min, max)->Unit(unit)->UseRealTime()
                        ->Repetitions(run_num);

static void BM_openmp_parallel(benchmark::State& state) 
{
    for (auto _ : state)
    {
        state.PauseTiming();
        double* result = (double*)malloc(sizeof(double)*state.range(0));
        double* a = (double*)malloc(sizeof(double)*state.range(0));
        double* b = (double*)malloc(sizeof(double)*state.range(0));
        state.ResumeTiming();
        c1_openmp_parallel(result, a, b, state.range(0));
        state.PauseTiming();
        free(result); free(a); free(b);
        state.ResumeTiming();
    }
}
BENCHMARK(BM_openmp_parallel)->RangeMultiplier(multiplier)->Range(min, max)->Unit(unit)->UseRealTime()
                                ->Repetitions(run_num);

static void BM_openmp_parallel_for(benchmark::State& state) 
{
    for (auto _ : state)
    {
        state.PauseTiming();
        double* result = (double*)malloc(sizeof(double)*state.range(0));
        double* a = (double*)malloc(sizeof(double)*state.range(0));
        double* b = (double*)malloc(sizeof(double)*state.range(0));
        state.ResumeTiming();
        c1_openmp_parallel_for(result, a, b, state.range(0));
        state.PauseTiming();
        free(result); free(a); free(b);
        state.ResumeTiming();
    }
}
BENCHMARK(BM_openmp_parallel_for)->RangeMultiplier(multiplier)->Range(min, max)->Unit(unit)->UseRealTime()
                                    ->Repetitions(run_num); 

static void BM_openmp_parallel_for_simd(benchmark::State& state) 
{
    for (auto _ : state)
    {
        state.PauseTiming();
        double* result = (double*)malloc(sizeof(double)*state.range(0));
        double* a = (double*)malloc(sizeof(double)*state.range(0));
        double* b = (double*)malloc(sizeof(double)*state.range(0));
        state.ResumeTiming();
        c1_openmp_parallel_for_simd(result, a, b, state.range(0));
        state.PauseTiming();
        free(result); free(a); free(b);
        state.ResumeTiming();
    }
}
BENCHMARK(BM_openmp_parallel_for_simd)->RangeMultiplier(multiplier)->Range(min, max)->Unit(unit)->UseRealTime()
                                        ->Repetitions(run_num);