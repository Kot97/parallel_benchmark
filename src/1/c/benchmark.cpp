#include "../write.hpp"
#include "pthread_.h"
#include "openmp_.h"
#include "serial_.h"

int main(int argc, char const *argv[])
{
    int num_threads;
    unsigned long min, max, step;
    if(argc == 2) num_threads = strtol(argv[1], NULL, 10);
    else if(argc == 3)
    {
        min = strtol(argv[1], NULL, 10);
        max = strtol(argv[2], NULL, 10);
        step = 100;
        num_threads = 4;
    }
    else if(argc == 4)
    {
        min = strtol(argv[1], NULL, 10);
        max = strtol(argv[2], NULL, 10);
        step = strtol(argv[3], NULL, 10);
        num_threads = 4;
    }
    else if(argc == 5)
    {
        min = strtol(argv[1], NULL, 10);
        max = strtol(argv[2], NULL, 10);
        step = strtol(argv[3], NULL, 10);
        num_threads = strtol(argv[4], NULL, 10);
    }
    else
    {
        num_threads = 4;
        min = 100;
        max = 1000000000;
        step = 100;
    }

    printf("Benchmarking element-wise vector multiplication in C...\n\n");
    benchmark_time_t benchmark_start = get_time();

    unsigned long size = (max - min) / step + 1;
    
    unsigned long *task_size = (unsigned long*)malloc(sizeof(unsigned long)*size);
    benchmark_time_t *times_serial = (benchmark_time_t*)malloc(sizeof(benchmark_time_t)*size);
    benchmark_time_t *times_pthread = (benchmark_time_t*)malloc(sizeof(benchmark_time_t)*size);
    benchmark_time_t *times_openmp = (benchmark_time_t*)malloc(sizeof(benchmark_time_t)*size);
    benchmark_time_t *times_openmp_for = (benchmark_time_t*)malloc(sizeof(benchmark_time_t)*size);
    benchmark_time_t *times_openmp_for_simd = (benchmark_time_t*)malloc(sizeof(benchmark_time_t)*size);

    unsigned long *temp_task_size = task_size;
    benchmark_time_t *temp_times_serial = times_serial;
    benchmark_time_t *temp_times_pthread = times_pthread;
    benchmark_time_t *temp_times_openmp = times_openmp;
    benchmark_time_t *temp_times_openmp_for = times_openmp_for;
    benchmark_time_t *temp_times_openmp_for_simd = times_openmp_for_simd;

    benchmark_time_t start, end;

    double *result, *a, *b;
    for(unsigned long i = min; i < max; i+=step)
    {
        *(temp_task_size++) = i;
        result = (double*)malloc(sizeof(double)*i);
        a = (double*)malloc(sizeof(double)*i);
        b = (double*)malloc(sizeof(double)*i);
        
        start = get_time();
        c1_serial(result, a, b, i);
        end = get_time();
        *(temp_times_serial++) = (end - start);

        start = get_time();
        c1_pthread(result, a, b, i, num_threads);
        end = get_time();
        *(temp_times_pthread++) = (end - start);

        start = get_time();
        c1_openmp_parallel(result, a, b, i);
        end = get_time();
        *(temp_times_openmp++) = (end - start);

        start = get_time();
        c1_openmp_parallel_for(result, a, b, i);
        end = get_time();
        *(temp_times_openmp_for++) = (end - start);

        start = get_time();
        c1_openmp_parallel_for_simd(result, a, b, i);
        end = get_time();
        *(temp_times_openmp_for_simd++) = (end - start);

        free(result); free(a); free(b);
    }

    const char* pthread_filename = "../../data/1/c/pthread.txt";
    const char* openmp_filename = "../../data/1/c/openmp_parallel.txt";
    const char* openmp_for_filename = "../../data/1/c/openmp_parallel_for.txt";
    const char* openmp_for_simd_filename = "../../data/1/c/openmp_parallel_for_simd.txt";

    write(pthread_filename, task_size, times_pthread, size);
    write(openmp_filename, task_size, times_openmp, size);
    write(openmp_for_filename, task_size, times_openmp_for, size);
    write(openmp_for_simd_filename, task_size, times_openmp_for_simd, size);

    auto benchmark_end = std::chrono::steady_clock::now().time_since_epoch().count();
    
    printf("Benchmark took %lf s", (benchmark_end - benchmark_start)/1000);

    free(task_size); free(times_serial); free(times_pthread); free(times_openmp); 
    free(times_openmp_for); free(times_openmp_for_simd);
    return 0;
}
