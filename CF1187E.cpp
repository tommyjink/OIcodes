#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,head[N],tot=0,f[N],siz[N];
int dp[N],sum[N];
struct node
{
    int to,next;
}e[N*2];
void add(int x,int y)
{
    e[++tot]=(node){y,head[x]};
    head[x]=tot;
}
void dfs(int x,int fa)
{
    siz[x]=1;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dfs(v,x);
        siz[x]+=siz[v];
        f[x]+=f[v];
        sum[x]+=f[v];
    }
    f[x]+=siz[x];
}
void dfs1(int x,int fa)
{
    dp[x]=siz[1];
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dfs1(v,x);
        dp[x]=max(dp[x],dp[v]+siz[1]-siz[v]+sum[x]-f[v]);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    dfs(1,0);
    dfs1(1,0);
    // for(int i=1;i<=n;i++)
    //     cout<<dp[i]<<" ";
    // cout<<endl;
    cout<<dp[1]<<endl;
    return 0;
}