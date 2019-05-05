#ifndef PARALLEL_BENCHMARK_TEST_C_VECTOR_MULT
#define PARALLEL_BENCHMARK_TEST_C_VECTOR_MULT

#include "../src/1/cpp/std_.hpp"
#include "../src/1/cpp/tbb_.hpp"
#include "test_vector_mult.hpp"

// clang++ -o cpp_vector_mult.test test_cpp_vector_mult.cpp -lgtest -lgtest_main -lpthread -ltbb

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

#endif // !1PARALLEL_BENCHMARK_TEST_C_VECTOR_MULT
