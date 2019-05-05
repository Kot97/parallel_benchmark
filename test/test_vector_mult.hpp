#ifndef PARALLEL_BENCHMARK_VECTOR_MULT_TEST_HPP
#define PARALLEL_BENCHMARK_VECTOR_MULT_TEST_HPP
#include <gtest/gtest.h>
#include <stdlib.h>
#include <tuple>
#include <vector>

class VectorMultNotSetTest : public ::testing::TestWithParam<unsigned long>
{
public:
    double *res, *a, *b;
    unsigned long size = GetParam();

    void SetUp() override
    {
        res = (double*)malloc(sizeof(double) * size);
        a = (double*)malloc(sizeof(double) * size);
        b = (double*)malloc(sizeof(double) * size);
    }

    void TearDown() override
    {
        free(res); free(a); free(b);
    }
};
INSTANTIATE_TEST_SUITE_P(SmallSize, VectorMultNotSetTest, ::testing::Range(2ul, 100ul));
INSTANTIATE_TEST_SUITE_P(MediumSize, VectorMultNotSetTest, 
::testing::Values(
    1000, 1001, 1003, 4578, 11203, 76711
));
INSTANTIATE_TEST_SUITE_P(LargeSize, VectorMultNotSetTest, 
::testing::Values(
    100000, 100002, 100005, 200123, 340028, 1000000, 1000008
));

class VectorMultSetTest : public ::testing::TestWithParam<std::tuple<unsigned long, double, double, double>>
{
public:
    double *res, *a, *b;
    unsigned long size = std::get<0>(GetParam());

    void SetUp() override
    {
        res = (double*)malloc(sizeof(double) * size);
        a = (double*)malloc(sizeof(double) * size);
        b = (double*)malloc(sizeof(double) * size);

        double _a = std::get<1>(GetParam());
        double _b = std::get<2>(GetParam());
        double *a_help = a, *b_help = b;
        for(unsigned long i = 0; i < size; ++i, ++a_help, ++b_help)
        {
            *a_help = _a;
            *b_help = _b;
        }
    }

    void TearDown() override
    {
        double _res = std::get<3>(GetParam());
        double *res_help = res;
        for(unsigned long i = 0; i < size; ++i, ++res_help)
            EXPECT_DOUBLE_EQ(*res_help, _res);
        free(res); free(a); free(b);
    }
};
INSTANTIATE_TEST_SUITE_P(SmallSizeInt, VectorMultSetTest,
::testing::Values(
    std::make_tuple(4, 2, 3, 6),
    std::make_tuple(19, 2, 3, 6),
    std::make_tuple(30, 2, 3, 6),
    std::make_tuple(93, 2, 3, 6),
    std::make_tuple(199, 2, 3, 6)
));
INSTANTIATE_TEST_SUITE_P(SmallSizeDouble, VectorMultSetTest,
::testing::Values(
    std::make_tuple(4, 2.2, 3.3, 7.26),
    std::make_tuple(19, 2.2, 3.3, 7.26),
    std::make_tuple(30, 2.2, 3.3, 7.26),
    std::make_tuple(93, 2.2, 3.3, 7.26),
    std::make_tuple(199, 2.2, 3.3, 7.26)
));
INSTANTIATE_TEST_SUITE_P(LargeSizeInt, VectorMultSetTest,
::testing::Values(
    std::make_tuple(1004, 2, 3, 6),
    std::make_tuple(15698, 2, 3, 6),
    std::make_tuple(23486, 2, 3, 6),
    std::make_tuple(234605, 2, 3, 6),
    std::make_tuple(1123544, 2, 3, 6)
));
INSTANTIATE_TEST_SUITE_P(LargeSizeDouble, VectorMultSetTest,
::testing::Values(
    std::make_tuple(1004, 2.2, 3.3, 7.26),
    std::make_tuple(15698, 2.2, 3.3, 7.26),
    std::make_tuple(23486, 2.2, 3.3, 7.26),
    std::make_tuple(234605, 2.2, 3.3, 7.26),
    std::make_tuple(1123544, 2.2, 3.3, 7.26)
));

class VectorMultTest : public ::testing::TestWithParam<
        std::tuple<std::vector<double>, std::vector<double>, std::vector<double>>>
{
public:
    double *res;
    const double *a = std::get<0>(GetParam()).data(), *b = std::get<1>(GetParam()).data(); 
    unsigned int size = std::get<0>(GetParam()).size();

    void SetUp() override
    {
        unsigned size2 = std::get<1>(GetParam()).size(), size3 = std::get<2>(GetParam()).size();
        ASSERT_EQ(size, size2) << "Element-wise vector multiplication requires vector of equal length!";
        ASSERT_EQ(size2, size3) << "Element-wise vector multiplication requires vector of equal length!";
        res = (double*)malloc(sizeof(double) * size);
    }

    void TearDown() override
    {
        const double* _res = std::get<2>(GetParam()).data();
        double *res_help = res;
        for(unsigned long i = 0; i < size; ++i, ++res_help, ++_res)
            EXPECT_DOUBLE_EQ(*res_help, *_res);
        free(res);
    }
};
INSTANTIATE_TEST_SUITE_P(Int, VectorMultTest,
::testing::Values(
    std::make_tuple(std::vector<double>{1,2,3,4}, std::vector<double>{1,2,3,4}, std::vector<double>{1,4,9,16}),
    std::make_tuple(std::vector<double>{6,7,8,9,10}, std::vector<double>{6,7,8,9,10}, std::vector<double>{36,49,64,81,100}),
    std::make_tuple(std::vector<double>{1001,1002,1003,10019}, std::vector<double>{1,1,1,1}, std::vector<double>{1001,1002,1003,10019})
));
INSTANTIATE_TEST_SUITE_P(Double, VectorMultTest,
::testing::Values(
    std::make_tuple(std::vector<double>{1.1,2.2,3.3,4.4}, std::vector<double>{1,2,3,4}, std::vector<double>{1.1,4.4,9.9,17.6}),
    std::make_tuple(std::vector<double>{6.1,7.1,8.1,9.1,10.1}, std::vector<double>{6,7,8,9,10}, std::vector<double>{36.6,49.7,64.8,81.9,101}),
    std::make_tuple(std::vector<double>{1001,1002,1003,10019}, std::vector<double>{1,1.0,1,1.0}, std::vector<double>{1001,1002.0,1003,10019})
));

#endif // !1PARALLEL_BENCHMARK_VECTOR_MULT_TEST_HPP