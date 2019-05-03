#ifndef PARALLEL_BENCHMARK_STD_1_HPP
#define PARALLEL_BENCHMARK_STD_1_HPP

#include <thread>
#include <vector>

unsigned int num_threads = std::thread::hardware_concurrency();

void __cpp1_thread(int id, double *result, double *a, double *b, unsigned long size)
{
    unsigned long end = size / num_threads;
    for(unsigned long i = 0; i < end; ++i, result+=num_threads, a+=num_threads, b+=num_threads)
        *result = *a * *b;
    
    if(id == num_threads-1 && size % num_threads != 0)
    {
        result -= (num_threads-1); 
        a -= (num_threads-1); 
        b -= (num_threads-1); 
        for(unsigned long i = size - size%num_threads; i < size; ++i, ++result, ++a, ++b)
            *result = *a * *b;
    }
} 

void cpp1_thread(double *result, double *a, double *b, unsigned long size, int num_threads=4)
{
    std::vector<std::thread> threads;

    for(int i = 0; i < num_threads; ++i)
        threads.emplace_back(__cpp1_thread, i, result + i, a + i, b + i, size);

    for(auto& i : threads) i.join();
}

#endif // !1PARALLEL_BENCHMARK_STD_1_HPP