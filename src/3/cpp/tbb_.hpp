#ifndef PARALLEL_BENCHMARK_TBB_3_HPP
#define PARALLEL_BENCHMARK_TBB_3_HPP

#include <tbb/blocked_range.h>
#include <tbb/parallel_reduce.h>
#include <tbb/task.h>
#include "serial_.hpp"

template<typename T> T cpp3_tbb_reduce(const T *a, const T *b);
template<typename T> T cpp3_tbb_task(const T *a, const T *b);

template<typename T>
class search_task : public tbb::task
{
public:
    const T *a, *b;
    T *const max;
    search_task(const T *a_, const T *b_, T *max_) : a(a_), b(b_), max(max_) {}
    tbb::task* execute() override;
};

#endif