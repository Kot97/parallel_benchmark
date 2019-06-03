#ifndef PARALLEL_BENCHMARK_SERIAL_1_H
#define PARALLEL_BENCHMARK_SERIAL_1_H

#include "../../cutoffs.h"

#ifdef __cplusplus
extern "C" {
#endif
void c1_serial(double *result, const double *a, const double *b, unsigned long size);
#ifdef __cplusplus
}
#endif

#endif