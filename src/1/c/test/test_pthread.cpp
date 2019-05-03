#include "../pthread_.h"
#include "../../testing.hpp"

// clang++ -o test_pthread.test test_pthread.cpp -lgtest -lgtest_main -lpthread

TEST(Pthread, NullInput)
{
    res = a = b = NULL;
    c1_pthread(res, a, b, 0);
}

TEST(Pthread, NotSetSize100)
{
    int size = 100;
    setup(size);
    c1_pthread(res, a, b, size);
    teardown();
}

TEST(Pthread, NotSetSize1000)
{
    int size = 1000;
    setup(size);
    c1_pthread(res, a, b, size);
    teardown();
}

TEST(Pthread, NotSetSize10000)
{
    int size = 10000;
    setup(size);
    c1_pthread(res, a, b, size);
    teardown();
}

TEST(Pthread, NotSetSize100000)
{
    int size = 100000;
    setup(size);
    c1_pthread(res, a, b, size);
    teardown();
}


TEST(Pthread, SetSize100)
{
    int size = 100;
    setup(size);
    set(size, 2, 3);
    c1_pthread(res, a, b, size);
    checkset(size, 6);
    teardown();
}

TEST(Pthread, SetSize1000)
{
    int size = 1000;
    setup(size);
    set(size, 2.2, 3.3);
    c1_pthread(res, a, b, size);
    checkset(size, 7.26);
    teardown();
}

TEST(Pthread, SetSize10000)
{
    int size = 10000;
    setup(size);
    set(size, 2.2, 3.3);
    c1_pthread(res, a, b, size);
    checkset(size, 7.26);
    teardown();
}

TEST(Pthread, SetSize101)
{
    int size = 101;
    setup(size);
    set(size, 2, 3);
    c1_pthread(res, a, b, size);
    checkset(size, 6);
    teardown();
}

TEST(Pthread, SetSize102)
{
    int size = 102;
    setup(size);
    set(size, 2, 3);
    c1_pthread(res, a, b, size);
    checkset(size, 6);
    teardown();
}

TEST(Pthread, SetSize1001)
{
    int size = 1001;
    setup(size);
    set(size, 2.2, 3.3);
    c1_pthread(res, a, b, size);
    checkset(size, 7.26);
    teardown();
}

TEST(Pthread, SetSize1002)
{
    int size = 1002;
    setup(size);
    set(size, 2.2, 3.3);
    c1_pthread(res, a, b, size);
    checkset(size, 7.26);
    teardown();
}

TEST(Pthread, SetSize1003)
{
    int size = 1003;
    setup(size);
    set(size, 2.2, 3.3);
    c1_pthread(res, a, b, size);
    checkset(size, 7.26);
    teardown();
}

TEST(Pthread, SetSize10001)
{
    int size = 10001;
    setup(size);
    set(size, 2.2, 3.3);
    c1_pthread(res, a, b, size);
    checkset(size, 7.26);
    teardown();
}

TEST(Pthread, SetSize100003)
{
    int size = 100003;
    setup(size);
    set(size, 2.2, 3.3);
    c1_pthread(res, a, b, size);
    checkset(size, 7.26);
    teardown();
}

TEST(Pthread, GivenVector)
{
    int size = 12;
    double res[] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
    double a[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    double b[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    c1_pthread(res, a, b, size);
    double expected[] = {1,4,9,16,25,36,49,64,81,100,121,144};
    checkvec(size, res, expected);
}

// ----------------------------------------------------------------------