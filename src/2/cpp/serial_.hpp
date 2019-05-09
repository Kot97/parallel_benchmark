#ifndef PARALLEL_BENCHMARK_SERIAL_2_HPP
#define PARALLEL_BENCHMARK_SERIAL_2_HPP

#include <unordered_map>
#include "../../cutoffs.h"

unsigned long cpp2_serial_rec(long n)
{
    if(n <= 2)  return 1;
    return cpp2_serial_rec(n-1) + cpp2_serial_rec(n-2);
}

std::unordered_map<long, unsigned long> map;

unsigned long cpp2_serial_rec_dict(long n)
{
    if (n <= 2) return 1;
    if (map.find(n) != map.end()) return map[n];
    else return map[n] = cpp2_serial_rec_dict(n - 1) + cpp2_serial_rec_dict(n - 2);
}

unsigned long cpp2_serial_iter(long n)
{
    if(n <= 2) return 1;
    unsigned long a = 1, b = 1, temp;
    while((n--) > 2)
    {
        temp = a;
        a = b;
        b += temp;
    }
    return b;
}


#endif // !1PARALLEL_BENCHMARK_SERIAL_2_HPP