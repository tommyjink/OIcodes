#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=3510,M=130,P=1e9+7,INF=1e16;
int n,k,p,w[N];
int tot=0,head[N];
int val[N],deg[N];
int dp[N][M],cnt[N][M],siz[N];
int ans=-INF;
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
    dp[x][1]=val[x];
    cnt[x][1]=1;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dfs(v,x);
        for(int t=min(k,siz[x]);t>=1;t--)
        {
            for(int j=min(k-t,siz[v]);j>=1;j--)
            {
                int tmp=dp[x][t]+dp[v][j];
                if(tmp>dp[x][j+t])
                {
                    dp[x][j+t]=tmp;
                    if(j+t==k)ans=max(ans,tmp);
                    cnt[x][j+t]=cnt[x][t]*cnt[v][j]%P;
                }
                else if(tmp==dp[x][j+t])
                    cnt[x][j+t]=(cnt[x][j+t]+cnt[x][t]*cnt[v][j]%P)%P;
            }
        }
        siz[x]+=siz[v];
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k>>p;
    for(int i=1;i<=n;i++)
        cin>>w[i];
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
        deg[x]++,deg[y]++;
    }
    for(int i=1;i<=n;i++)
        val[i]=w[i]-p*deg[i];
    for(int i=1;i<=n;i++)
        for(int j=0;j<=k;j++)
            dp[i][j]=-INF;
    dfs(1,0);
    int num=0;
    for(int i=1;i<=n;i++)
        if(dp[i][k]==ans)num=(num+cnt[i][k])%P;
    cout<<ans+2*p*(k-1)<<" "<<num<<endl;
    return 0;
}