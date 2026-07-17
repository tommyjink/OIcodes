#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=3010;
int n,head[N],tot,dp[N][N],g[N],siz[N],son[N];
int ans;
struct node
{
    int to,next;
}e[N*2];
void add(int x,int y)
{
    e[++tot]=(node){y,head[x]};
    head[x]=tot;
}
bool check(int now)
{
    
}
void dfs(int x,int fa)
{
    siz[x]=1;
    son[x]=0;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        son[x]++;
        dfs(v,x);
        siz[x]+=siz[v];
    }
    for(int i=1;i<=n;i++)g[i]=dp[x][i];
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        for(int j=1;j<=n;j++)
        {
            if(j-son[v]>0)
                dp[x][j]=min(dp[x][j],dp[v][j-son[v]]+siz[v]);
        }
    }
    for(int i=1;i<=n;i++)
        swap(g[i],dp[x][i]);
    for(int i=1;i<=n;i++)ans=min(ans,g[i]);
}
int find()
{
    int l=1,r=n;
    while(l<r)
    {
        int mid=(l+r+1)>>1;
        if(check(mid))l=mid;
        else r=mid-1;
    }
    return l;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}