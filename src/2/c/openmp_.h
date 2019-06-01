#ifndef PARALLEL_BENCHMARK_OPENMP_2_H
#define PARALLEL_BENCHMARK_OPENMP_2_H

#include <stdlib.h>
#include <omp.h>
#include "dictionary.h"
#include "serial_.h"

unsigned long _c2_openmp_task_rec(long n);
unsigned long c2_openmp_task_rec(long n);

unsigned long _c2_openmp_task_rec_dict_lock(long n);
unsigned long c2_openmp_task_rec_dict_lock(long n);

unsigned long _c2_openmp_task_rec_dict_critical(long n);
unsigned long c2_openmp_task_rec_dict_critical(long n);

#endif