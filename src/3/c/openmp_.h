#ifndef PARALLEL_BENCHMARK_OPENMP_3_H
#define PARALLEL_BENCHMARK_OPENMP_3_H

#include "serial_.h"

#ifdef __cplusplus
extern "C" {
#endif

double c3_openmp_parallel_for(const double *a, const double *b);
double _c3_openmp_task(const double *a, const double *b);
double c3_openmp_task(const double *a, const double *b);

#ifdef __cplusplus
}
#endif

#endif