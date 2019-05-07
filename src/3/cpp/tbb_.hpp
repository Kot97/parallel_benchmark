#ifndef PARALLEL_BENCHMARK_TBB_3_HPP
#define PARALLEL_BENCHMARK_TBB_3_HPP

#include <tbb/blocked_range.h>
#include <tbb/parallel_reduce.h>
#include <tbb/task.h>
#include "serial_.hpp"

template<typename T>
T cpp3_tbb_reduce(const T *a, const T *b)
{
    return tbb::parallel_reduce(tbb::blocked_range<const T*>(a, b), *a, 
    [&](const auto& r, T temp)
    {
        T temp_max = temp;
        for(auto i : r) if (i > temp_max) temp_max = i;
        return temp_max;
    }, 
    [&](T max1, T max2)
    {
        return max1 > max2 ? max1 : max2;
    });
}

constexpr unsigned int search_cutoff = 6;

template<typename T>
class search_task : public tbb::task
{
public:
    const T *a, *b;
    T *const max;
    search_task(const T *a_, const T *b_, T *max_) : a(a_), b(b_), max(max_) {}

    tbb::task* execute() override
    {
        unsigned long size = b - a;
        if(size < search_cutoff) *max = cpp3_serial(a, b);
        else
        {
            T i, j;
            search_task<T> *task1 = new(allocate_child()) search_task<T>(a, b-size/2, &i);
            search_task<T> *task2 = new(allocate_child()) search_task<T>(b-size/2, b, &j);
            set_ref_count(3);
            spawn(*task2);
            spawn_and_wait_for_all(*task1);
            *max = i > j ? i : j;
        }
        return nullptr;
    }
};

template<typename T>
T cpp3_tbb_task(const T *a, const T *b)
{
    if(b - a < search_cutoff) cpp3_serial(a, b);
    T max;
    search_task<T> *task = new(tbb::task::allocate_root()) search_task<T>(a, b, &max);
    tbb::task::spawn_root_and_wait(*task);
    return max;
}

#endif // !1PARALLEL_BENCHMARK_TBB_3_HPP