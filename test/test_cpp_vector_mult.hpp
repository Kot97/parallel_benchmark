#ifndef PARALLEL_BENCHMARK_TEST_CPP_VECTOR_MULT
#define PARALLEL_BENCHMARK_TEST_CPP_VECTOR_MULT

#include "../src/1/cpp/std_.hpp"
#include "../src/1/cpp/tbb_.hpp"
#include "test_vector_mult.hpp"

TEST(NullInput, Std)
{
    cpp1_thread(NULL, NULL, NULL, 0);
    cpp1_thread(nullptr, nullptr, nullptr, 0);
}
TEST(NullInput, Tbb)
{
    cpp1_tbb(NULL, NULL, NULL, 0);
    cpp1_tbb(nullptr, nullptr, nullptr, 0);
}

TEST_P(VectorMultNotSetTest, Std)
{
    cpp1_thread(res, a, b, size);
}
TEST_P(VectorMultNotSetTest, Tbb)
{
    cpp1_tbb(res, a, b, size);
}

TEST_P(VectorMultSetTest, Std)
{
    cpp1_thread(res, a, b, size);
}
TEST_P(VectorMultSetTest, Tbb)
{
    cpp1_tbb(res, a, b, size);
}

TEST_P(VectorMultTest, Std)
{
    cpp1_thread(res, a, b, size);
}
TEST_P(VectorMultTest, Tbb)
{
    cpp1_tbb(res, a, b, size);
}

#endif // !1PARALLEL_BENCHMARK_TEST_CPP_VECTOR_MULT
