#include "serial_.h"

unsigned long c2_serial_rec(long n)
{
    if(n <= 2)  return 1;
    return c2_serial_rec(n-1) + c2_serial_rec(n-2);
}

unsigned long dictionary[DCACHE_SIZE] = { 0 };

unsigned long c2_serial_rec_dict(long n)
{
    if (n <= 2) return 1;
    if (n < DCACHE_SIZE) 
    {
        if (dictionary[n] != 0) return dictionary[n];
        else return dictionary[n] = c2_serial_rec_dict(n - 1) + c2_serial_rec_dict(n - 2);
    } 
    else return c2_serial_rec_dict(n - 1) + c2_serial_rec_dict(n - 2);
}

unsigned long c2_serial_iter(long n)
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