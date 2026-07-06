#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10,M=500,INF=1e15;
int n,head[N],tot=0,siz[N];
vector<int> f[N][2];
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
    vector<int> ff[2];
    f[x][0].resize(2);
    f[x][1].resize(2);
    f[x][0][0]=f[x][1][0]=INF;
    f[x][0][1]=1,f[x][1][1]=2;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dfs(v,x);
        ff[0]=ff[1]=vector<int>(min(siz[x]+siz[v],M)+1,INF);
        for(int j=1;j<=min(siz[x],M);j++)
        {
            for(int k=1;k<=min(siz[v],M);k++)
            {
                if(j+k<M)
                    ff[0][j+k]=min(ff[0][j+k],f[x][0][j]+f[v][0][k]+j*k),
                    ff[1][j+k]=min(ff[1][j+k],f[x][1][j]+f[v][1][k]+2*j*k);
                ff[0][j]=min(ff[0][j],f[x][0][j]+f[v][1][k]);
                ff[1][j]=min(ff[1][j],f[x][1][j]+f[v][0][k]);
            }
        }
        f[x][0]=ff[0];
        f[x][1]=ff[1];
        vector<int>().swap(f[v][0]);
        vector<int>().swap(f[v][1]);
        siz[x]+=siz[v];
    }
}
void solve()
{
    cin>>n;
    tot=0;
    for(int i=1;i<=n;i++)
        head[i]=0;
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    dfs(1,0);
    int ans=INF;
    for(int i:f[1][0])ans=min(ans,i);
    for(int i:f[1][1])ans=min(ans,i);
    cout<<n*(n+1)-ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}