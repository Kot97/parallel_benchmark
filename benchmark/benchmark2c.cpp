#include "parameters2.hpp"
#include "../src/2/c/serial_.h"
#include "../src/2/c/openmp_.h"
#include <iostream>

// clang++ -o benchmark2c.out benchmark2c.cpp -lbenchmark -lbenchmark_main -fopenmp -lpthread
// ./benchmark2c.out --benchmark_out="../data/1/benchmark2c.json" --benchmark_out_format=json --benchmark_report_aggregates_only=true

static void BM_serial_rec(benchmark::State& state) 
{
    for (auto _ : state)
    {
        c2_serial_rec(state.range(0));
    }
}
BENCHMARK(BM_serial_rec)->Apply(args1)->Unit(unit)->UseRealTime()->Repetitions(run_num);

static void BM_serial_rec_dict(benchmark::State& state) 
{
    for (auto _ : state)
    {
        state.PauseTiming();
        for(int i = 0; i < DCACHE_SIZE; ++i) dictionary[i] = 0;
        state.ResumeTiming();
        c2_serial_rec_dict(state.range(0));
    }
}
BENCHMARK(BM_serial_rec_dict)->Apply(args2)->Unit(unit)->UseRealTime()->Repetitions(run_num);

static void BM_serial_iter(benchmark::State& state) 
{
    for (auto _ : state)
    {
        c2_serial_iter(state.range(0));
    }
}
BENCHMARK(BM_serial_iter)->Apply(args2)->Unit(unit)->UseRealTime()->Repetitions(run_num);

// -------------------------------------------------------------------------------------

static void BM_openmp_task_rec(benchmark::State& state) 
{
    for (auto _ : state)
    {
        c2_openmp_task_rec(state.range(0));
    }
}
BENCHMARK(BM_openmp_task_rec)->Apply(args1)->Unit(unit)->UseRealTime()->Repetitions(run_num);

static void BM_openmp_task_rec_dict_lock(benchmark::State& state) 
{
    for (auto _ : state)
    {
        state.PauseTiming();
        for(int i = 0; i < DCACHE_SIZE; i++) dictionary[i] = 0;
        state.ResumeTiming();
        c2_openmp_task_rec_dict_lock(state.range(0));
    }
}
BENCHMARK(BM_openmp_task_rec_dict_lock)->Apply(args2)->Unit(unit)->UseRealTime()->Repetitions(run_num);

static void BM_openmp_task_rec_dict_critical(benchmark::State& state) 
{
    for (auto _ : state)
    {
        state.PauseTiming();
        for(int i = 0; i < DCACHE_SIZE; i++) dictionary[i] = 0;
        state.ResumeTiming();
        c2_openmp_task_rec_dict_critical(state.range(0));
    }
}
BENCHMARK(BM_openmp_task_rec_dict_critical)->Apply(args2)->Unit(unit)->UseRealTime()->Repetitions(run_num);
