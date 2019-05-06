#include "parameters.hpp"
#include "../src/1/c/serial_.h"
#include "../src/1/c/pthread_.h"
#include "../src/1/c/openmp_.h"

// clang++ -o benchmark1c.out benchmark1c.cpp -lbenchmark -lbenchmark_main -fopenmp -lpthread
// ./benchmark1c.out --benchmark_out="../data/benchmark1c.json" --benchmark_out_format=json --benchmark_report_aggregates_only=true

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