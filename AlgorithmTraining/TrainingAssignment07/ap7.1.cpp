#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

vector<vector<int>> W;
vector<int> nearest, dist;
vector<pair<int, int>> F;

void prim(int n);

int main(void)
{
    int n, m, col, row;

    cin >> n >> m;

    W.resize(n + 1, vector<int>(n + 1, INT_MAX));
    nearest.resize(n + 1, 0);
    dist.resize(n + 1, INT_MAX);
    F.resize(n + 1);

    for (int i = 1; i <= n; i++)
    {
        W[i][i] = 0;
    }
    
    for (int i = 0; i < m; i++)
    {
        int val;
        cin >> row >> col;
        cin >> val;
        W[row][col] = val;
        W[col][row] = val;
    }

    prim(n);

    for (int i = 2; i <= n; i++)
        cout << F[i].first << " " << F[i].second << " " << W[F[i].first][F[i].second] << endl;

    return 0;
}

void prim(int n)
{
    int min, vnear;

    for (int i = 2; i <= n; i++)
    {
        nearest[i] = 1;
        dist[i] = W[1][i];
    }

    for (int j = 2; j < n; j++)
        cout << nearest[j] << " ";
    cout << nearest[n] << endl;

    for (int i = 2; i <= n; i++)
    {
        min = INT_MAX;
        for (int j = 2; j <= n; j++)
            if (0 <= dist[j] && dist[j] < min)
            {
                min = dist[j];
                vnear = j;
            }
        
        F[i] = {vnear, nearest[vnear]};

        dist[vnear] = -1;
        for (int j = 2; j <= n; j++)
            if (dist[j] > W[j][vnear])
            {
                dist[j] = W[j][vnear];
                nearest[j] = vnear;
            }

        for (int j = 2; j < n; j++)
            cout << nearest[j] << " ";
        cout << nearest[n] << endl;
    }
}