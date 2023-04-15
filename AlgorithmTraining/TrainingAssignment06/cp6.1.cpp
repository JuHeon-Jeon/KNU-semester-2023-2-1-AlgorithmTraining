#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> M, P;

void minMult(int n, vector<int> d);
int minimum(int i, int j, int& mink, vector<int> d);
void printMatrix(int n);
void orderMatrix(int i, int j, string& s);

int main(void)
{
    int n;
    vector<int> d;
    string str;

    cin >> n;
    d.resize(n + 1);
    M.resize(n, vector<int>(n));
    P.resize(n, vector<int>(n));

    for (int i = 0; i <= n; i++)
        cin >> d[i];

    minMult(n, d);
    printMatrix(n);
    cout << M[0][n - 1] << endl;
    orderMatrix(0, n - 1, str);
    cout << str;

    return 0;
}

void minMult(int n, vector<int> d)
{
    int i, j, k, diagonal;

    for (i = 0; i < n; i++)
        M[i][i] = 0;
    for (diagonal = 1; diagonal < n; diagonal++)
        for (i = 0; i < n - diagonal; i++)
        {
            j = i + diagonal;
            M[i][j] = minimum(i, j, k, d);
            P[i][j] = k;
        }
}

int minimum(int i, int j, int& mink, vector<int> d)
{
    int min = 999999, tmp;
    for (int k = i; k <= j - 1; k++)
    {
        tmp = M[i][k] + M[k + 1][j] + d[i] * d[k + 1] * d[j + 1];
        if (min > tmp)
        {
            min = tmp;
            mink = k + 1;
        }
    }

    return min;
}

void printMatrix(int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n - 1; j++)
            printf("%d ", M[i][j]);
        printf("%d\n", M[i][j]);
    }
    
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n - 1; j++)
            printf("%d ", P[i][j]);
        printf("%d\n", P[i][j]);
    }
}
void orderMatrix(int i, int j, string& s)
{
    if (i == j)
    {
        s += string("(");
        s += string("A") + to_string(i + 1);
        s += string(")");
    }
    else
    {
        int k = P[i][j] - 1;
        s += string("(");
        orderMatrix(i, k, s);
        orderMatrix(k + 1, j, s);
        s += string(")");
    }
}
