#ifndef PARALLEL_BENCHMARK_TEST_C_FIBONACCI
#define PARALLEL_BENCHMARK_TEST_C_FIBONACCI

// #include "../src/2/c/serial_.h"
// #include "../src/2/c/openmp_.h"
#include <2/c/serial_.h>
#include <2/c/openmp_.h>
#include "test_fibonacci.hpp"

TEST_FIBONACCI(SerialRec, c2_serial_rec)
TEST_FIBONACCI2(SerialRecDict, c2_serial_rec_dict)
TEST_FIBONACCI2(SerialIter, c2_serial_iter)

TEST_FIBONACCI(OpenmpTaskRec, c2_openmp_task_rec)
TEST_FIBONACCI2(OpenmpTaskRecDictLock, c2_openmp_task_rec_dict_lock)
TEST_FIBONACCI2(OpenmpTaskRecDictCritical, c2_openmp_task_rec_dict_critical)

#endif