#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> b, c;

void lcs(string x, string y);
string get_lcs(int i, int j, string& x);

int main(void)
{
    string x, y, result = "";

    cin >> x >> y;

    lcs(x, y);
    result = get_lcs(x.length(), y.length(), x);

    cout << result.length() << endl;
    if (result.length())
        cout << result;

    return 0;
}

void lcs(string x, string y)
{
    int m, n;
    x = " " + x;
    y = " " + y;
    m = x.length();
    n = y.length();
    c.resize(m, vector<int>(n, 0));
    b.resize(m, vector<int>(n, 0));

    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
        {
            if (x[i] == y[j])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 1;
            }
            else
            {
                c[i][j] = max(c[i][j - 1], c[i - 1][j]);
                if (c[i][j - 1] > c[i - 1][j])
                    b[i][j] = 2;
                else
                    b[i][j] = 3;
            }
        }
}

string get_lcs(int i, int j, string& x)
{
    if (i == 0 || j == 0)
        return "";
    else
    {
        if (b[i][j] == 1)
            return get_lcs(i - 1, j - 1, x) + x[i - 1];
        else if (b[i][j] == 2)
            return get_lcs(i, j - 1, x);
        else if (b[i][j] == 3)
            return get_lcs(i - 1, j, x);
        else
            exit(1);
    }
}