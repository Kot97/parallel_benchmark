Benchmark of parallel models:  
    C: pthreads, OpenMP, MPI  
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

Build system: CMake  
Unit tests: googletest  
Benchmarks: googlebenchmark  
Plots: bmplot

