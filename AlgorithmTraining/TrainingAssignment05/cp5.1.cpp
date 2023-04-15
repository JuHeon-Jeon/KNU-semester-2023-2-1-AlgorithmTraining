#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;
int bin (int n, int k);
vector<vector<int>> S(1001, vector<int>(1001, 0));

int main(void)
{
    int n, k;

    cin >> n >> k;

    cout << bin (n, k) << endl;
    cout << cnt;

    return 0;
}

int bin (int n, int k)
{
    cnt++;
    if (k == 0 || k == n)
        S[n][k] = 1;
    else if (S[n][k] == 0)
        S[n][k] = (bin(n - 1, k) + bin (n - 1, k - 1)) % 10007;
    
    return S[n][k];

}