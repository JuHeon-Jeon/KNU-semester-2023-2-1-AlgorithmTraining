#include <iostream>
using namespace std;

typedef long long long2;
int cnt, king, kingCnt = 0;

void colConPrint (long2 n)
{
    if (n == 1)
        printf("1");
    else if (n % 2)
        {
            printf("%d ", n);
            colConPrint(n * 3 + 1);
        }
    else
        {
            printf("%d ", n);
            colConPrint(n / 2);
        }
}

void colConCnt (long2 n)
{
    if (n == 1)
        cnt++;
    else if (n % 2)
    {
        cnt++;
        colConCnt(n * 3 + 1);
    }
    else
    {
        cnt++;
        colConCnt(n / 2);
    }
}

void colConCf (long2 n)
{
    cnt = 0;
    colConCnt(n);
    if (kingCnt <= cnt)
        {
            king = n;
            kingCnt = cnt;
        }
}

int main(void)
{
    int start, end;

    scanf("%d %d", &start, &end);

    king = start;
    for (int i = start; i <= end; i++)
        colConCf((long2)i);

    printf("%d %d\n", king, kingCnt - 1);
    colConPrint(king);

    return 0;
}
