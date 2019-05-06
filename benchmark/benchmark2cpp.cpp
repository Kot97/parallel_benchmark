#include "parameters2.hpp"
#include "../src/2/cpp/serial_.hpp"
#include "../src/2/cpp/std_.hpp"
#include "../src/2/cpp/tbb_.hpp"

// clang++ -o benchmark2cpp.out benchmark2cpp.cpp -lbenchmark -lbenchmark_main -lpthread -ltbb
// ./benchmark2cpp.out --benchmark_out="../data/1/benchmark2cpp.json" --benchmark_out_format=json --benchmark_report_aggregates_only=true

static void BM_serial_rec(benchmark::State& state) 
{
    for (auto _ : state)
    {
        cpp2_serial_rec(state.range(0));
    }
}
BENCHMARK(BM_serial_rec)->Apply(args1)->Unit(unit)->UseRealTime()->Repetitions(run_num);

static void BM_serial_rec_dict(benchmark::State& state) 
{
    for (auto _ : state)
    {
        state.PauseTiming();
        map.clear();
        state.ResumeTiming();
        cpp2_serial_rec_dict(state.range(0));
    }
}
BENCHMARK(BM_serial_rec_dict)->Apply(args2)->Unit(unit)->UseRealTime()->Repetitions(run_num);

static void BM_serial_iter(benchmark::State& state) 
{
    for (auto _ : state)
    {
        cpp2_serial_iter(state.range(0));
    }
}
BENCHMARK(BM_serial_iter)->Apply(args2)->Unit(unit)->UseRealTime()->Repetitions(run_num);

// -------------------------------------------------------------------------------------

static void BM_std_async(benchmark::State& state) 
{
    for (auto _ : state)
    {
        cpp2_async(state.range(0));
    }
}
BENCHMARK(BM_std_async)->Apply(args1)->Unit(unit)->UseRealTime()->Repetitions(run_num);

static void BM_std_async_dict(benchmark::State& state) 
{
    for (auto _ : state)
    {
        state.PauseTiming();
        map2.clear();
        state.ResumeTiming();
        cpp2_async_dict(state.range(0));
    }
}
BENCHMARK(BM_std_async_dict)->Apply(args1)->Unit(unit)->UseRealTime()->Repetitions(run_num);

static void BM_std_task(benchmark::State& state) 
{
    for (auto _ : state)
    {
        cpp2_task(state.range(0));
    }
}
BENCHMARK(BM_std_task)->Apply(args1)->Unit(unit)->UseRealTime()->Repetitions(run_num);

static void BM_std_task_dict(benchmark::State& state) 
{
    for (auto _ : state)
    {
        state.PauseTiming();
        map2.clear();
        state.ResumeTiming();
        cpp2_task_dict(state.range(0));
    }
}
BENCHMARK(BM_std_task_dict)->Apply(args1)->Unit(unit)->UseRealTime()->Repetitions(run_num);

// -----------------------------------------------------------------------------------

static void BM_tbb(benchmark::State& state) 
{
    for (auto _ : state)
    {
        cpp2_tbb(state.range(0));
    }
}
BENCHMARK(BM_tbb)->Apply(args1)->Unit(unit)->UseRealTime()->Repetitions(run_num);

static void BM_tbb_dict(benchmark::State& state) 
{
    for (auto _ : state)
    {
        state.PauseTiming();
        cache.clear();
        state.ResumeTiming();
        cpp2_tbb_dict(state.range(0));
    }
}
BENCHMARK(BM_tbb_dict)->Apply(args2)->Unit(unit)->UseRealTime()->Repetitions(run_num);
