#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10,MOD=1e9+7;
int n,m,head[N],tot=0,siz[N];
vector<int> f[N][4];
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
    for(int i=0;i<4;i++) f[x][i].resize(2,0);
    f[x][0][1]=1;
    f[x][2][0]=1;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dfs(v,x);
        vector<int> ff[4];
        int lim=min(siz[x]+siz[v],m);
        for(int k=0;k<4;k++) ff[k].resize(lim+1,0);
        for(int j=0;j<=min(siz[x],m);j++)
        {
            for(int k=0;k<=min(siz[v],m);k++)
            {
                if(j+k>m) break;
                int u0=f[x][0][j], u1=f[x][1][j], u2=f[x][2][j], u3=f[x][3][j];
                int v0=f[v][0][k], v1=f[v][1][k], v2=f[v][2][k], v3=f[v][3][k];
                if(u0)
                {
                    ff[0][j+k]=(ff[0][j+k]+u0*((v2+v3)%MOD))%MOD;
                    ff[1][j+k]=(ff[1][j+k]+u0*((v0+v1)%MOD))%MOD;
                }
                if(u1)
                    ff[1][j+k]=(ff[1][j+k]+u1*((v0+v1+v2+v3)%MOD))%MOD;
                if(u2)
                {
                    ff[2][j+k]=(ff[2][j+k]+u2*v3)%MOD;
                    ff[3][j+k]=(ff[3][j+k]+u2*v1)%MOD;
                }
                if(u3)
                    ff[3][j+k]=(ff[3][j+k]+u3*((v1+v3)%MOD))%MOD;
            }
        }
        for(int k=0;k<4;k++) f[x][k]=ff[k];
        for(int k=0;k<4;k++) vector<int>().swap(f[v][k]);
        siz[x]=min(siz[x]+siz[v],m);
    }
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    dfs(1,0);
    int ans=0;
    if(m<f[1][1].size()) ans=(ans+f[1][1][m])%MOD;
    if(m<f[1][3].size()) ans=(ans+f[1][3][m])%MOD;
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}