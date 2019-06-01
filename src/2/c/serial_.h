#ifndef PARALLEL_BENCHMARK_SERIAL_2_H
#define PARALLEL_BENCHMARK_SERIAL_2_H

#include "dictionary.h"
#include "../../cutoffs.h"

unsigned long c2_serial_rec(long n);
unsigned long c2_serial_rec_dict(long n);
unsigned long c2_serial_iter(long n);

#endif