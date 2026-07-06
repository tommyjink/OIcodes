#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n, k;
map<int, int> mp;
void dfs(int x, int now)
{
    if (mp.count(x))return;
    mp[x] = now;
    if (x == 1 || x == k)return;
    if (x % 2 == 1)
        dfs(x / 2, now + 1),
        dfs(x / 2 + 1, now + 1);
    else dfs(x / 2, now + 1);
}
void solve()
{
    mp.clear();
    cin >> n >> k;
    if (n == k){cout << "0"<<endl;return;}
    dfs(n, 0);
    if (mp[k]) cout << mp[k] << endl;
    else cout << "-1" << endl;
}
signed main()
{
    cin>>t;
    while (t--)
        solve();
    return 0;
}
