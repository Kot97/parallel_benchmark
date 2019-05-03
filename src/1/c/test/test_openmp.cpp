#include "../openmp_.h"
#include "../../testing.hpp"

// clang++ -o test_openmp.test test_openmp.cpp -lgtest -lgtest_main -fopenmp

TEST(OpenmpParallel, NullInput)
{
    res = a = b = NULL;
    c1_openmp_parallel(res, a, b, 0);
}

TEST(OpenmpParallel, NotSetSize100)
{
    int size = 100;
    setup(size);
    c1_openmp_parallel(res, a, b, size);
    teardown();
}

TEST(OpenmpParallel, NotSetSize1000)
{
    int size = 1000;
    setup(size);
    c1_openmp_parallel(res, a, b, size);
    teardown();
}

TEST(OpenmpParallel, NotSetSize10000)
{
    int size = 10000;
    setup(size);
    c1_openmp_parallel(res, a, b, size);
    teardown();
}

TEST(OpenmpParallel, NotSetSize100000)
{
    int size = 100000;
    setup(size);
    c1_openmp_parallel(res, a, b, size);
    teardown();
}


TEST(OpenmpParallel, SetSize100)
{
    int size = 100;
    setup(size);
    set(size, 2, 3);
    c1_openmp_parallel(res, a, b, size);
    checkset(size, 6);
    teardown();
}

TEST(OpenmpParallel, SetSize1000)
{
    int size = 1000;
    setup(size);
    set(size, 2.2, 3.3);
    c1_openmp_parallel(res, a, b, size);
    checkset(size, 7.26);
    teardown();
}

TEST(OpenmpParallel, SetSize10000)
{
    int size = 10000;
    setup(size);
    set(size, 2.2, 3.3);
    c1_openmp_parallel(res, a, b, size);
    checkset(size, 7.26);
    teardown();
}

TEST(OpenmpParallel, SetSize101)
{
    int size = 101;
    setup(size);
    set(size, 2, 3);
    c1_openmp_parallel(res, a, b, size);
    checkset(size, 6);
    teardown();
}

TEST(OpenmpParallel, SetSize102)
{
    int size = 102;
    setup(size);
    set(size, 2, 3);
    c1_openmp_parallel(res, a, b, size);
    checkset(size, 6);
    teardown();
}

TEST(OpenmpParallel, SetSize1001)
{
    int size = 1001;
    setup(size);
    set(size, 2.2, 3.3);
    c1_openmp_parallel(res, a, b, size);
    checkset(size, 7.26);
    teardown();
}

TEST(OpenmpParallel, SetSize1002)
{
    int size = 1002;
    setup(size);
    set(size, 2.2, 3.3);
    c1_openmp_parallel(res, a, b, size);
    checkset(size, 7.26);
    teardown();
}

TEST(OpenmpParallel, SetSize1003)
{
    int size = 1003;
    setup(size);
    set(size, 2.2, 3.3);
    c1_openmp_parallel(res, a, b, size);
    checkset(size, 7.26);
    teardown();
}

TEST(OpenmpParallel, SetSize10001)
{
    int size = 10001;
    setup(size);
    set(size, 2.2, 3.3);
    c1_openmp_parallel(res, a, b, size);
    checkset(size, 7.26);
    teardown();
}

TEST(OpenmpParallel, SetSize100003)
{
    int size = 100003;
    setup(size);
    set(size, 2.2, 3.3);
    c1_openmp_parallel(res, a, b, size);
    checkset(size, 7.26);
    teardown();
}

