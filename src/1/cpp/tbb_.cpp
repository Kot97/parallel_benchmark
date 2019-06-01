#include "tbb_.hpp"

void cpp1_tbb(double *result, const double *a, const double *b, unsigned long size)
{
    if(size < CUTOFF1) { cpp1_serial(result, a, b, size); return; }
    tbb::parallel_for(0ul, size, [&](const unsigned long& i)
    {   
        result[i] = a[i] * b[i]; 
    });
}