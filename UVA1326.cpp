#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 30;
int n, a[N], ans = 0, sav = 0;
map<int, int> mp, mp2;
void dfs(int l, int r, int cnt, int now, int val, int mode)
{
    if (l > r)
    {
        if (mode)
        {
            if (!mp.count(val) || cnt > mp[val])
                mp[val] = cnt, mp2[val] = now;
        }
        else
        {
            if (mp.count(val) && mp[val] + cnt > ans)
                ans = mp[val] + cnt, sav = mp2[val] | now;
        }
        return;
    }
    dfs(l + 1, r, cnt, now, val, mode);
    dfs(l + 1, r, cnt + 1, now | (1ll << (l - 1)), val ^ a[l], mode);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n)
    {
        memset(a,0,sizeof(a));
        mp.clear(),mp2.clear();
        ans=0,sav=0;
        for (int i = 1; i <= n; i++)
        {
            string s;
            cin >> s;
            for (int j = 0; j < s.length(); j++)
                a[i] ^= (1ll << (s[j] - 'A'));
        }
        dfs(1, n / 2, 0, 0, 0, 1);
        dfs(n / 2 + 1, n, 0, 0, 0, 0);
        cout << ans << endl;
        for (int i = 1; i <= n; i++)
            if (sav & (1ll << (i - 1)))
                cout << i << " ";
    }
    return 0;
}