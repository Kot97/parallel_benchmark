include_directories(../src)
link_directories(../src/1/c ../src/1/cpp ../src/2/c ../src/2/cpp ../src/3/c ../src/3/cpp)

add_executable( benchmark1 benchmark1.cpp )
target_link_libraries( benchmark1 PRIVATE
                    lib1c lib1cpp -lbenchmark -lbenchmark_main )

add_executable( benchmark2c benchmark2c.cpp )
add_executable( benchmark2cpp benchmark2cpp.cpp )
target_link_libraries( benchmark2c PRIVATE
                    lib2c -lbenchmark -lbenchmark_main)
target_link_libraries( benchmark2cpp PRIVATE 
                    lib2cpp -lbenchmark -lbenchmark_main)

add_executable( benchmark3 benchmark3.cpp )
target_link_libraries( benchmark3 PRIVATE
                    lib3c lib3cpp -lbenchmark -lbenchmark_main)