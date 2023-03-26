#include <iostream>
#include <vector>
using namespace std;
int cnt = 0;

void quicksort(int low, int high, vector<int>& S);
void partition(int low, int high, int& pivotpoint, vector<int>& S);

int main(void)
{
    int n;
    vector<int>S;

    cin >> n;
    S.resize(n + 1);

    for(int i = 1; i <= n; i++)
        cin >> S[i];
    
    quicksort(1, n, S);

    for(int i = 1; i < n; i++)
        cout << S[i] << " ";
    cout << S[n] << endl;
    cout << cnt;

    return 0;
}

void quicksort(int low, int high, vector<int>& S)
{
    int pivotpoint = 1;

    if (low < high)
    {
        partition(low, high, pivotpoint, S);
        quicksort(low, pivotpoint - 1, S);
        quicksort(pivotpoint + 1, high, S);
    }
}

void partition(int low, int high, int& pivotpoint, vector<int>& S)
{
    int i, j, pivotitem;

    pivotitem = S[low];
    j = low;
    for (i = low+1; i <= high; i++) {
        if (S[i] < pivotitem) {
            j++;
            swap(S[i], S[j]);
            cnt++;
        }
    }
    pivotpoint = j;
    swap(S[low], S[pivotpoint]);
    cnt++;
}