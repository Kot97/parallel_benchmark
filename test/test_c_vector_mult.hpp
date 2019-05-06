#ifndef PARALLEL_BENCHMARK_TEST_C_VECTOR_MULT
#define PARALLEL_BENCHMARK_TEST_C_VECTOR_MULT

#include "../src/1/c/openmp_.h"
#include "../src/1/c/pthread_.h"
#include "test_vector_mult.hpp"

TEST(NullInput, Pthread)
{
    c1_pthread(NULL, NULL, NULL, 0);
    c1_pthread(nullptr, nullptr, nullptr, 0);
}
TEST(NullInput, OpenmpParallel)
{
    c1_openmp_parallel(NULL, NULL, NULL, 0);
    c1_openmp_parallel(nullptr, nullptr, nullptr, 0);
}
TEST(NullInput, OpenmpParallelFor)
{
    c1_openmp_parallel_for(NULL, NULL, NULL, 0);
    c1_openmp_parallel_for(nullptr, nullptr, nullptr, 0);
}
TEST(NullInput, OpenmpParallelForSimd)
{
    c1_openmp_parallel_for_simd(NULL, NULL, NULL, 0);
    c1_openmp_parallel_for_simd(nullptr, nullptr, nullptr, 0);
}

TEST_P(VectorMultNotSetTest, Pthread)
{
    c1_pthread(res, a, b, size);
}
TEST_P(VectorMultSetTest, Pthread)
{
    c1_pthread(res, a, b, size);
}
TEST_P(VectorMultTest, Pthread)
{
    c1_pthread(res, a, b, size);
}

TEST_P(VectorMultNotSetTest, OpenmpParallel)
{
    c1_openmp_parallel(res, a, b, size);
}
TEST_P(VectorMultSetTest, OpenmpParallel)
{
    c1_openmp_parallel(res, a, b, size);
}
TEST_P(VectorMultTest, OpenmpParallel)
{
    c1_openmp_parallel(res, a, b, size);
}

TEST_P(VectorMultNotSetTest, OpenmpParallelFor)
{
    c1_openmp_parallel_for(res, a, b, size);
}
TEST_P(VectorMultSetTest, OpenmpParallelFor)
{
    c1_openmp_parallel_for(res, a, b, size);
}
TEST_P(VectorMultTest, OpenmpParallelFor)
{
    c1_openmp_parallel_for(res, a, b, size);
}

TEST_P(VectorMultNotSetTest, OpenmpParallelForSimd)
{
    c1_openmp_parallel_for_simd(res, a, b, size);
}
TEST_P(VectorMultSetTest, OpenmpParallelForSimd)
{
    c1_openmp_parallel_for_simd(res, a, b, size);
}
TEST_P(VectorMultTest, OpenmpParallelForSimd)
{
    c1_openmp_parallel_for_simd(res, a, b, size);
}

#endif // !1PARALLEL_BENCHMARK_TEST_C_VECTOR_MULT