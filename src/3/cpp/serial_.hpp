#ifndef PARALLEL_BENCHMARK_SERIAL_3_HPP
#define PARALLEL_BENCHMARK_SERIAL_3_HPP

#include "../../cutoffs.h"

template<typename T>
T cpp3_serial(const T *a, const T *b)
{
    if(a == b) return *a;
    T max = *a;
    const T *temp = a;
    unsigned int size = b - a;
    for(unsigned long i = 0; i < size; ++i, ++temp) if(*temp > max) max = *temp;
    return max;
}

#endif