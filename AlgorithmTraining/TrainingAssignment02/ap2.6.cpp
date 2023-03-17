#include <iostream>
using namespace std;

typedef long long long2;
int cnt;

void colCon (long2 n)
{
    cnt = 0;
    if (n == 1)
        cnt++;
    else if (n % 2)
            colCon(n * 3 + 1);
    else
            colCon(n / 2);
}
