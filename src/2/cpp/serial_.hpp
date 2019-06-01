#ifndef PARALLEL_BENCHMARK_SERIAL_2_HPP
#define PARALLEL_BENCHMARK_SERIAL_2_HPP

#include <unordered_map>
#include "../../cutoffs.h"

extern std::unordered_map<long, unsigned long> map;

unsigned long cpp2_serial_rec(long n);
unsigned long cpp2_serial_rec_dict(long n);
unsigned long cpp2_serial_iter(long n);

#endif