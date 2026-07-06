#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 5005;
int n, op[N], a[N];
bool check1()
{
    int b = -1e9, c = 1e9;
    for (int i = 1; i <= n; i++)
    {
        b = max(b, a[i]);
        c = min(c, a[i]);
        if (op[i] == 0 && a[i] != c)
            return false;
        if (op[i] == 1 && a[i] != b)
            return false;
    }
    return true;
}
bool check2()
{
    int b = -1e9, c = 1e9;
    for (int i = n; i >= 1; i--)
    {
        b = max(b, a[i]);
        c = min(c, a[i]);
        if (op[i] == 2 && a[i] != c)
            return false;
        if (op[i] == 3 && a[i] != b)
            return false;
    }
    return true;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> op[i], a[i] = i;
    int ans = 0;
    while (next_permutation(a + 1, a + 1 + n))
    {
        // for (int i = 1; i <= n; i++)
        //     cout << a[i] << " ";
        // cout << endl;
        if (check1() && check2())
        {
            ans++;
            // for (int i = 1; i <= n; i++)
            //     cout << a[i] << " ";
            // cout << endl;
        }
    }
    cout << ans << endl;
    return 0;
}