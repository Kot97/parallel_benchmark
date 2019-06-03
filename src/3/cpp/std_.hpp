#ifndef PARALLEL_BENCHMARK_STD_3_HPP
#define PARALLEL_BENCHMARK_STD_3_HPP

#include <thread>
#include <future>
#include <functional>
#include "serial_.hpp"

template<typename T>
T cpp3_task(const T *a, const T *b)
{
    unsigned long size = b - a;
    if(size < CUTOFF3) return cpp3_serial(a, b);
    std::packaged_task<T()> task1(std::bind(cpp3_task<T>, a, b - size/2));
    std::packaged_task<T()> task2(std::bind(cpp3_task<T>, b - size/2, b));
    std::future<T> max1 = task1.get_future(), max2 = task2.get_future();
    task1(); task2();
    auto m1 = max1.get();
    auto m2 = max2.get();
    return m1 > m2 ? m1 : m2;
}

template<typename T>
T cpp3_async(const T *a, const T *b)
{
    unsigned long size = b - a;
    if(size < CUTOFF3) return cpp3_serial(a, b);
    auto task1 = std::async(std::launch::async, cpp3_task<T>, a, b - size/2);
    auto task2 = std::async(std::launch::async, cpp3_task<T>, b - size/2, b);
    auto m1 = task1.get();
    auto m2 = task2.get();
    return m1 > m2 ? m1 : m2;
}

#endif