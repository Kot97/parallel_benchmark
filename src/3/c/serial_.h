#ifndef PARALLEL_BENCHMARK_SERIAL_3_H
#define PARALLEL_BENCHMARK_SERIAL_3_H

double c3_serial(const double *a, const double *b)
{
    double max = *a;
    const double *temp = a + 1;
    unsigned int size = b - a;
    for(unsigned long i = 1; i < size; ++i, ++temp) if(*temp > max) max = *temp;
    return max;
}

#endif // !1PARALLEL_BENCHMARK_SERIAL_3_H