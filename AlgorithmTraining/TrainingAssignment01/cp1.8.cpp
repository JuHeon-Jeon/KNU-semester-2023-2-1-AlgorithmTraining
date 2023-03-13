#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
    int n;
    scanf("%d", &n);
    vector<int> S(n + 1);

    for (int i = 1; i <= n; i++)
        scanf("%d", &S[i]);
    sort(S.begin(), S.end());

    if ((n % 2))
        printf("%d %d %d", S[1], S[n / 2 + 1], S[n]);
    else
        printf("%d %d %d", S[1], S[n / 2], S[n]);
}