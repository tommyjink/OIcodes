//扫描线模板
#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e6 + 10;
int n, b[N],ans=0;
struct node
{
    int x1, x2, y, o;
} a[N];
struct Tree
{
    int l, r, v, s;
} t[N * 16];
void pushup(int k)
{
    if(t[k].v)t[k].s=b[t[k].r+1]-b[t[k].l];
    else t[k].s = t[k * 2].s + t[k * 2 + 1].s;
}
void build(int k, int l, int r)
{
    t[k].l = l, t[k].r = r;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(k * 2, l, mid);
    build(k * 2 + 1, mid + 1, r);
}
void add(int k, int l, int r, int d)
{
    if (t[k].l > r || t[k].r < l) return;
    if (l <= t[k].l && t[k].r <= r)
    {
        t[k].v += d;
        pushup(k);
        return;
    }
    add(k * 2, l, r, d);
    add(k * 2 + 1, l, r, d);
    pushup(k);
}
bool cmp(node x, node y)
{
    return x.y < y.y;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, y, xx, yy;
        cin >> x >> y >> xx >> yy;
        a[i] = (node){x, xx, y, 1};
        a[i + n] = (node){x, xx, yy, -1};
        b[i] = x, b[i + n] = xx;
    }
    sort(a + 1, a + 1 + 2 * n, cmp);
    sort(b + 1, b + 1 + 2 * n);
    int tot=unique(b+1,b+1+2*n)-b-1;
    build(1,1,tot);
    for(int i=1;i<=2*n-1;i++)
    {
        a[i].x1=lower_bound(b+1,b+1+tot,a[i].x1)-b;
        a[i].x2=lower_bound(b+1,b+1+tot,a[i].x2)-b;
        // printf("%lld,%lld %lld,%lld\n",a[i].x1,a[i].x2,b[a[i].x1],b[a[i].x2]);
        add(1,a[i].x1,a[i].x2-1,a[i].o);
        // cout<<t[1].s<<endl;
        ans+=t[1].s*(a[i+1].y-a[i].y);
    }
    cout<<ans<<endl;
    return 0;
}