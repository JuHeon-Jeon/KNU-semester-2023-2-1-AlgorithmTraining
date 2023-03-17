#include <iostream>
using namespace std;
long long fnCnt = 0, blocCnt = 0;

void hanoi(int n, int k, char src, char via, char dst) {
    fnCnt++;
    if (n == 1)
        blocCnt++;
    else {
        hanoi(n-1, k, src, dst, via);
        hanoi(1, k, src, via, dst);
        if (k == blocCnt)
            printf("%c -> %c\n", src, dst);
        hanoi(n-1, k, via, src, dst);
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    hanoi(n, k, 'A', 'B', 'C');
    cout << fnCnt;
}