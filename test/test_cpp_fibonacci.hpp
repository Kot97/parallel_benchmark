#ifndef PARALLEL_BENCHMARK_TEST_CPP_FIBONACCI
#define PARALLEL_BENCHMARK_TEST_CPP_FIBONACCI

#include "../src/2/cpp/serial_.hpp"
#include "../src/2/cpp/std_.hpp"
#include "../src/2/cpp/tbb_.hpp"
#include "test_fibonacci.hpp"

TEST_P(FibonacciTest, CppSerialRec)
{
    EXPECT_EQ(cpp2_serial_rec(GetParam().first), GetParam().second);
}

TEST_P(FibonacciTest, CppSerialRecDict)
{
    EXPECT_EQ(cpp2_serial_rec_dict(GetParam().first), GetParam().second);
}
TEST_P(Fibonacci2Test, CppSerialRecDict)
{
    EXPECT_EQ(cpp2_serial_rec_dict(GetParam().first), GetParam().second);
}

TEST_P(FibonacciTest, CppSerialIter)
{
    EXPECT_EQ(cpp2_serial_iter(GetParam().first), GetParam().second);
}
TEST_P(Fibonacci2Test, CppSerialIter)
{
    EXPECT_EQ(cpp2_serial_iter(GetParam().first), GetParam().second);
}

TEST_P(FibonacciTest, CppTask)
{
    EXPECT_EQ(cpp2_task(GetParam().first), GetParam().second);
}

TEST_P(FibonacciTest, CppAsync)
{
    EXPECT_EQ(cpp2_async(GetParam().first), GetParam().second);
}

TEST_P(FibonacciTest, CppTaskDict)
{
    EXPECT_EQ(cpp2_task_dict(GetParam().first), GetParam().second);
}

TEST_P(FibonacciTest, CppAsyncDict)
{
    EXPECT_EQ(cpp2_async_dict(GetParam().first), GetParam().second);
}

TEST_P(FibonacciTest, Tbb)
{
    EXPECT_EQ(cpp2_tbb(GetParam().first), GetParam().second);
}

TEST_P(FibonacciTest, TbbDict)
{
    EXPECT_EQ(cpp2_tbb_dict(GetParam().first), GetParam().second);
}
TEST_P(Fibonacci2Test, TbbDict)
{
    EXPECT_EQ(cpp2_tbb_dict(GetParam().first), GetParam().second);
}

#endif // !1PARALLEL_BENCHMARK_TEST_CPP_FIBONACCI