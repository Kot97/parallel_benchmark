#ifndef PARALLEL_BENCHMARK_STD_3_HPP
#define PARALLEL_BENCHMARK_STD_3_HPP

#include <thread>
#include <future>
#include <functional>
#include "serial_.hpp"

template<typename T> T cpp3_task(const T *a, const T *b);
template<typename T> T cpp3_async(const T *a, const T *b);

#endif