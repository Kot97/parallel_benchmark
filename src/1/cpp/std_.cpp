#include "std_.hpp"

unsigned int num_threads2 = std::thread::hardware_concurrency();

void _cpp1_thread(int id, double *result, const double *a, const double *b, unsigned long size)
{
    unsigned long end = size / num_threads2;
    for(unsigned long i = 0; i < end; ++i, result+=num_threads2, a+=num_threads2, b+=num_threads2)
        *result = *a * *b;
    
    if(id == num_threads2-1 && size % num_threads2 != 0)
    {
        result -= (num_threads2-1); 
        a -= (num_threads2-1); 
        b -= (num_threads2-1); 
        for(unsigned long i = size - size%num_threads2; i < size; ++i, ++result, ++a, ++b)
            *result = *a * *b;
    }
} 

void cpp1_thread(double *result, const double *a, const double *b, unsigned long size)
{
    if(size < CUTOFF1) { c1_serial(result, a, b, size); return; }
    std::vector<std::thread> threads;

    for(int i = 0; i < num_threads2; ++i)
        threads.emplace_back(_cpp1_thread, i, result + i, a + i, b + i, size);

    for(auto& i : threads) i.join();
}