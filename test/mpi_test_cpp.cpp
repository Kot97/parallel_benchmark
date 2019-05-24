#include "mpi_environment.hpp"
#include "mpi_test_cpp_vector_mult.hpp"
#include "mpi_test_c_vector_mult.hpp"

MPI_TEST_NULL_INPUT(BoostMpi, cpp1_mpi)
MPI_TEST_VECTOR_MULT(BoostMpi, cpp1_mpi)

C_MPI_TEST_NULL_INPUT(OpenMpi, c1_mpi)
C_MPI_TEST_VECTOR_MULT(OpenMpi, c1_mpi)

// mpic++ -o mpi_cpp.test mpi_test_cpp.cpp -lgtest -lpthread -lboost_mpi

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    testing::AddGlobalTestEnvironment(new MPIEnvironment);
    return RUN_ALL_TESTS();
}