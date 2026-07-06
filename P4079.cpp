#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,P=1e9+7;
int n,m,head[N],tot=0,f[N],vis[N];
struct node
{
    int to,next,valx,valy;
}e[N*2];
int mod(int x)
{
    return ((x%P)+P)%P;
}
void add(int x,int y,int z,int zz)
{
    e[++tot]=(node){y,head[x],z,zz};
    head[x]=tot;
}
int qpow(int x,int y)
{
    x%=P;
    int res=1;
    while(y)
    {
        if(y&1)res=res*x%P;
        y>>=1;
        x=x*x%P;
    }
    return res;
}
int F(int x)
{
    return qpow(mod(x),P-2);
}
bool dfs(int x,int fa)
{
    vis[x]=true;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        int val=mod(mod(f[x]*e[i].valy)*mod(F(e[i].valx)));
        if(!vis[v])
        {
            f[v]=val;
            if(!dfs(v,x))return false;
        }
        else if(vis[v])
            if(val!=f[v])return false;
    }
    return true;
}
void solve(int num)
{
    cin>>n>>m;
    tot=0;
    for(int i=1;i<=n;i++)
        head[i]=f[i]=vis[i]=0;
    for(int i=1;i<=m;i++)
    {
        int x,y,z,zz;
        cin>>x>>y>>z>>zz;
        add(x,y,z,zz);
        add(y,x,zz,z);
    }
    int res=1;
    for(int i=1;i<=n;i++)if(!vis[i])f[i]=1,res&=dfs(i,0);
    // for(int i=1;i<=n;i++)cout<<f[i]<<" ";
    // cout<<endl;
    if(res)printf("Case #%lld: Yes\n",num);
    else printf("Case #%lld: No\n",num);

}
signed main()
{
    // freopen("dat3.in","r",stdin);
    // freopen("dat_3.in","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    int num=0;
    while(++num<=t)
        solve(num);
    return 0;
}