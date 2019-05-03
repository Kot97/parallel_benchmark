#include <benchmark/benchmark.h>
#include "serial_.h"
#include "pthread_.h"
#include "openmp_.h"

// clang++ -o benchmark.out benchmark.cpp -lbenchmark -lbenchmark_main -fopenmp -lpthread

constexpr int multiplier = 10;
constexpr int min = 100;
constexpr int max = 100000000;
constexpr auto unit = benchmark::kMicrosecond;

static void serial(benchmark::State& state) 
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

BENCHMARK(serial)->RangeMultiplier(multiplier)->Range(min, max)->Unit(unit);
static void pthread(benchmark::State& state) 
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
BENCHMARK(pthread)->RangeMultiplier(multiplier)->Range(min, max)->Unit(unit);

static void openmp_parallel(benchmark::State& state) 
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
BENCHMARK(openmp_parallel)->RangeMultiplier(multiplier)->Range(min, max)->Unit(unit);

static void openmp_parallel_for(benchmark::State& state) 
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
BENCHMARK(openmp_parallel_for)->RangeMultiplier(multiplier)->Range(min, max)->Unit(unit); 

static void openmp_parallel_for_simd(benchmark::State& state) 
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
BENCHMARK(openmp_parallel_for_simd)->RangeMultiplier(multiplier)->Range(min, max)->Unit(unit);