#ifndef PARALLEL_BENCHMARK_FIBONACCI_TEST_HPP
#define PARALLEL_BENCHMARK_FIBONACCI_TEST_HPP

#include <gtest/gtest.h>

class FibonacciTest : public ::testing::TestWithParam<std::pair<long, unsigned long>> { };
INSTANTIATE_TEST_SUITE_P(NegativeAndZero, FibonacciTest, 
::testing::Values( 
   std::make_pair(-100, 1),
   std::make_pair(-10, 1),
   std::make_pair(-4, 1),
   std::make_pair(0, 1)
 ));
 INSTANTIATE_TEST_SUITE_P(Positive, FibonacciTest, 
 ::testing::Values(
    std::make_pair(1, 1),
    std::make_pair(2, 1),
    std::make_pair(5, 5),
    std::make_pair(8, 21),
    std::make_pair(10, 55),
    std::make_pair(15, 610),
    std::make_pair(20, 6765),
    std::make_pair(40, 102334155)
 ));

class Fibonacci2Test : public ::testing::TestWithParam<std::pair<long, unsigned long>> { };
INSTANTIATE_TEST_SUITE_P(BigNumbers, Fibonacci2Test, 
::testing::Values(
    std::make_pair(45, 1134903170),
    std::make_pair(50, 12586269025),
    std::make_pair(60, 1548008755920),
    std::make_pair(70, 190392490709135),
    std::make_pair(80, 23416728348467685)
));

#endif //!PARALLEL_BENCHMARK_FIBONACCI_TEST_HPP