Benchmark of parallel models:  
    C: pthreads, OpenMP  
    C++: thread standard library, Intel TBB  

Tasks:  
    1. Vector element-wise multiplication  
    2. N-th Fibonacci number:  
        a. Recursive  
        b. Recursive with cache  
        c. Iterative  
    3. Finding maximum value in vector  

Sizes of tasks:  
    1 and 3: 10^k, k = {3,...,8}  
    2: 10^k, k = {1,...,5}  

Project structure:  
    /src/task/model/ - contain code which generate time data for plotting  
    /data/task/model/ - contain time data for plotting  
    /plot/task/model/ - contain plots of task size vs execution time in model  
    /plot/task/ - contain plots of task size vs execution time for asymptotically best results in each model  
    /plot/ - contain plot of task size vs execution time for 2 asymptotically best results in each task and plotting.py  
    /test/ - contain unit tests

Unit tests: googletest  
Benchmarks: googlebenchmark  
Plots: matplotlib  

Environment:  
    Ubuntu 19.04 Linux 5.0.0 64 bit  
    Intel Core i5-3570K 3.40 GHz (4 threads)  
    3.8 GiB RAM  