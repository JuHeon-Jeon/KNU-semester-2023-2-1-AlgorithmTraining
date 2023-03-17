#include <iostream>
#include <cmath>
using namespace std;

typedef long long long_t;

long_t log4(long_t n)
{
    long_t rtn = log(n) / log(4);
    return rtn;
}

long_t fun(long_t n)
{
    if (n == 0)
        return 1;
    else
    {
        long_t s = pow(8, log4(n) + 1);
        /*for (int i = 1; i <= 8; i++)
            s += fun(n/4);*/
        return s;
    }
}

int main()
{
    long_t n;
    scanf("%lld", &n);
    printf("%lld", fun(n));
}