#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sum(int n, vector<int> S);

int main() {
    int n;
    scanf("%d", &n);
    vector<int> S(n+1);
    for (int i = 1; i <= n; i++)
        scanf("%d", &S[i]);
    printf("%d", sum(n, S));
}

int sum(int n, vector<int> S)
{
    int result = 0;
    for (int i = 1; i <= n; i++)
        result += S[i];
    return result;
}