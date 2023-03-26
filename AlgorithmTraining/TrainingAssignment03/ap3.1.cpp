#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binsearch(vector<int> v, int low, int high, int target, int* cnt);

int main(void)
{
    int n, m, cnt, gotcha;
    vector<int> v1;
    vector<int> v2;

    cin >> n >> m;
    v1.resize(n);
    v2.resize(m);

    for (int i = 0; i < n; i++)
        cin >> v1[i];
    for (int i = 0; i < m; i++)
        cin >> v2[i];

    sort(v1.begin(), v1.begin() + n);

    for (int i = 0; i < m; i++)
    {
        cnt = 0;
        gotcha = binsearch(v1, 0, n - 1, (int)v2[i], &cnt);
        cout << cnt << " " << gotcha + 1 << endl;
    }

    return 0;
}

int binsearch(vector<int> v, int low, int high, int target, int* cnt)
{
    int mid;
    (*cnt)++;

    if (low > high)
        return -1;
    else
    {
        mid = (low + high) / 2;
        if (target == v[mid])
            return mid;
        else if (target < v[mid])
            return binsearch(v, low, mid - 1, target, cnt);
        else if (target > v[mid])
            return binsearch(v, mid + 1, high, target, cnt);
    }
}
