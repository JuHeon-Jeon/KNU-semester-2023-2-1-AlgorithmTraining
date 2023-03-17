#include <iostream>
#include <cmath>
using namespace std;

typedef long long long_t;

long_t fun(long_t n)
{
    if ( n == 0)
        return 1;
    else
        return pow(4, log2(n) + 1);
        //return fun(n/2) + fun(n/2) + fun(n/2) + fun(n/2);
}
int main()
{
    long_t n;
    scanf("%lld", &n);
    printf("%lld", fun(n));
}