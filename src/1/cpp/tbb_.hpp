#ifndef PARALLEL_BENCHMARK_TBB_1_HPP
#define PARALLEL_BENCHMARK_TBB_1_HPP

#include <tbb/parallel_for.h>
#include "../serial_.h"

void cpp1_tbb(double *result, const double *a, const double *b, unsigned long size);

#endif