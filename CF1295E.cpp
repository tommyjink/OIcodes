#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 2e5 + 10;
int n, lazy[N*4], p[N], a[N], b[N];
struct node
{
    int l, r, minval;
} t[N * 4];
void pushup(int k)
{
    t[k].minval = min(t[k * 2].minval, t[k * 2 + 1].minval);
}
void pushdown(int k)
{
    if (lazy[k])
    {
        t[k*2].minval += lazy[k];
        t[k*2+1].minval += lazy[k];
        lazy[k * 2] += lazy[k];
        lazy[k * 2 + 1] += lazy[k];
        lazy[k] = 0;
    }
}
void build(int k, int l, int r)
{
    t[k].l = l;
    t[k].r = r;
    if (l == r)
    {
        t[k].minval = b[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(k * 2, l, mid);
    build(k * 2 + 1, mid + 1, r);
    pushup(k);
}
void add(int k, int l, int r, int x)
{
    if (t[k].l > r || t[k].r < l)
        return;
    if (t[k].l >= l && t[k].r <= r)
    {
        t[k].minval += x;
        lazy[k] += x;
        return;
    }
    pushdown(k);
    add(k * 2, l, r, x);
    add(k * 2 + 1, l, r, x);
    pushup(k);
}
int query(int k, int l, int r)
{
    if (t[k].l > r || t[k].r < l)
        return 1e9;
    if (t[k].l >= l && t[k].r <= r)
        return t[k].minval;
    pushdown(k);
    return min(query(k * 2, l, r), query(k * 2 + 1, l, r));
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    for (int i = 1; i <= n; i++)
        cin >> a[p[i]];
    for (int i = 1; i <= n; i++)
        b[i] = b[i - 1] + a[i];
    build(1, 1, n);
    // while(1)
    // {
    //     int op;
    //     cin>>op;
    //     if(op==1)
    //     {
    //         int x,y,z;
    //         cin>>x>>y>>z;
    //         add(1,x,y,z);
    //     }
    //     else
    //     {
    //         int x,y;
    //         cin>>x>>y;
    //         cout<<query(1,x,y)<<endl;
    //     }
    //     for(int i=1;i<=n;i++)
    //         cout<<query(1,i,i)<<" ";
    //     cout<<endl;
    // }
    int ans = 1e9,now=0;
    // for(int j=1;j<=n;j++)
    //     cout<<query(1,j,j)<<" ";
    // cout<<endl;
    for (int i = 1; i <= n-1; i++)
    {
        add(1, 1, p[i] - 1, a[p[i]]);
        add(1, p[i] , n, -a[p[i]]);
        now+=a[p[i]];
        // for(int j=1;j<=n;j++)
        //     cout<<query(1,j,j)<<" ";
        // cout<<endl;
        ans = min(ans, query(1, 1, n));
        ans=min(ans,now);
    }
    cout << ans << endl;
    return 0;
}