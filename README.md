Benchmark of parallel models:  
    C: pthreads, OpenMP  
    C++: thread standard library, Intel TBB, PSTL  
    Python: thread, process  
In addicion in each language there is also serial solution for each task (in Python one more with usage of numpy)  

Tasks:  
    1. Vector multiplication  
    2. N-th Fibonacci number:  
        a. Recursive  
        b. Recursive with cache  
        c. Iterative  
    3. Finding maximum value in vector  

Sizes of tasks:  
    1 and 3: 10^k, k = {3,...,9}  
    2: 10^k, k = {1,...,4}  

Project structure:  
    /src/task/model/ - contain code which generate time data for plotting  
    /src/task/model/test/ - contain unit tests for model (C/C++: gtest, Python: pytest)  
    /data/task/model/ - contain time data for plotting  
    /plot/task/model/ - contain plots of task size vs execution time in model  
    /plot/task/ - contain plots of task size vs execution time for asymptotically best results in each model  
    /plot/ - contain plot of task size vs execution time for 2 asymptotically best results in each task and plotting.py which plot all plots using matplotlib  

Environment:
    Ubuntu 19.04 Linux 5.0.0 64 bit  
    Intel Core i5-3570K 3.40 GHz (4 threads)  
    3.8 GiB RAM  