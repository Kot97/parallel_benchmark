#ifndef PARALLEL_BENCHMARK_TBB_2_HPP
#define PARALLEL_BENCHMARK_TBB_2_HPP

#include <tbb/task.h>
#include <tbb/concurrent_hash_map.h>

unsigned long cpp2_serial_rec_p(long n)
{
    if(n <= 2)  return 1;
    return cpp2_serial_rec_p(n-1) + cpp2_serial_rec_p(n-2);
}

using cache_t = tbb::concurrent_hash_map<long, unsigned long>;
cache_t cache; 

unsigned long cpp2_serial_rec_dict_p(long n)
{
    if (n <= 2) return 1;
    cache_t::const_accessor a;
    if (cache.find(a, n)) return (*a).second;
    a.release();
    unsigned long val = cpp2_serial_rec_dict_p(n-1) + cpp2_serial_rec_dict_p(n-2);
    cache.insert(std::make_pair(n, val));
    return val;
}

class fib_task : public tbb::task
{
public:
    const long n;
    unsigned long *const sum;
    fib_task(long n_, unsigned long *sum_) : n(n_), sum(sum_) {}

    tbb::task* execute() override
    {
        if(n < 20) *sum = cpp2_serial_rec_p(n);
        else
        {
            unsigned long i, j;
            fib_task *a = new(allocate_child()) fib_task(n-1, &i);
            fib_task *b = new(allocate_child()) fib_task(n-2, &j);
            set_ref_count(3);
            spawn(*b);
            spawn_and_wait_for_all(*a);
            *sum = i + j;
        }
        return nullptr;
    }
};

unsigned long cpp2_tbb(long n)
{
    if(n <= 2) return 1;
    unsigned long ret;
    fib_task& a = *new(tbb::task::allocate_root()) fib_task(n, &ret);
    tbb::task::spawn_root_and_wait(a);
    return ret;
}

class fib_task_dict : public tbb::task
{
public:
    const long n;
    unsigned long *const sum;
    fib_task_dict(long n_, unsigned long *sum_) : n(n_), sum(sum_) {}

    tbb::task* execute() override
    {
        if(n < 20) *sum = cpp2_serial_rec_dict_p(n);
        else
        {
            unsigned long i, j, count = 1;
            fib_task_dict *a = nullptr, *b = nullptr;
            cache_t::const_accessor acc;
            if (cache.find(acc, n))
            {
                *sum = (*acc).second;
                acc.release();
                return nullptr;
            }
            else
            {
                if(cache.find(acc, n-1))
                    i = (*acc).second;   
                else
                {
                    a = new(allocate_child()) fib_task_dict(n-1, &i);
                    count++;
                }
                acc.release();

                if(cache.find(acc, n-2))
                    j = (*acc).second;   
                else
                {
                    b = new(allocate_child()) fib_task_dict(n-2, &j);
                    count++;
                }
                acc.release();
            }

            set_ref_count(count);
            
            if(count == 3)
            {
                spawn(*b);
                spawn_and_wait_for_all(*a);
                cache.insert(std::make_pair(n-1, i));
                cache.insert(std::make_pair(n-2, j));
            }
            if(count == 2)
            {
                if(a)
                { 
                    spawn_and_wait_for_all(*a);
                    cache.insert(std::make_pair(n-1, i));
                }
                else 
                { 
                    spawn_and_wait_for_all(*b);
                    cache.insert(std::make_pair(n-2, j));
                }
            }
            *sum = i + j;
        }
        return nullptr;
    }
};

unsigned long cpp2_tbb_dict(long n)
{
    if(n <= 2) return 1;
    unsigned long ret;
    fib_task_dict& a = *new(tbb::task::allocate_root()) fib_task_dict(n, &ret);
    tbb::task::spawn_root_and_wait(a);
    return ret;
}


#endif // !1PARALLEL_BENCHMARK_TBB_2_HPP