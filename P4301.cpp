#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int M = 60;
int n, a[10000], ans = 0, p[M];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n, greater<int>());
    for (int i = 1; i <= n; i++)
    {
        int x = a[i];
        bool tag = false;
        for (int j = M - 1; j >= 0; j--)
        {
            if ((x >> j) & 1)
            {
                if (!p[j])
                {
                    p[j] = x;
                    tag = true;
                    break;
                }
                else
                    x ^= p[j];
            }
        }
        if (!tag)
            ans += a[i];
    }
    cout << ans << endl;
    return 0;
}