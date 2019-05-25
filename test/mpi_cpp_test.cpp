#include "mpi_environment.hpp"
#include "mpi_test_cpp_vector_mult.hpp"
#include "mpi_test_cpp_search.hpp"

MPI_TEST_NULL_INPUT(BoostMpi, cpp1_mpi)
MPI_TEST_VECTOR_MULT(BoostMpi, cpp1_mpi)
MPI_TEST_SEARCH(BoostMpi, cpp3_mpi)

// mpic++ -o mpi_cpp.test mpi_cpp_test.cpp -lgtest -lpthread -lboost_mpi
// mpirun -n N mpi_cpp.test

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    testing::AddGlobalTestEnvironment(new MPIEnvironment);
    return RUN_ALL_TESTS();
}