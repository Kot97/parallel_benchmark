#ifndef PARALLEL_BENCHMARK_BENCHMARK_HPP
#define PARALLEL_BENCHMARK_BENCHMARK_HPP

#include <fstream>
#include <chrono>

int write(const char* filename, const unsigned long* time, const double* value, unsigned long size)
{
    if(time == nullptr || value == nullptr || size == 0) return -1;

    std::ofstream file(filename, std::ios_base::out);
    if(file.bad()) return -2;

    const double *temp_value = value;
    const unsigned long *temp_time = time;
    for(unsigned long i = 0; i < size; ++i, ++temp_time, ++temp_value)
        file << *temp_time << " " << *temp_value << std::endl;

    file.close();
}

auto get_time = []()
{
    return std::chrono::time_point_cast<std::chrono::milliseconds> 
            (std::chrono::steady_clock::now()).time_since_epoch().count();
};

using benchmark_time_t = decltype(get_time());

#endif // !1PARALLEL_BENCHMARK_BENCHMARK_HPP