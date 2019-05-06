#ifndef PARALLEL_BENCHMARK_STD_2_HPP
#define PARALLEL_BENCHMARK_STD_2_HPP

#include <unordered_map>
#include <thread>
#include <future>
#include <functional>

unsigned long cpp2_task(long n)
{
    if(n <= 2)  return 1;
    std::packaged_task<unsigned long()> task1(std::bind(cpp2_task, n-1));
    std::packaged_task<unsigned long()> task2(std::bind(cpp2_task, n-2));
    std::future<unsigned long> i = task1.get_future();
    std::future<unsigned long> j = task2.get_future();

    task1();
    task2();
    return i.get() + j.get();
}

unsigned long cpp2_async(long n)
{
    if(n <= 2)  return 1;
    auto task1 = std::async(std::launch::async, cpp2_task, n-1);
    auto task2 = std::async(std::launch::async, cpp2_task, n-2);
    return task1.get() + task2.get();
}

std::unordered_map<long, unsigned long> map2;
std::mutex mutex;

unsigned long cpp2_task_dict(long n)
{
    if (n <= 2) return 1;
    if (map2.find(n) != map2.end()) return map2[n];
    else
    {
        std::packaged_task<unsigned long()> task1(std::bind(cpp2_task, n-1));
        std::packaged_task<unsigned long()> task2(std::bind(cpp2_task, n-2));
        std::future<unsigned long> i = task1.get_future();
        std::future<unsigned long> j = task2.get_future();

        task1();
        task2();
        {
            std::lock_guard<std::mutex> guard(mutex);
            map2[n] =  i.get() + j.get();
        }
        return map2[n];
    } 
}

unsigned long cpp2_async_dict(long n)
{
    if (n <= 2) return 1;
    if (map2.find(n) != map2.end()) return map2[n];
    else
    {
        auto task1 = std::async(std::launch::async, cpp2_task, n-1);
        auto task2 = std::async(std::launch::async, cpp2_task, n-2);
        {
            std::lock_guard<std::mutex> guard(mutex);
            map2[n] =  task1.get() + task2.get();
        }
        return map2[n];
    } 
}

#endif // !1PARALLEL_BENCHMARK_STD_2_HPP