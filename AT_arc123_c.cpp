#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
void solve()
{
    int n, a[100] = {0}, len = 0, m;
    cin >> n;
    while (n)
        a[++len] = n % 10, n /= 10;
    m = len;
    while (a[len] >= 1 && a[len] <= 3)
        len--;
    if (len == 0)
    {
        cout << "1" << endl;
        return;
    }
    while (a[len] >= 2 && a[len] <= 6)
        len--;
    if (len == 0)
    {
        cout << "2" << endl;
        return;
    }
    while (a[len] >= 3 && a[len] <= 9)
        len--;
    if (len == 0)
    {
        cout << "3" << endl;
        return;
    }
    int tag = 0;
    for (int i = 1; i <= len; i++)
    {
        if ((a[i] == 3 && !tag) || (a[i] == 4 && tag))
        {
            cout << "5" << endl;
            return;
        }
        tag = (a[i] <= 3);
    }
    cout << "4" << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
/*
5
456
10000
123
314
91
*/