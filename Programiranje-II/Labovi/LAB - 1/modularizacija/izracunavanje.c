#include "izracunavanje.h"
long long faktorijel(int n)
{
    long long temp = 1;
    for (int i = 2; i <= n; ++i)
        temp *= i;
    return temp;
}
long long suma(long long* niz, int n)
{
    long long s = niz[0];
    for (int i = 1; i < n; ++i)
        s += niz[i];
    return s;
}
