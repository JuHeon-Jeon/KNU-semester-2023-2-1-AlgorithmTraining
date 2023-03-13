#include <iostream>
#include <algorithm>
using namespace std;

int fib(int n);
int cnt = 0;
int main(void)
{
    int x, resultFib;
    scanf("%d", &x);
    resultFib = fib(x);
    printf("%d\n%d", resultFib, cnt);
}

int fib(int n)
{
    if (n <= 1)
    {
        cnt++;
        return n;
    }
    else
    {
        cnt++;
        return (fib(n - 1) + fib(n - 2)) % 1000000;
    }
}