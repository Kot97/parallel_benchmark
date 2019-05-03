#include "../tbb_.hpp"
#include "../../testing.hpp"

// clang++ -o test_tbb.test test_tbb.cpp -lgtest -lgtest_main -lpthread -ltbb

TEST(Tbb, NullInput)
{
    res = a = b = NULL;
    cpp1_tbb(res, a, b, 0);
}

TEST(Tbb, NotSetSize100)
{
    int size = 100;
    setup(size);
    cpp1_tbb(res, a, b, size);
    teardown();
}

TEST(Tbb, NotSetSize1000)
{
    int size = 1000;
    setup(size);
    cpp1_tbb(res, a, b, size);
    teardown();
}

TEST(Tbb, NotSetSize10000)
{
    int size = 10000;
    setup(size);
    cpp1_tbb(res, a, b, size);
    teardown();
}

TEST(Tbb, NotSetSize100000)
{
    int size = 100000;
    setup(size);
    cpp1_tbb(res, a, b, size);
    teardown();
}


TEST(Tbb, SetSize100)
{
    int size = 100;
    setup(size);
    set(size, 2, 3);
    cpp1_tbb(res, a, b, size);
    checkset(size, 6);
    teardown();
}

TEST(Tbb, SetSize1000)
{
    int size = 1000;
    setup(size);
    set(size, 2.2, 3.3);
    cpp1_tbb(res, a, b, size);
    checkset(size, 7.26);
    teardown();
}

TEST(Tbb, SetSize10000)
{
    int size = 10000;
    setup(size);
    set(size, 2.2, 3.3);
    cpp1_tbb(res, a, b, size);
    checkset(size, 7.26);
    teardown();
}

TEST(Tbb, SetSize101)
{
    int size = 101;
    setup(size);
    set(size, 2, 3);
    cpp1_tbb(res, a, b, size);
    checkset(size, 6);
    teardown();
}

TEST(Tbb, SetSize102)
{
    int size = 102;
    setup(size);
    set(size, 2, 3);
    cpp1_tbb(res, a, b, size);
    checkset(size, 6);
    teardown();
}

TEST(Tbb, SetSize1001)
{
    int size = 1001;
    setup(size);
    set(size, 2.2, 3.3);
    cpp1_tbb(res, a, b, size);
    checkset(size, 7.26);
    teardown();
}

TEST(Tbb, SetSize1002)
{
    int size = 1002;
    setup(size);
    set(size, 2.2, 3.3);
    cpp1_tbb(res, a, b, size);
    checkset(size, 7.26);
    teardown();
}

TEST(Tbb, SetSize1003)
{
    int size = 1003;
    setup(size);
    set(size, 2.2, 3.3);
    cpp1_tbb(res, a, b, size);
    checkset(size, 7.26);
    teardown();
}

TEST(Tbb, SetSize10001)
{
    int size = 10001;
    setup(size);
    set(size, 2.2, 3.3);
    cpp1_tbb(res, a, b, size);
    checkset(size, 7.26);
    teardown();
}

TEST(Tbb, SetSize100003)
{
    int size = 100003;
    setup(size);
    set(size, 2.2, 3.3);
    cpp1_tbb(res, a, b, size);
    checkset(size, 7.26);
    teardown();
}

TEST(Tbb, GivenVector)
{
    int size = 12;
    double res[] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
    double a[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    double b[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    cpp1_tbb(res, a, b, size);
    double expected[] = {1,4,9,16,25,36,49,64,81,100,121,144};
    checkvec(size, res, expected);
}

// ----------------------------------------------------------------------