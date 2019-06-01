#ifndef PARALLEL_BENCHMARK_PTHREAD_1_H
#define PARALLEL_BENCHMARK_PTHREAD_1_H

#include <pthread.h>
#include <stddef.h>
#include <stdlib.h>
#include "../serial_.h"

typedef struct
{
    double *result;
    const double *a, *b;
    int id;
    unsigned long size;
} arg;

#define num_threads 4

void* _c1_pthread(void* f_arg);
void c1_pthread(double *result, const double *a, const double *b, unsigned long size);

#endif