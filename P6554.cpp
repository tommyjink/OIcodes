#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e6;
int n, head[N], tot = 0, w[N], cnt[N];
int in[N], root = 1, tag[N], sum[N],f[N];
struct node
{
    int to, next;
} e[N * 2];
void add(int x, int y)
{
    e[++tot] = (node){y, head[x]};
    head[x] = tot;
}
void dfs1(int x, int fa)
{
    for (int i = head[x]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa)
            continue;
        dfs1(v, x);
        cnt[x] += cnt[v];
        sum[x] += sum[v] + cnt[v] * w[x];
    }
    if (tag[x])
        sum[x] = w[x];
}
void dfs2(int x, int fa)
{
    for (int i = head[x]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa)
            continue;
        if(tag[v])
            f[v]=f[x]-w[x]-w[v]+(cnt[root]-1)*w[v];
        else f[v]=f[x]-cnt[v]*w[x]+(cnt[root]-cnt[v])*w[v];
        dfs2(v,x);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        add(x, y), add(y, x);
        in[x]++, in[y]++;
        if (in[x] > 1)
            root = x;
        if (in[y] > 1)
            root = y;
    }
    for (int i = 1; i <= n; i++)
    {
        cin>>w[i];
        cnt[i] = tag[i] = (in[i] == 1);
    }
    dfs1(root,0);
    // cout<<root<<endl;
    // for(int i=1;i<=n;i++)
    //     cout<<cnt[i]<<" ";
    // cout<<endl;
    f[root]=sum[root];
    
    dfs2(root,0);
    double ans=-1e15;
    for(int i=1;i<=n;i++)
        ans=max(ans,f[i]*1.0/double(cnt[root]-tag[i]));
    printf("%.4lf",ans);
    return 0;
}