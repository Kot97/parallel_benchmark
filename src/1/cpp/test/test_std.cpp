#include "../std_.hpp"
#include "../../testing.hpp"

// clang++ -o test_std.test test_std.cpp -lgtest -lgtest_main -lpthread

TEST(Std, NullInput)
{
    res = a = b = NULL;
    cpp1_thread(res, a, b, 0);
}

TEST(Std, NotSetSize100)
{
    int size = 100;
    setup(size);
    cpp1_thread(res, a, b, size);
    teardown();
}

TEST(Std, NotSetSize1000)
{
    int size = 1000;
    setup(size);
    cpp1_thread(res, a, b, size);
    teardown();
}

TEST(Std, NotSetSize10000)
{
    int size = 10000;
    setup(size);
    cpp1_thread(res, a, b, size);
    teardown();
}

TEST(Std, NotSetSize100000)
{
    int size = 100000;
    setup(size);
    cpp1_thread(res, a, b, size);
    teardown();
}


TEST(Std, SetSize100)
{
    int size = 100;
    setup(size);
    set(size, 2, 3);
    cpp1_thread(res, a, b, size);
    checkset(size, 6);
    teardown();
}

TEST(Std, SetSize1000)
{
    int size = 1000;
    setup(size);
    set(size, 2.2, 3.3);
    cpp1_thread(res, a, b, size);
    checkset(size, 7.26);
    teardown();
}

TEST(Std, SetSize10000)
{
    int size = 10000;
    setup(size);
    set(size, 2.2, 3.3);
    cpp1_thread(res, a, b, size);
    checkset(size, 7.26);
    teardown();
}

TEST(Std, SetSize101)
{
    int size = 101;
    setup(size);
    set(size, 2, 3);
    cpp1_thread(res, a, b, size);
    checkset(size, 6);
    teardown();
}

TEST(Std, SetSize102)
{
    int size = 102;
    setup(size);
    set(size, 2, 3);
    cpp1_thread(res, a, b, size);
    checkset(size, 6);
    teardown();
}

TEST(Std, SetSize1001)
{
    int size = 1001;
    setup(size);
    set(size, 2.2, 3.3);
    cpp1_thread(res, a, b, size);
    checkset(size, 7.26);
    teardown();
}

TEST(Std, SetSize1002)
{
    int size = 1002;
    setup(size);
    set(size, 2.2, 3.3);
    cpp1_thread(res, a, b, size);
    checkset(size, 7.26);
    teardown();
}

TEST(Std, SetSize1003)
{
    int size = 1003;
    setup(size);
    set(size, 2.2, 3.3);
    cpp1_thread(res, a, b, size);
    checkset(size, 7.26);
    teardown();
}

TEST(Std, SetSize10001)
{
    int size = 10001;
    setup(size);
    set(size, 2.2, 3.3);
    cpp1_thread(res, a, b, size);
    checkset(size, 7.26);
    teardown();
}

TEST(Std, SetSize100003)
{
    int size = 100003;
    setup(size);
    set(size, 2.2, 3.3);
    cpp1_thread(res, a, b, size);
    checkset(size, 7.26);
    teardown();
}

TEST(Std, GivenVector)
{
    int size = 12;
    double res[] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
    double a[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    double b[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    cpp1_thread(res, a, b, size);
    double expected[] = {1,4,9,16,25,36,49,64,81,100,121,144};
    checkvec(size, res, expected);
}

// ----------------------------------------------------------------------