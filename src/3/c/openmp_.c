#include "openmp_.h"

double c3_openmp_parallel_for(const double *a, const double *b)
{
    unsigned long size = b - a;
    if(size < CUTOFF3) return c3_serial(a, b);
    double max = *a;
    #pragma omp parallel for reduction(max:max)
    for(unsigned long i = 1; i < size; ++i) if(a[i] > max) max = a[i];
    return max;
}

double _c3_openmp_task(const double *a, const double *b)
{
    unsigned int size = b - a;
    if(size < CUTOFF3) return c3_serial(a, b);
    double max1, max2;
    #pragma omp task shared(max1)
        max1 = _c3_openmp_task(a, b - size/2);
    #pragma omp task shared(max2)
        max2 = _c3_openmp_task(b - size/2, b);
    #pragma omp taskwait
    return max1 > max2 ? max1 : max2;
}

double c3_openmp_task(const double *a, const double *b)
{
    if(b - a < CUTOFF3) return c3_serial(a, b);
    double ret;
    #pragma omp parallel
    #pragma omp single nowait
        ret = _c3_openmp_task(a, b);
    return ret;
}