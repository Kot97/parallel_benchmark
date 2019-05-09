#ifndef PARALLEL_BENCHMARK_OPENMP_1_H
#define PARALLEL_BENCHMARK_OPENMP_1_H

#include <omp.h>
#include <stddef.h>
#include <stdio.h>
#include "serial_.h"

void c1_openmp_parallel(double *result, const double *a, const double *b, unsigned long size)
{
    if(size < CUTOFF1) { c1_serial(result, a, b, size); return; }
    
    double *help_temp_result = NULL;
    const double *help_temp_a = NULL, *help_temp_b = NULL;
    int _count;
#pragma omp parallel
    {
        int id = omp_get_thread_num();
        int count = omp_get_num_threads();
        double *temp_result = result + id;
        const double *temp_a = a + id, *temp_b = b + id;
        for(unsigned long i = 0; i < size/count; ++i, temp_result+=count, temp_a+=count, temp_b+=count)
            *temp_result = *temp_a * *temp_b;
        
        if(id == count-1) 
            if(size%count != 0)
            {
                help_temp_result = temp_result - count + 1;
                help_temp_a = temp_a - count + 1;
                help_temp_b = temp_b - count + 1;
                _count = count;
            }
    }
    if(help_temp_result == NULL) return;

    for(unsigned long i = size - size%_count; i < size; ++i, ++help_temp_result, ++help_temp_a, ++help_temp_b)
        *help_temp_result = *help_temp_a * *help_temp_b;
}

void c1_openmp_parallel_for(double *result, const double *a, const double *b, unsigned long size)
{
    if(size < CUTOFF1) { c1_serial(result, a, b, size); return; }

    #pragma omp parallel for 
    for (unsigned long i = 0; i < size; ++i)
       result[i] = a[i] * b[i];
}

void c1_openmp_parallel_for_simd(double *result, const double *a, const double *b, unsigned long size)
{
    if(size < CUTOFF1) { c1_serial(result, a, b, size); return; }

    #pragma omp parallel for simd 
    for (unsigned long i = 0; i < size; ++i)
       result[i] = a[i] * b[i];
}

#endif // !1PARALLEL_BENCHMARK_OPENMP_1_H