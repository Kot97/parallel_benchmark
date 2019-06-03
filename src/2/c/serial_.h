#ifndef PARALLEL_BENCHMARK_SERIAL_2_H
#define PARALLEL_BENCHMARK_SERIAL_2_H

#include "../../cutoffs.h"
#include "dictionary.h"

extern unsigned long dictionary[DCACHE_SIZE];

#ifdef __cplusplus
extern "C" {
#endif

unsigned long c2_serial_rec(long n);
unsigned long c2_serial_rec_dict(long n);
unsigned long c2_serial_iter(long n);

#ifdef __cplusplus
}
#endif

#endif