#include "mpi_environment.hpp"
#include "mpi_test_vector_mult.hpp"
#include "mpi_test_search.hpp"

C_MPI_TEST_NULL_INPUT(OpenMpi, c1_mpi)
C_MPI_TEST_VECTOR_MULT(OpenMpi, c1_mpi)
C_MPI_TEST_SEARCH(OpenMpi, c3_mpi)

// mpic++ -o mpi_c.test mpi_c_test.cpp -lgtest -lpthread
// mpirun -n N mpi_c.test

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    testing::AddGlobalTestEnvironment(new MPIEnvironment);
    return RUN_ALL_TESTS();
}