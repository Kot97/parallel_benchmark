#ifndef PARALLEL_BENCHMARK_TEST_C_SEARCH
#define PARALLEL_BENCHMARK_TEST_C_SEARCH

// #include "../src/3/c/serial_.h"
// #include "../src/3/c/openmp_.h"
#include <3/c/serial_.h>
#include <3/c/openmp_.h>
#include "test_search.hpp"

TEST_SEARCH(Serial, c3_serial)
TEST_SEARCH(OpenmpFor, c3_openmp_parallel_for)
TEST_SEARCH(OpenmpTask, c3_openmp_task)

#endif