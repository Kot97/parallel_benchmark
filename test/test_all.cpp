#include "test_c_vector_mult.hpp"
#include "test_cpp_vector_mult.hpp"
#include "test_c_fibonacci.hpp"
#include "test_cpp_fibonacci.hpp"

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}