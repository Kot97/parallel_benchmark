#ifndef PARALLEL_BENCHMARK_SERIAL_1_H
#define PARALLEL_BENCHMARK_SERIAL_1_H

#include "../cutoffs.h"

void c1_serial(double *result, const double *a, const double *b, unsigned long size)
{
    double *temp_result = result;
    const double *temp_a = a, *temp_b = b;
    for(unsigned long i = 0; i < size; ++i, ++temp_result, ++temp_a, ++temp_b)
        *temp_result = *temp_a * *temp_b;
}

#endif // !1PARALLEL_BENCHMARK_SERIAL_1_H