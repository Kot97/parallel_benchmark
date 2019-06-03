#ifndef PARALLEL_BENCHMARK_OPENMP_1_H
#define PARALLEL_BENCHMARK_OPENMP_1_H

#include <omp.h>
#include <stddef.h>
#include <stdio.h>
#include "serial_.h"

#ifdef __cplusplus
extern "C" {
#endif

void c1_openmp_parallel(double *result, const double *a, const double *b, unsigned long size);
void c1_openmp_parallel_for(double *result, const double *a, const double *b, unsigned long size);
void c1_openmp_parallel_for_simd(double *result, const double *a, const double *b, unsigned long size);

#ifdef __cplusplus
}
#endif

#endif 