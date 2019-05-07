#ifndef PARALLEL_BENCHMARK_TEST_CPP_FIBONACCI
#define PARALLEL_BENCHMARK_TEST_CPP_FIBONACCI

#include "../src/2/cpp/serial_.hpp"
#include "../src/2/cpp/std_.hpp"
#include "../src/2/cpp/tbb_.hpp"
#include "test_fibonacci.hpp"

TEST_FIBONACCI(CppSerialRec, cpp2_serial_rec)
TEST_FIBONACCI2(CppSerialRecDict, cpp2_serial_rec_dict)
TEST_FIBONACCI2(CppSerialIter, cpp2_serial_iter)

TEST_FIBONACCI(CppTask, cpp2_task)
TEST_FIBONACCI(CppAsync, cpp2_async)

TEST_FIBONACCI(CppTaskDict, cpp2_task_dict)
TEST_FIBONACCI(CppAsyncDict, cpp2_async_dict)

TEST_FIBONACCI(Tbb, cpp2_tbb)
TEST_FIBONACCI2(TbbDict, cpp2_tbb_dict)

#endif // !1PARALLEL_BENCHMARK_TEST_CPP_FIBONACCI