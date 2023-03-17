#include <iostream>
using namespace std;

typedef long long long2;

void colCon (long2 n)
{
    if (n == 1)
        printf("1");
    else if (n % 2)
        {
            printf("%d ", n);
            colCon(n * 3 + 1);
        }
    else
        {
            printf("%d ", n);
            colCon(n / 2);
        }
}

int main(void)
{
    long2 n;
    scanf("%lld", &n);
    colCon(n);

    return 0;
}