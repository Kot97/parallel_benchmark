#include "../src/2/c/serial_.h"
#include "test_fibonacci.hpp"

// clang++ -o c_fibonacci.test test_c_fibonacci.cpp -lgtest -lgtest_main -lpthread

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