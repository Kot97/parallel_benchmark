#ifndef PARALLEL_BENCHMARK_SERIAL_1_HPP
#define PARALLEL_BENCHMARK_SERIAL_1_HPP

void cpp1_serial(double *result, double *a, double *b, unsigned long size)
{
    double *temp_result = result, *temp_a = a, *temp_b = b;
    for(unsigned long i = 0; i < size; ++i, ++temp_result, ++temp_a, ++temp_b)
        *temp_result = *temp_a * *temp_b;
}

#endif // !1PARALLEL_BENCHMARK_SERIAL_1_HPP