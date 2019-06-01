#ifndef PARALLEL_BENCHMARK_TBB_2_HPP
#define PARALLEL_BENCHMARK_TBB_2_HPP

#include <tbb/task.h>
#include <tbb/concurrent_hash_map.h>
#include "serial_.hpp"

using cache_t = tbb::concurrent_hash_map<long, unsigned long>;
extern cache_t cache;

unsigned long cpp2_serial_rec_dict_p(long n);

class fib_task : public tbb::task
{
public:
    const long n;
    unsigned long *const sum;
    fib_task(long n_, unsigned long *sum_) : n(n_), sum(sum_) {}

    tbb::task* execute() override;
};

unsigned long cpp2_tbb(long n);

class fib_task_dict : public tbb::task
{
public:
    const long n;
    unsigned long *const sum;
    fib_task_dict(long n_, unsigned long *sum_) : n(n_), sum(sum_) {}

    tbb::task* execute() override;
};

unsigned long cpp2_tbb_dict(long n);

#endif