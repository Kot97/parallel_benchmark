find_package(MPI REQUIRED)

add_executable( benchmark1 benchmark1.cpp )
target_link_libraries( benchmark1 PRIVATE
                    1 -lbenchmark -lbenchmark_main -ltbb )

add_executable( benchmark1mpi benchmark1mpi.cpp )
target_link_libraries( benchmark1mpi PRIVATE
                    1mpi -lbenchmark ${MPI_LIBRARIES})

add_executable( benchmark2c benchmark2c.cpp )
add_executable( benchmark2cpp benchmark2cpp.cpp )
target_link_libraries( benchmark2c PRIVATE
                    2c -lbenchmark -lbenchmark_main)
target_link_libraries( benchmark2cpp PRIVATE 
                    2cpp -lbenchmark -lbenchmark_main -ltbb)

add_executable( benchmark3 benchmark3.cpp )
target_link_libraries( benchmark3 PRIVATE
                    3 -lbenchmark -lbenchmark_main -ltbb ${MPI_LIBRARIES})

add_executable( benchmark3mpi benchmark3mpi.cpp )
target_link_libraries( benchmark3mpi PRIVATE
                    3mpi -lbenchmark ${MPI_LIBRARIES})