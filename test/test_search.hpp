#ifndef PARALLEL_BENCHMARK_TEST_SEARCH_HPP
#define PARALLEL_BENCHMARK_TEST_SEARCH_HPP

#include <gtest/gtest.h>
#include <vector>

class SearchTest : public ::testing::TestWithParam<
                std::pair<std::vector<double>, double>>
{
public:
    const double *a = GetParam().first.data(), *b = GetParam().first.cend().base();
    const unsigned long size = GetParam().first.size();
};
INSTANTIATE_TEST_SUITE_P(Small, SearchTest, ::testing::Values(
    std::make_pair(std::vector<double>{1,2,3,4}, 4), 
    std::make_pair(std::vector<double>{1,2,3,4,5.5,6,7,8.1,9}, 9),
    std::make_pair(std::vector<double>{123,123,3,21,312,44,12,1111,2,3,4}, 1111)
));
INSTANTIATE_TEST_SUITE_P(Medium, SearchTest, ::testing::Values(
    std::make_pair(std::vector<double>{1239.99,12222.3,3111.1,21,312,4421321321.5,12,1111,2,3,4}, 4421321321.5),
    std::make_pair(std::vector<double>{1239.99,12321,4,421,1.1111,23213.3,12222.3,3111.1,21,312,41.5,1,11,2000000.22,3,4}, 2000000.22),
    std::make_pair(std::vector<double>{1,123,12312,3.2,1.2321,213123,12.3,11,22,123,4214,1224,6677891123.11}, 6677891123.11)
));
INSTANTIATE_TEST_SUITE_P(Large, SearchTest, ::testing::Values(
    std::make_pair(std::vector<double>
    {992222039.99,12222.3,3111.1,21,312,1321321.5,12,111,2,3,4,42121,1231,325643,64356,3463,4436,43643,1.643643,44}, 
    992222039.99),
    std::make_pair(std::vector<double>
    {1239.99,91212222.1111,9912,11.1,11,20000.22,3,4,45.5,43.3,111,32321,53252,54747,12,312,312.232,5.3253}, 
    91212222.1111),
    std::make_pair(std::vector<double>
    {1,12312,12321.3,121.23312,311.12,1.2321,22769131231.31,97697634,12312,12.3,11,22,123,4214,1224,6623.11}, 
    22769131231.31)
));

#define TEST_SEARCH(test_name, function_name)\
TEST_P(SearchTest, test_name)\
{\
    ASSERT_DOUBLE_EQ(function_name(a, b), GetParam().second);\
}

#endif