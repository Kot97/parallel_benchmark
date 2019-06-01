#ifndef PARALLEL_BENCHMARK_TEST_CPP_VECTOR_MULT
#define PARALLEL_BENCHMARK_TEST_CPP_VECTOR_MULT

#include <1/cpp/tbb_.hpp>
#include <1/cpp/std_.hpp>
// #include "../src/1/cpp/std_.hpp"
// #include "../src/1/cpp/tbb_.hpp"
#include "test_vector_mult.hpp"

TEST_NULL_INPUT(Std, cpp1_thread)
TEST_NULL_INPUT(Tbb, cpp1_tbb)

TEST_VECTOR_MULT(Std, cpp1_thread)
TEST_VECTOR_MULT(Tbb, cpp1_tbb)

#endif