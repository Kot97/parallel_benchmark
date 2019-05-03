#ifndef PARALLEL_BENCHMARK_TESTING_1_HPP
#define PARALLEL_BENCHMARK_TESTING_1_HPP
#include <stdlib.h>
#include <gtest/gtest.h>

double *res, *a, *b;

void setup(int size)
{
    res = (double*)malloc(sizeof(double) * size);
    a = (double*)malloc(sizeof(double) * size);
    b = (double*)malloc(sizeof(double) * size);
}

void teardown()
{
    free(res); free(a); free(b);
}

void set(int size, double _a, double _b)
{
    double *a_help = a, *b_help = b;
    for(unsigned long i = 0; i < size; ++i, ++a_help, ++b_help)
    {
        *a_help = _a;
        *b_help = _b;
    }
}

void checkset(int size, double _res)
{
    double *res_help = res;
    for(unsigned long i = 0; i < size; ++i, ++res_help)
        EXPECT_DOUBLE_EQ(*res_help, _res);
}

void checkvec(int size, double *res, double *_res)
{
    double *res_help = res, *_res_help = _res;
    for(unsigned long i = 0; i < size; ++i, ++res_help, ++_res_help)
        EXPECT_DOUBLE_EQ(*res_help, *_res_help);
}

#endif // !1PARALLEL_BENCHMARK_TESTING_1_HPP