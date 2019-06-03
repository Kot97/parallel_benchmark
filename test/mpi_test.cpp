#include "mpi_environment.hpp"
#include "mpi_test_vector_mult.hpp"
#include "mpi_test_search.hpp"

C_MPI_TEST_NULL_INPUT(Mpi, c1_mpi)
C_MPI_TEST_VECTOR_MULT(Mpi, c1_mpi)
C_MPI_TEST_SEARCH(Mpi, c3_mpi)

C_MPI_TEST_NULL_INPUT(MpiOpenmp, c1_mpi_openmp)
C_MPI_TEST_VECTOR_MULT(MpiOpenmp, c1_mpi_openmp)
C_MPI_TEST_SEARCH(MpiOpenmp, c3_mpi_openmp)

// mpic++ -o mpi.test mpi_test.cpp ../src/1/c/mpi_.c ../src/1/c/serial_.c ../src/1/c/openmp_.c ../src/3/c/mpi_.c ../src/3/c/serial_.c ../src/3/c/openmp_.c -lgtest -lpthread -fopenmp
// mpirun -n N mpi.test

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    testing::AddGlobalTestEnvironment(new MPIEnvironment);
    return RUN_ALL_TESTS();
}