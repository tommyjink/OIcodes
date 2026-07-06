#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e6 + 10;
int n, a[N], m, prime[N], cnt = 0, d[N], f[N], vis[N];
struct node
{
    int l, r, mx, sum;
} t[N * 4];
void pushup(int k)
{
    t[k].sum = t[k * 2].sum + t[k * 2 + 1].sum;
    t[k].mx = max(t[k * 2].mx, t[k * 2 + 1].mx);
}
void build(int k, int l, int r)
{
    t[k].l = l;
    t[k].r = r;
    if (l == r)
    {
        t[k].mx = t[k].sum = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(k * 2, l, mid);
    build(k * 2 + 1, mid + 1, r);
    pushup(k);
}
void update(int k, int l, int r)
{
    if (t[k].mx <= 2||t[k].r<l||t[k].l>r)
        return;
    if(t[k].l==t[k].r)
    {
        t[k].mx=t[k].sum=d[t[k].mx];
        return;
    }
    update(k * 2, l, r);
    update(k * 2 + 1, l, r);
    pushup(k);
}
int query(int k, int l, int r)
{
    if(t[k].l>r||t[k].r<l)return 0;
    if (l <= t[k].l && t[k].r <= r)
        return t[k].sum;
    return query(k * 2, l, r) + query(k * 2 + 1, l, r);
}
void init()
{
    d[1] = f[1] = 1;
    for (int i = 2; i < N; i++)
    {
        if (!vis[i])
        {
            prime[++cnt] = i;
            d[i] = 2;
            f[i] = 1;
        }
        for (int j = 1; j <= cnt && i * prime[j] < N; j++)
        {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0)
            {
                f[i*prime[j]]=f[i]+1;
                d[i*prime[j]]=d[i]*(f[i*prime[j]]+1)/(f[i]+1);
                break;
            }
            f[i*prime[j]]=1;
            d[i*prime[j]]=d[i]*d[prime[j]];
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    init();
    build(1, 1, n);
    while (m--)
    {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 1)
        { 
            update(1, l, r);
        }
        else
        {
            cout<<query(1, l, r)<<endl;
        } 
    }
    return 0;
}