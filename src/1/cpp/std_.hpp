#ifndef PARALLEL_BENCHMARK_STD_1_HPP
#define PARALLEL_BENCHMARK_STD_1_HPP

#include <thread>
#include <vector>
#include "serial_.hpp"

void _cpp1_thread(int id, double *result, const double *a, const double *b, unsigned long size);
void cpp1_thread(double *result, const double *a, const double *b, unsigned long size);

#endif