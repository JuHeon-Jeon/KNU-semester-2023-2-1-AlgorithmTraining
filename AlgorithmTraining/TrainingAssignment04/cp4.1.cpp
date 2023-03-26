#include <iostream>
#include <vector>
using namespace std;

void strassen();


int main(void)
{
    int n, threshold, k = 1;

    cin >> n >> threshold;

    if (n % 2)
    {
        while (k < n)
            k *= 2;
        n = k;
    }

    vector<vector<int>>S(n + 1, vector<int>(n + 1));
    vector<vector<int>>T(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> S[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> T[i][j];

    
    
    return 0;
}

void strassen()
{

}