#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=3010;
const int P=1e9+7;
int n,tot=0;
int head[N],sz[N],ans[N];
int dp[N][N],tmp[N],f[N],g[N];
struct node
{
    int to,next;
}e[N*2];
void add(int x,int y)
{
    e[++tot]=(node){y,head[x]};
    head[x]=tot;
}
void dfs(int u,int fa)
{
    sz[u]=1;
    for(int i=0;i<=n;i++)dp[u][i]=0;
    dp[u][0]=1;
    for(int i=head[u];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dfs(v,u);
        for(int j=0;j<=sz[u]+sz[v];j++)tmp[j]=0;
        for(int j=0;j<sz[u];j++)
        {
            if(!dp[u][j])continue;
            for(int k=0;k<=sz[v];k++)
            {
                if(!dp[v][k])continue;
                tmp[j+k]=(tmp[j+k]+dp[u][j]*dp[v][k])%P;
            }
        }
        sz[u]+=sz[v];
        for(int j=0;j<sz[u];j++)dp[u][j]=tmp[j];
    }
    dp[u][1]=(dp[u][1]+1)%P;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    for(int r=1;r<=n;r++)
    {
        for(int i=0;i<=n;i++)f[i]=0;
        f[0]=1;
        int cur=1;
        for(int i=head[r];i;i=e[i].next)
        {
            int v=e[i].to;
            dfs(v,r);
            for(int j=0;j<=cur+sz[v];j++)g[j]=0;
            for(int j=0;j<cur;j++)
            {
                if(!f[j])continue;
                for(int k=0;k<=sz[v];k++)
                {
                    if(!dp[v][k])continue;
                    g[j+k]=(g[j+k]+f[j]*dp[v][k])%P;
                }
            }
            cur+=sz[v];
            for(int j=0;j<cur;j++)f[j]=g[j];
        }
        for(int k=1;k<=n;k++)
            ans[k]=(ans[k]+f[k-1])%P;
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}