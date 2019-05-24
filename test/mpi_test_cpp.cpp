#include "mpi_test_cpp_vector_mult.hpp"
#include "mpi_environment.hpp"

MPI_TEST_NULL_INPUT(BoostMpi, cpp1_mpi)
MPI_TEST_VECTOR_MULT(BoostMpi, cpp1_mpi)

// MPI_TEST_FIBONACCI(BoostMpi, cpp2_mpi_rec)

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    testing::AddGlobalTestEnvironment(new MPIEnvironment);
    return RUN_ALL_TESTS();
}