Benchmark of parallel models:  
    C: pthreads, OpenMP  
    C++: thread standard library, Intel TBB  

Problems:  
    1. Vector element-wise multiplication  
    2. N-th Fibonacci number:  
        a. Recursive  
        b. Recursive with cache  
        c. Iterative  
    3. Finding maximum value in vector  

Project structure:  
    /src/task/model/ - contain solutions of problems in C and C++  
    /benchmark/ - contain code which generate time data  
    /data/env/ - contain time data for plotting  
    /plot/env/ - contain plots of task size vs execution time  
    /test/ - contain unit tests of solutions  

Unit tests: googletest  
Benchmarks: googlebenchmark  
Plots: bmplot

Test compilation and run:  
cd test clang++ -o all.test test_all.cpp -lgtest -fopenmp -lpthread -ltbb  
./all.test  
MPI Test compilation and run on N nodes:  
mpic++ -o mpi_c.test mpi_c_test.cpp -lgtest -lpthread  
mpic++ -o mpi_cpp.test mpi_cpp_test.cpp -lgtest -lpthread -lboost_mpi  
mpirun -n N mpi_c.test  
mpirun -n N mpi_cpp.test  

Benchmarks compilation and run:  
build commands are in .cpp files  
