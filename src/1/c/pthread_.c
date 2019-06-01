#include "pthread_.h"

void* _c1_pthread(void* f_arg)
{
    arg x = *(arg*)f_arg;
    unsigned long end = x.size / num_threads;
    for(unsigned long i = 0; i < end; ++i, x.result+=num_threads, x.a+=num_threads, x.b+=num_threads)
        *x.result = *x.a * *x.b;
    
    if(x.id == num_threads-1 && x.size % num_threads != 0)
    {
        x.result -= (num_threads-1); 
        x.a -= (num_threads-1); 
        x.b -= (num_threads-1); 
        for(unsigned long i = x.size - x.size%num_threads; i < x.size; ++i, ++x.result, ++x.a, ++x.b)
            *x.result = *x.a * *x.b;
    }

    return NULL;
} 

void c1_pthread(double *result, const double *a, const double *b, unsigned long size)
{
    if(size < CUTOFF1) { c1_serial(result, a, b, size); return; }

    pthread_t* threads = (pthread_t*)malloc(sizeof(pthread_t)*num_threads);
    arg* args = (arg*)malloc(sizeof(arg)*num_threads);

    for(int i = 0; i < num_threads; ++i)
    {
        args[i].id = i;
        args[i].a = a + i;
        args[i].b = b + i;
        args[i].result = result + i;
        args[i].size = size;

        pthread_create(&threads[i], NULL, _c1_pthread, &args[i]);
    }

    for(int i = 0; i < num_threads; ++i)
        pthread_join(threads[i], NULL);
    
    free(threads); free(args);
}