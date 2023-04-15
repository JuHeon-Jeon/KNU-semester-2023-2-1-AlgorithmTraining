#include <iostream>
#include <vector>
using namespace std;

int bin(int n, int k);
vector<int> S;

int main(void)
{
    int n, k;

    cin >> n >> k;
    
    S.resize(n + 1);
    for (int i = 0; i < n; i++)
        S[i] = 0;
    
    cout << bin(n, k);

    return 0;
}

int bin (int n, int k)
{
    S[0] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = i; j > 0; j--)
            S[j] = (S[j] + S[j - 1]) % 10007;

    return S[k];
}