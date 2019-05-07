#ifndef PARALLEL_BENCHMARK_SERIAL_3_HPP
#define PARALLEL_BENCHMARK_SERIAL_3_HPP

template<typename T>
T cpp3_serial(const T *a, const T *b)
{
    T max = *a;
    const T *temp = a + 1;
    unsigned int size = b - a;
    for(unsigned long i = 1; i < size; ++i, ++temp) if(*temp > max) max = *temp;
    return max;
}

#endif // !1PARALLEL_BENCHMARK_SERIAL_3_HPP