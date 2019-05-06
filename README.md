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
Plots: matplotlib  

Environment:  
1)Ubuntu 19.04 Linux 5.0.0 64 bit  
  Intel Core i5-3570K 3.40 GHz (4 threads)  
  3.8 GiB RAM  