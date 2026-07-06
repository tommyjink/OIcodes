#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 10;
int n, m, tag = 0;
char a[N][N];
void solve()
{
    if (n % 2 == 0 && m % 2 == 0)
    {
        for (int i = 1; i <= n; ++i)
            a[i][1] = a[i][m] = '1';
        for (int j = 1; j <= m; ++j)
            a[1][j] = a[n][j] = '1';
        for (int i = 2; i < n; ++i)
            if (i % 2 == 0)
                for (int j = 2; j < m; ++j)
                    a[i][j] = (j % 2 ? '1' : '*');
            else
                for (int j = 2; j < m; ++j)
                    a[i][j] = (j % 2 ? '*' : '1');
    }
    else
    {
        if (m % 2 == 0)
            swap(n, m), tag = 1;
        for (int i = 1; i <= n; ++i)
            a[i][1] = a[i][m] = '1';
        for (int j = 1; j <= m; ++j)
            a[1][j] = a[n][j] = '1';
        for (int i = 2; i < n; ++i)
            if (i % 2 == 0)
            {
                for (int j = 2; j < m; ++j)
                    a[i][j] = (j % 2 ? '1' : '*');
            }
            else
            {
                for (int j = 2; j < m; ++j)
                    a[i][j] = (j % 2 ? '*' : '1');
            }
        if (n % 2 == 1)
        {
            for (int i = 3, j = 3; i < max(n, m); i += 2)
            {
                if (i < n && i < m)
                    a[i][i] = '+';
                else if (i < n)
                {
                    if (i < n && j < m)
                    {
                        a[i][j] = '+';
                        j += 2;
                        if (j >= m)
                            j = 3;
                    }
                }
                else
                {
                    if (j < n && i < m)
                    {
                        a[j][i] = '+';
                        j += 2;
                        if (j >= n)
                            j = 3;
                    }
                }
            }
        }
        else if (m > 3)
            for (int i = 3; i < n; i += 2)
                a[i][3] = '+';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    solve();
    if (tag)
    {
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
                cout << a[j][i];
            cout << endl;
        }
    }
    else
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
                cout << a[i][j];
            cout << endl;
        }
    }
}
