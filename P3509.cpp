#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N = 1e6 + 10;
int n, k, fa[N], f[N],now[N];
long long a[N], m;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int l = 1, r = k + 1;
    for (int i = 1; i <= n; i++)
    {
        while (r < n && abs(a[r + 1] - a[i]) < abs(a[l] - a[i])) l++, r++;
        if (abs(a[l] - a[i]) >= abs(a[r] - a[i]))fa[i] = l;
        else fa[i] = r;
    }

    long long mm = m;
    for(int i=1;i<=n;i++)
        now[i]=i;
    while (mm)
    {
        if (mm & 1)
            for(int i=1;i<=n;i++)
                now[i]=fa[now[i]];
        mm >>= 1;
        for(int i=1;i<=n;i++)
            f[i]=fa[i];
        for(int i=1;i<=n;i++)
            fa[i]=f[f[i]];
    }
    for(int i=1;i<=n;i++)
        cout<<now[i]<<" ";
    return 0;
}