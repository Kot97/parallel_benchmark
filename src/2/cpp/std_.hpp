#ifndef PARALLEL_BENCHMARK_STD_2_HPP
#define PARALLEL_BENCHMARK_STD_2_HPP

#include <unordered_map>
#include <thread>
#include <future>
#include <functional>
#include "serial_.hpp"

unsigned long cpp2_task(long n);
unsigned long cpp2_async(long n);

std::unordered_map<long, unsigned long> map2;
std::mutex mutex;

unsigned long cpp2_task_dict(long n);
unsigned long cpp2_async_dict(long n);

#endif