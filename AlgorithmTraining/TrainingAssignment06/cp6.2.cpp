#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> A, R, K;
vector<int> order;


void optSearchTree(int n);
int minimum(int i, int j, int& k);
void printMatrix(int n);
void orderTree(int i, int j, int start);

int main (void)
{
    int n;

    cin >> n;

    A.resize(n + 2, vector<int>(n + 1, 0));
    R.resize(n + 2, vector<int>(n + 1, 0));
    K.resize(n + 1, vector<int>(2, 0));


    for (int i = 1; i <= n; i++)
        cin >> K[i][0];
    for (int i = 1; i <= n; i++)
        cin >> K[i][1];

    optSearchTree(n);
    printMatrix(n);
    cout << A[1][n] << endl;

    orderTree(1, n, R[1][n]);

    int i;
    for (i = 0; i < order.size() - 1; i++)
        cout << K[order[i]][0] << " ";
    cout << K[order[i]][0] << endl;

    for (i = 1; i < n; i++)
        cout << K[i][0] << " ";
    cout << K[i][0] << endl;


    return 0;
}

void optSearchTree(int n)
{
    int i, j, k, diagonal;

    for (i = 1; i <= n; i++)
    {
        A[i][i] = K[i][1];  A[i][i - 1] = 0;
        R[i][i] = i;        R[i][i - 1] = 0;
    }
    A[n + 1][n] = 0;
    R[n + 1][n] = 0;

    for (diagonal = 1; diagonal <= n - 1; diagonal++)
        for (i = 1; i <= n - diagonal; i++)
        {
            j = i + diagonal;
            A[i][j] = minimum(i, j, k);
            R[i][j] = k;
        }
}

int minimum(int i, int j, int& mink)
{
    int minVal = 999999, k, tmp, sumPer = 0;

    for (int m = i; m <= j; m++)
        sumPer += K[m][1];

    for (k = i; k <= j; k++)
    {
        tmp = A[i][k - 1] + A[k + 1][j] + sumPer;
        if (minVal > tmp)
        {
            minVal = tmp;
            mink = k;
        }
    }

    return minVal;
}

void printMatrix(int n)
{
    int i, j;
    for (i = 1; i <= n + 1; i++)
    {
        for (j = i - 1; j < n; j++)
            cout << A[i][j] << " ";
        cout << A[i][j] << endl;
    }
    
    for (i = 1; i <= n + 1; i++)
    {
        for (j = i - 1; j < n; j++)
            cout << R[i][j] << " ";
        cout << R[i][j] << endl;
    }

}

void orderTree(int i, int j, int start)
{
    int root;

    root = R[i][j];

    if (i <= j)
    {
        order.push_back(root);
        orderTree(i, root - 1, start);
        orderTree(root + 1, j, start);
    }
}