TEST(OpenmpParallel, GivenVector)
{
    int size = 12;
    double res[] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
    double a[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    double b[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    c1_openmp_parallel(res, a, b, size);
    double expected[] = {1,4,9,16,25,36,49,64,81,100,121,144};
    checkvec(size, res, expected);
}

// ----------------------------------------------------------------------

TEST(OpenmpParallelFor, NullInput)
{
    res = a = b = NULL;
    c1_openmp_parallel_for(res, a, b, 0);
}

TEST(OpenmpParallelFor, NotSetSize100)
{
    int size = 100;
    setup(size);
    c1_openmp_parallel_for(res, a, b, size);
    teardown();
}

TEST(OpenmpParallelFor, NotSetSize1000)
{
    int size = 1000;
    setup(size);
    c1_openmp_parallel_for(res, a, b, size);
    teardown();
}

TEST(OpenmpParallelFor, NotSetSize10000)
{
    int size = 10000;
    setup(size);
    c1_openmp_parallel_for(res, a, b, size);
    teardown();
}

TEST(OpenmpParallelFor, NotSetSize100000)
{
    int size = 100000;
    setup(size);
    c1_openmp_parallel_for(res, a, b, size);
    teardown();
}


TEST(OpenmpParallelFor, SetSize100)
{
    int size = 100;
    setup(size);
    set(size, 2, 3);
    c1_openmp_parallel_for(res, a, b, size);
    checkset(size, 6);
    teardown();
}

TEST(OpenmpParallelFor, SetSize1000)
{
    int size = 1000;
    setup(size);
    set(size, 2.2, 3.3);
    c1_openmp_parallel_for(res, a, b, size);
    checkset(size, 7.26);
    teardown();
}

TEST(OpenmpParallelFor, SetSize10000)
{
    int size = 10000;
    setup(size);
    set(size, 2.2, 3.3);
    c1_openmp_parallel_for(res, a, b, size);
    checkset(size, 7.26);
    teardown();
}

TEST(OpenmpParallelFor, SetSize101)
{
    int size = 101;
    setup(size);
    set(size, 2, 3);
    c1_openmp_parallel_for(res, a, b, size);
    checkset(size, 6);
    teardown();
}

TEST(OpenmpParallelFor, SetSize102)
{
    int size = 102;
    setup(size);
    set(size, 2, 3);
    c1_openmp_parallel_for(res, a, b, size);
    checkset(size, 6);
    teardown();
}

TEST(OpenmpParallelFor, SetSize1001)
{
    int size = 1001;
    setup(size);
    set(size, 2.2, 3.3);
    c1_openmp_parallel_for(res, a, b, size);
    checkset(size, 7.26);
    teardown();
}

TEST(OpenmpParallelFor, SetSize1002)
{
    int size = 1002;
    setup(size);
    set(size, 2.2, 3.3);
    c1_openmp_parallel_for(res, a, b, size);
    checkset(size, 7.26);
    teardown();
}

TEST(OpenmpParallelFor, SetSize1003)
{
    int size = 1003;
    setup(size);
    set(size, 2.2, 3.3);
    c1_openmp_parallel_for(res, a, b, size);
    checkset(size, 7.26);
    teardown();
}

TEST(OpenmpParallelFor, SetSize10001)
{
    int size = 10001;
    setup(size);
    set(size, 2.2, 3.3);
    c1_openmp_parallel_for(res, a, b, size);
    checkset(size, 7.26);
    teardown();
}

TEST(OpenmpParallelFor, SetSize100003)
{
    int size = 100003;
    setup(size);
    set(size, 2.2, 3.3);
    c1_openmp_parallel_for(res, a, b, size);
    checkset(size, 7.26);
    teardown();
}

TEST(OpenmpParallelFor, GivenVector)
{
    int size = 12;
    double res[] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
    double a[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    double b[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    c1_openmp_parallel_for(res, a, b, size);
    double expected[] = {1,4,9,16,25,36,49,64,81,100,121,144};
    checkvec(size, res, expected);
}

// ----------------------------------------------------------------------

TEST(OpenmpParallelForSimd, NullInput)
{
    res = a = b = NULL;
    c1_openmp_parallel_for_simd(res, a, b, 0);
}

TEST(OpenmpParallelForSimd, NotSetSize100)
{
    int size = 100;
    setup(size);
    c1_openmp_parallel_for_simd(res, a, b, size);
    teardown();
}

TEST(OpenmpParallelForSimd, NotSetSize1000)
{
    int size = 1000;
    setup(size);
    c1_openmp_parallel_for_simd(res, a, b, size);
    teardown();
}

TEST(OpenmpParallelForSimd, NotSetSize10000)
{
    int size = 10000;
    setup(size);
    c1_openmp_parallel_for_simd(res, a, b, size);
    teardown();
}

TEST(OpenmpParallelForSimd, NotSetSize100000)
{
    int size = 100000;
    setup(size);
    c1_openmp_parallel_for_simd(res, a, b, size);
    teardown();
}


TEST(OpenmpParallelForSimd, SetSize100)
{
    int size = 100;
    setup(size);
    set(size, 2, 3);
    c1_openmp_parallel_for_simd(res, a, b, size);
    checkset(size, 6);
    teardown();
}

TEST(OpenmpParallelForSimd, SetSize1000)
{
    int size = 1000;
    setup(size);
    set(size, 2.2, 3.3);
    c1_openmp_parallel_for_simd(res, a, b, size);
    checkset(size, 7.26);
    teardown();
}

TEST(OpenmpParallelForSimd, SetSize10000)
{
    int size = 10000;
    setup(size);
    set(size, 2.2, 3.3);
    c1_openmp_parallel_for_simd(res, a, b, size);
    checkset(size, 7.26);
    teardown();
}

TEST(OpenmpParallelForSimd, SetSize101)
{
    int size = 101;
    setup(size);
    set(size, 2, 3);
    c1_openmp_parallel_for_simd(res, a, b, size);
    checkset(size, 6);
    teardown();
}

TEST(OpenmpParallelForSimd, SetSize102)
{
    int size = 102;
    setup(size);
    set(size, 2, 3);
    c1_openmp_parallel_for_simd(res, a, b, size);
    checkset(size, 6);
    teardown();
}

TEST(OpenmpParallelForSimd, SetSize1001)
{
    int size = 1001;
    setup(size);
    set(size, 2.2, 3.3);
    c1_openmp_parallel_for_simd(res, a, b, size);
    checkset(size, 7.26);
    teardown();
}

TEST(OpenmpParallelForSimd, SetSize1002)
{
    int size = 1002;
    setup(size);
    set(size, 2.2, 3.3);
    c1_openmp_parallel_for_simd(res, a, b, size);
    checkset(size, 7.26);
    teardown();
}

TEST(OpenmpParallelForSimd, SetSize1003)
{
    int size = 1003;
    setup(size);
    set(size, 2.2, 3.3);
    c1_openmp_parallel_for_simd(res, a, b, size);
    checkset(size, 7.26);
    teardown();
}

TEST(OpenmpParallelForSimd, SetSize10001)
{
    int size = 10001;
    setup(size);
    set(size, 2.2, 3.3);
    c1_openmp_parallel_for_simd(res, a, b, size);
    checkset(size, 7.26);
    teardown();
}

TEST(OpenmpParallelForSimd, SetSize100003)
{
    int size = 100003;
    setup(size);
    set(size, 2.2, 3.3);
    c1_openmp_parallel_for_simd(res, a, b, size);
    checkset(size, 7.26);
    teardown();
}

TEST(OpenmpParallelForSimd, GivenVector)
{
    int size = 12;
    double res[] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
    double a[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    double b[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    c1_openmp_parallel_for_simd(res, a, b, size);
    double expected[] = {1,4,9,16,25,36,49,64,81,100,121,144};
    checkvec(size, res, expected);
}

// ----------------------------------------------------------------------