#ifndef PARALLEL_BENCHMARK_SERIAL_3_H
#define PARALLEL_BENCHMARK_SERIAL_3_H

#include "../../cutoffs.h"

double c3_serial(const double *a, const double *b)
{
    if(a == b) return *a;
    double max = *a;
    const double *temp = a;
    unsigned int size = b - a;
    for(unsigned long i = 0; i < size; ++i, ++temp) if(*temp > max) max = *temp;
    return max;
}

#endif // !1PARALLEL_BENCHMARK_SERIAL_3_H