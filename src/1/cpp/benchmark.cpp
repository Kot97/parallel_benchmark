#include <benchmark/benchmark.h>
#include "serial_.hpp"
#include "std_.hpp"
#include "tbb_.hpp"

// clang++ -o benchmark.out benchmark.cpp -lbenchmark -lbenchmark_main -lpthread -ltbb
// ./benchmark.out --benchmark_out="../../../data/1/cpp/benchmark.json" --benchmark_out_format=json --benchmark_report_aggregates_only=true

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
        cpp1_serial(result, a, b, state.range(0));
        state.PauseTiming();
        free(result); free(a); free(b);
        state.ResumeTiming();
    }
}
BENCHMARK(BM_serial)->RangeMultiplier(multiplier)->Range(min, max)->Unit(unit)->UseRealTime()
                        ->Repetitions(run_num);

static void BM_std(benchmark::State& state) 
{
    for (auto _ : state)
    {
        state.PauseTiming();
        double* result = (double*)malloc(sizeof(double)*state.range(0));
        double* a = (double*)malloc(sizeof(double)*state.range(0));
        double* b = (double*)malloc(sizeof(double)*state.range(0));
        state.ResumeTiming();
        cpp1_thread(result, a, b, state.range(0));
        state.PauseTiming();
        free(result); free(a); free(b);
        state.ResumeTiming();
    }
}
BENCHMARK(BM_std)->RangeMultiplier(multiplier)->Range(min, max)->Unit(unit)->UseRealTime()
                    ->Repetitions(run_num);

static void BM_tbb(benchmark::State& state) 
{
    for (auto _ : state)
    {
        state.PauseTiming();
        double* result = (double*)malloc(sizeof(double)*state.range(0));
        double* a = (double*)malloc(sizeof(double)*state.range(0));
        double* b = (double*)malloc(sizeof(double)*state.range(0));
        state.ResumeTiming();
        cpp1_tbb(result, a, b, state.range(0));
        state.PauseTiming();
        free(result); free(a); free(b);
        state.ResumeTiming();
    }
}
BENCHMARK(BM_tbb)->RangeMultiplier(multiplier)->Range(min, max)->Unit(unit)->UseRealTime()
                    ->Repetitions(run_num);