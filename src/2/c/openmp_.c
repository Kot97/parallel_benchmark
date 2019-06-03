#include "openmp_.h"

unsigned long _c2_openmp_task_rec(long n)
{
    if(n < CUTOFF2) return c2_serial_rec(n);
    unsigned long ret, ret2;
    #pragma omp task shared(ret)
        ret = _c2_openmp_task_rec(n-1);
    #pragma omp task shared(ret2)
        ret2 = _c2_openmp_task_rec(n-2);
    #pragma omp taskwait
    return ret + ret2;
}

unsigned long c2_openmp_task_rec(long n)
{
    if(n < CUTOFF2) return c2_serial_rec(n);
    unsigned long ret;
    #pragma omp parallel
        #pragma omp single
            ret = _c2_openmp_task_rec(n);
    return ret;
}

omp_lock_t dictionary_lock[DCACHE_SIZE];

unsigned long _c2_openmp_task_rec_dict_lock(long n)
{
    if(n < CUTOFF2) return c2_serial_rec_dict(n);
    if(n < DCACHE_SIZE) 
    {
        if (dictionary[n] != 0) return dictionary[n];
        else
        {
            unsigned long i, j;
            #pragma omp task shared(i)
                i = _c2_openmp_task_rec_dict_lock(n-1);
            #pragma omp task shared(j)
                j = _c2_openmp_task_rec_dict_lock(n-2);
            #pragma omp taskwait
            omp_set_lock(dictionary_lock + n);
            dictionary[n] = i + j; 
            omp_unset_lock(dictionary_lock + n);
            return dictionary[n];
        }
    }
    else 
    {
        unsigned long i, j;
        #pragma omp task shared(i)
            i = _c2_openmp_task_rec_dict_lock(n-1);
        #pragma omp task shared(j)
            j = _c2_openmp_task_rec_dict_lock(n-2);
        #pragma omp taskwait
        return i + j;
    }
}

unsigned long c2_openmp_task_rec_dict_lock(long n)
{
    if(n < CUTOFF2) return c2_serial_rec_dict(n);
    unsigned long ret;
    #pragma omp parallel
    {
        #pragma omp for
        for(int i = 0; i < DCACHE_SIZE; ++i)
            omp_init_lock(dictionary_lock + i);
        #pragma omp single
            ret = _c2_openmp_task_rec_dict_lock(n);
        #pragma omp for
        for(int i = 0; i < DCACHE_SIZE; ++i)
            omp_destroy_lock(dictionary_lock + i);
    }
    return ret;
}

unsigned long _c2_openmp_task_rec_dict_critical(long n)
{
    if(n < CUTOFF2) return c2_serial_rec_dict(n);
    if(n < DCACHE_SIZE) 
    {
        if (dictionary[n] != 0) return dictionary[n];
        else
        {
            unsigned long i, j;
            #pragma omp task shared(i)
                i = _c2_openmp_task_rec_dict_lock(n-1);
            #pragma omp task shared(j)
                j = _c2_openmp_task_rec_dict_lock(n-2);
            #pragma omp taskwait
            #pragma omp critical
                dictionary[n] = i + j; 
            return dictionary[n];
        }
    }
    else 
    {
        unsigned long i, j;
        #pragma omp task shared(i)
            i = _c2_openmp_task_rec_dict_lock(n-1);
        #pragma omp task shared(j)
            j = _c2_openmp_task_rec_dict_lock(n-2);
        #pragma omp taskwait
        return i + j;
    }
}

unsigned long c2_openmp_task_rec_dict_critical(long n)
{
    if(n < CUTOFF2) return c2_serial_rec_dict(n);
    unsigned long ret;
    #pragma omp parallel
        #pragma omp single
            ret = _c2_openmp_task_rec_dict_critical(n);
    return ret;
}