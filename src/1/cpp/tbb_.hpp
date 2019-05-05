#ifndef PARALLEL_BENCHMARK_TBB_1_HPP
#define PARALLEL_BENCHMARK_TBB_1_HPP

#include <tbb/parallel_for.h>

void cpp1_tbb(double *result, const double *a, const double *b, unsigned long size)
{
    tbb::parallel_for(0ul, size, [&](const unsigned long& i)
    {   
        result[i] = a[i] * b[i]; 
    });
}

#endif // !1PARALLEL_BENCHMARK_TBB_1_HPP