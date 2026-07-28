#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e3+10,INF=1e18;
int n,hp[N],ans=0,f[N][N][2],siz[N],nf[N][2];
vector<int> g[N];
void dfs(int x,int fa)
{
    // cout<<x<<endl;
    f[x][0][0]=hp[x];
    f[x][1][1]=0;
    siz[x]=1;
    for(int v:g[x])
    {
        dfs(v,x);
        for(int i=0;i<=siz[x]+siz[v];i++)nf[i][0]=nf[i][1]=INF;
        for(int i=siz[x];i>=0;i--)
        {
            for(int j=siz[v];j>=0;j--)
            {
                nf[i+j][0]=min(nf[i+j][0],
                    f[x][i][0]+min(f[v][j][0]+hp[v],f[v][j][1]));
                nf[i+j][1]=min(nf[i+j][1],
                    f[x][i][1]+min(f[v][j][0],f[v][j][1]));
            }
        }
        for(int i=0;i<=siz[x]+siz[v];i++)f[x][i][0]=nf[i][0],f[x][i][1]=nf[i][1];
        siz[x]+=siz[v];
    }
}
void solve()
{
    ans=0;
    cin>>n;
    memset(f,1,sizeof(f));
    for(int i=1;i<=n;i++)g[i].clear();
    for(int i=2;i<=n;i++)
    {
        int x;cin>>x;
        g[x].push_back(i);
    }
    for(int i=1;i<=n;i++)
        cin>>hp[i];
    dfs(1,0);
    for(int i=0;i<=n;i++)
        cout<<min(f[1][i][0],f[1][i][1])<<" ";
    cout<<endl;
    // for(int i=1;i<=n;i++)
    //     cout<<f[i][0][0]<<" "<<f[i][1][1]<<endl;
    // cout<<f[1][0][0]<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}