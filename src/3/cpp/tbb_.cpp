#include "tbb_.hpp"

template<typename T>
T cpp3_tbb_reduce(const T *a, const T *b)
{
    if(b - a < CUTOFF3) return cpp3_serial(a, b);
    return tbb::parallel_reduce(tbb::blocked_range<const T*>(a, b), *a, 
    [&](const auto& r, T temp)
    {
        T temp_max = temp;
        for(auto i : r) if (i > temp_max) temp_max = i;
        return temp_max;
    }, 
    [&](T max1, T max2)
    {
        return max1 > max2 ? max1 : max2;
    });
}

template<typename T> tbb::task* search_task<T>::execute()
{
    unsigned long size = b - a;
    if(size < CUTOFF3) *max = cpp3_serial(a, b);
    else
    {
        T i, j;
        search_task<T> *task1 = new(allocate_child()) search_task<T>(a, b-size/2, &i);
        search_task<T> *task2 = new(allocate_child()) search_task<T>(b-size/2, b, &j);
        set_ref_count(3);
        spawn(*task2);
        spawn_and_wait_for_all(*task1);
        *max = i > j ? i : j;
    }
    return nullptr;
}

template<typename T>
T cpp3_tbb_task(const T *a, const T *b)
{
    if(b - a < CUTOFF3) cpp3_serial(a, b);
    T max;
    search_task<T> *task = new(tbb::task::allocate_root()) search_task<T>(a, b, &max);
    tbb::task::spawn_root_and_wait(*task);
    return max;
}