#include "parameters3.hpp"
// #include "../src/3/c/mpi_.h"
#include <3/c/mpi_.h>

// mpirun benchmark1mpi --benchmark_out="../../data/1/benchmark1mpi.json" --benchmark_out_format=json --benchmark_report_aggregates_only=true

MPI_BENCHMARK_SEARCH(BM_mpi, c3_mpi)
MPI_BENCHMARK_SEARCH(BM_mpi_openmp, c3_mpi_openmp)

class NullReporter : public ::benchmark::BenchmarkReporter 
{
public:
  NullReporter() {}
  virtual bool ReportContext(const Context &) {return true;}
  virtual void ReportRuns(const std::vector<Run> &) {}
  virtual void Finalize() {}
};

int main(int argc, char **argv) 
{
    MPI_Init(&argc, &argv);

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    ::benchmark::Initialize(&argc, argv);

    if(rank == 0)
    {
        ::benchmark::RunSpecifiedBenchmarks();
    }
    else 
    {
        NullReporter null;
        ::benchmark::RunSpecifiedBenchmarks(&null);
    }

    MPI_Finalize();
    return 0;
}