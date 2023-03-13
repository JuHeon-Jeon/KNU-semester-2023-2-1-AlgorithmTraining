#include <iostream>
#include <algorithm>
using namespace std;

int fib(int x);

int main(void)
{
    int x, resultFib;
    scanf("%d", &x);
    resultFib = fib(x);
    printf("%d", resultFib);
}
int fib(int x)
{
    int fib = 0, prefib = 1, prefib2 = 0;
    if (x < 2)
        return x;
    for (int i = 2; i <= x; i++)
    {
        fib = (prefib + prefib2) % 1000000;
        prefib2 = prefib;
        prefib = fib;
    }
    return fib;
}