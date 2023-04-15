#include <iostream>
#include <vector>
using namespace std;

#define INF 999;
vector<vector<int>> D, P, T;

void printArr(vector<vector<int>> Arr);
void printT(vector<vector<int>>& T);
void Floyd2(int n);
void path(int start, int finish, int row);

int main(void)
{
    int n, m, t;
    int u, v, w;

    cin >> n >> m;

    D.resize(n + 1, vector<int>(n + 1, 0));
    P.resize(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        D[u][v] = w;
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
            {
                if(!D[i][j])
                    D[i][j] = INF;
            }
        }

    cin >> t;
    
    T.resize(t + 1, vector<int>(3, 0));

    for (int i = 1; i <= t; i++)
    {
        cin >> u >> v;
        T[i][1] = u;
        T[i][2] = v;
    }

    Floyd2(n);
    for (int i = 1; i <= t; i++)
    {
        int j = T[i][2];
        int start = T[i][1];
        T.pop_back();

        path(start, j, i);

        T[i].push_back(j);
    }

    printArr(D);
    printArr(P);
    printT(T);

    return 0;
}

void printArr(vector<vector<int>> Arr)
{
    int m, n;
    m = Arr.size();
    n = Arr[1].size();

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n - 1; j++)
            cout << Arr[i][j] << " ";
        cout << Arr[i][n - 1] << endl;
    }
}

void printT(vector<vector<int>>& T)
{
    int m, n;
    m = T.size();

    for (int i = 1; i < m; i++)
    {
        int j = 1;
        n = T[i].size();
        while (true)
        {
            if (T[i][0] == -1) //길 없을 시 NONE
            {
                cout << "NONE";
                break;
            }

            if (j == n - 1)
            {
                cout << T[i][j];
                break;
            }
            
            cout << T[i][j] << " ";
            j++;
        }
        cout << endl;
    }
}

void Floyd2(int n)
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                if (D[i][j] > D[i][k] + D[k][j])
                {
                    D[i][j] = D[i][k] + D[k][j];
                    P[i][j] = k;
                }
            }
}

void path(int start, int finish, int row)
{
    int k = P[start][finish];
    if (k == 999)
        T[row][0] = -1;
    if (k != 0)
    {
        path(start, k, row);
        T[row].push_back(k);
        path(k, finish, row);
    }
}