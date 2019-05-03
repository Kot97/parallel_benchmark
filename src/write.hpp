#ifndef PARALLEL_BENCHMARK_BENCHMARK_HPP
#define PARALLEL_BENCHMARK_BENCHMARK_HPP

#include <fstream>
#include <chrono>

auto get_time = []()
{
    return std::chrono::time_point_cast<std::chrono::milliseconds> 
            (std::chrono::steady_clock::now()).time_since_epoch().count();
};

using benchmark_time_t = decltype(get_time());

int write(const char* filename, const unsigned long* task_size, const benchmark_time_t* time_value, unsigned long size)
{
    if(task_size == nullptr || time_value == nullptr || size == 0) return -1;

    std::ofstream file(filename, std::ios_base::out);
    if(file.bad()) return -2;

    const benchmark_time_t *temp_time_value = time_value;
    const unsigned long *temp_task_size = task_size;
    for(unsigned long i = 0; i < size; ++i, ++temp_time_value, ++temp_task_size)
        file << *temp_task_size << " " << *temp_time_value << std::endl;

    file.close();
}

#endif // !1PARALLEL_BENCHMARK_BENCHMARK_HPP