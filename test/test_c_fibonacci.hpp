#ifndef PARALLEL_BENCHMARK_TEST_C_FIBONACCI
#define PARALLEL_BENCHMARK_TEST_C_FIBONACCI

#include "../src/2/c/serial_.h"
#include "../src/2/c/openmp_.h"
#include "test_fibonacci.hpp"

TEST_P(FibonacciTest, SerialRec)
{
    EXPECT_EQ(c2_serial_rec(GetParam().first), GetParam().second);
}

TEST_P(FibonacciTest, SerialRecDict)
{
    EXPECT_EQ(c2_serial_rec_dict(GetParam().first), GetParam().second);
}
TEST_P(Fibonacci2Test, SerialRecDict)
{
    EXPECT_EQ(c2_serial_rec_dict(GetParam().first), GetParam().second);
}

TEST_P(FibonacciTest, SerialIter)
{
    EXPECT_EQ(c2_serial_iter(GetParam().first), GetParam().second);
}
TEST_P(Fibonacci2Test, SerialIter)
{
    EXPECT_EQ(c2_serial_iter(GetParam().first), GetParam().second);
}

TEST_P(FibonacciTest, OpenmpTaskRec)
{
    EXPECT_EQ(c2_openmp_task_rec(GetParam().first), GetParam().second);
}

TEST_P(FibonacciTest, OpenmpTaskRecDictLock)
{
    EXPECT_EQ(c2_openmp_task_rec_dict_lock(GetParam().first), GetParam().second);
}
TEST_P(Fibonacci2Test, OpenmpTaskRecDictLock)
{
    EXPECT_EQ(c2_openmp_task_rec_dict_lock(GetParam().first), GetParam().second);
}

TEST_P(FibonacciTest, OpenmpTaskRecDictCritical)
{
    EXPECT_EQ(c2_openmp_task_rec_dict_critical(GetParam().first), GetParam().second);
}
TEST_P(Fibonacci2Test, OpenmpTaskRecDictCritical)
{
    EXPECT_EQ(c2_openmp_task_rec_dict_critical(GetParam().first), GetParam().second);
}

#endif // !1PARALLEL_BENCHMARK_TEST_C_FIBONACCI