#include <iostream>
#include <vector>
using namespace std;

void powMatrix(vector<vector<int>>& S, int n, int power);

int main(void)
{
    int n, power;

    cin >> n >> power;
    vector<vector<int>> S(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> S[i][j];

    powMatrix(S, n, power);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < n; j++)
            cout << S[i][j] << " ";
        cout << S[i][n] << endl;
    }



    return 0;
}

void powMatrix(vector<vector<int>>& S, int n, int power)
{
    int m, flag = 0, tmp = 0;
    vector<vector<int>> T(n + 1, vector<int>(n + 1));
    vector<vector<int>> U(n + 1, vector<int>(n + 1));


    if (power % 2)
    {
        flag = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                T[i][j] = S[i][j];
    }
    
    m = power / 2;

    if (power > 1)
    {
        powMatrix(S, n, m);

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                U[i][j] = S[i][j];

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                tmp = 0;
                for (int k = 1; k <= n; k++)
                    tmp += (U[i][k] * U[k][j]);
                S[i][j] = tmp % 1000;
            }

        if (flag)
        {
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    U[i][j] = S[i][j];

            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                {
                    tmp = 0;
                    for (int k = 1; k <= n; k++)
                        tmp += (U[i][k] * T[k][j]);
                    S[i][j] = tmp % 1000;
                }
        }

        return;
    }
    if (power == 1)
        return;

    fprintf(stderr, "power < 1");
}