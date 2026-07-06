//8-22 contest B
#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N=1e6+100;
int n, m, s, p[N], fa[N], v[N], c[N], mx[N], d[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin>>a;
        if (p[a])
            fa[i] = p[a], ++s;
        else
            p[a] = i, v[a] = 1;
    }
    m = 1e6;
    for (int i = m; i; i--)
    {
        if (!p[i])
            continue;
        for (int j = i << 1; j <= m; j += i)
            if (p[j] && !fa[p[j]])
                fa[p[j]] = p[i], v[j] = i, ++s;
    }
    if (s < n - 1)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    for (int i = 1; i <= m; i++)
        if (p[i])
        {
            d[i] = d[v[i]] + 1;
            c[i / v[i]]++;
            if (d[i] > d[mx[i / v[i]]])
                mx[i / v[i]] = i;
        }
    for (int i = 2; i <= m; i++)
    {
        int tot = 0, t = 0;
        for (int j = i; j <= m; j += i)
        {
            tot += c[j];
            if (d[t] < d[mx[j]])
                t = mx[j];
        }
        while (t > 1)
        {
            if ((t / v[t]) % i == 0)
                --tot;
            t = v[t];
        }
        if (tot)
        {
            cout<<"-1"<<endl;
            return 0;
        }
    }
    for (int i = 1; i <= n; i++)
        cout<<fa[i]<<" ";
    return 0;
}
