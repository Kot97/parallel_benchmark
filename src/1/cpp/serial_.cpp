#include "serial_.hpp"

void cpp1_serial(double *result, const double *a, const double *b, unsigned long size)
{
    double *temp_result = result;
    const double *temp_a = a, *temp_b = b;
    for(unsigned long i = 0; i < size; ++i, ++temp_result, ++temp_a, ++temp_b)
        *temp_result = *temp_a * *temp_b;
}