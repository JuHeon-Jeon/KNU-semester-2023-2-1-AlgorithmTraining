#include <iostream>
#include <vector>
//#include <algorithm>
using namespace std;
int cnt = 0;

void mergesort(int n, vector<int>& S);
void merge(int h, int m, vector<int> U, vector<int> v, vector<int>& S);

int main(void)
{
    int n;
    vector<int> S;

    cin >> n;
    S.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> S[i];

    mergesort(n, S);

    for (int i = 1; i < n; i++)
        cout << S[i] << " ";
    cout << S[n];
    cout << endl;
    cout << cnt;

    return 0;
}

void mergesort(int n, vector<int>& S) {
    if (n > 1) {
        int h = n / 2, m = n - h;
        vector<int> U(h+1), V(m+1);
        cnt += h + m; // 추가 메모리 크기 카운트. cnt는 전역 변수
        for (int i = 1; i <= h; i++)
            U[i] = S[i];
        for (int i = h+1; i <= n; i++)
            V[i - h] = S[i];
        mergesort(h, U);
        mergesort(m, V);
        merge(h, m, U, V, S);
    }
}

void merge(int h, int m, vector<int> U, vector<int> V, vector<int>& S)
{
    int i = 1, j = 1, k = 1;

    while (i <= h && j <= m)
    {
        if (U[i] <= V[j])
            S[k++] = U[i++];
        else
            S[k++] = V[j++];
    }

    if (i > h)
        while (j <= m)
            S[k++] = V[j++];
    else
        while (i <= h)
            S[k++] = U[i++];
}
