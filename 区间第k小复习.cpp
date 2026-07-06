#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 100000;
int a[N], b[N], ls[N], rs[N], sum[N], cnt = 0, root[N];
int clone(int node)
{
    cnt++;
    ls[cnt] = ls[node];
    rs[cnt] = rs[node];
    sum[cnt] = sum[node];
    return cnt;
}
int build(int l, int r)
{
    int node=++cnt;
    if (l == r)
        return node;
    int mid = (l + r) >> 1;
    ls[node] = build(l, mid);
    rs[node] = build(mid + 1, r);
    return node;
}
int update(int node, int pl, int pr, int x)
{
    node = clone(node);
    sum[node]++;
    if (pl == pr)
        return node;
    int mid = (pl + pr) >> 1;
    if (x <= mid)
        ls[node] = update(ls[node], pl, mid, x);
    if (x > mid)
        rs[node] = update(rs[node], mid + 1, pr, x);
    return node;
}
int query(int pre, int node, int pl, int pr, int k)
{
    // printf("pl:%lld,pr:%lld\n",pl,pr);
    if(pl==pr)
        return b[pl];
    int lssum=sum[ls[node]]-sum[ls[pre]];
    // printf("lssum:%lld\n",lssum);
    int mid=(pl+pr)>>1;
    if(lssum>=k)
        return query(ls[pre],ls[node],pl,mid,k);
    else
        return query(rs[pre],rs[node],mid+1,pr,k-lssum);
}
signed main()
{
    int n, m; // n个数，m个询问
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        b[i] = a[i];
    }
    root[0] = build(1, n);
    sort(b + 1, b + 1 + n);
    int size = unique(b + 1, b + 1 + n) - b - 1;
    for (int i = 1; i <= n; i++)
    {
        int nw = lower_bound(b + 1, b + 1 + size, a[i]) - b;
        root[i] = update(root[i - 1], 1, size, nw);
    }
    for (int i = 1; i <= m; i++)
    {
        int l,r,k;
        scanf("%lld%lld%lld",&l,&r,&k);
        printf("ANS=%lld\n", query(root[l-1],root[r],1,size,k));
    }
    return 0;
}
/*
10 10
1 3 5 6 7 8 9 10 13 14
*/