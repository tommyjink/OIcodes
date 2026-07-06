#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+100,M=50;
int n,m,head[N],tot=0,dep[N],f[N][M+10];
int siz[N],sup[N];
struct node
{
    int from,to,next;
}e[N*2];
void add(int x,int y)
{
    e[++tot]=(node){x,y,head[x]};
    head[x]=tot;
}
void dfs(int x,int fa)
{
    dep[x]=dep[fa]+1;
    f[x][0]=fa;
    siz[x]=1;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dfs(v,x);
        siz[x]+=siz[v];
    }
}
void dfs2(int x,int fa)
{
    sup[x]=siz[1];
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dfs2(v,x);
        sup[x]-=siz[v];
    }
}
void init()
{
    for(int j=1;j<=M;j++)
        for(int i=1;i<=n;i++)
            f[i][j]=f[f[i][j-1]][j-1];
}
int cal(int x,int d)
{
    for(int i=M;i>=0;i--)
        if((1ll<<i)<=d)
            d-=(1ll<<i),x=f[x][i];
    return x;
}
int lca(int x,int y)
{
    if(dep[x]<dep[y])swap(x,y);
    for(int i=M;i>=0;i--)
        if(dep[f[x][i]]>=dep[y])
            x=f[x][i];
    if(x==y)return y;
    for(int i=M;i>=0;i--)
        if(f[x][i]!=f[y][i])
            x=f[x][i],y=f[y][i];
    return f[x][0];
}
int dis(int x,int y)
{
    if(dep[x]<dep[y])
        swap(x,y);
    int o=lca(x,y);
    if(o==y)return dep[x]-dep[y];
    else return dep[x]-2*dep[o]+dep[y];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    dfs(1,0);
    dfs2(1,0);
    init();
    cin>>m;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        if(dep[x]<dep[y])
            swap(x,y);
        int d=dis(x,y);
        if(d&1)
        {
            cout<<"0"<<endl;
            continue;
        }
        if(x==y)
        {
            cout<<siz[1]<<endl;
            continue;
        }
        // cout<<d<<endl;
        int z=cal(x,d/2);
        int aa=cal(x,d/2-1),bb;
        if(dep[x]==dep[y])
            bb=cal(y,d/2-1);
        else bb=f[z][0];
        int res=siz[1];
        if(aa==f[z][0])res-=sup[z]-1;
        else res-=siz[aa];
        if(bb==f[z][0])res-=sup[z]-1;
        else res-=siz[bb];
        // cout<<aa<<" "<<bb<<endl;
        // cout<<z<<" "<<res<<endl;
        cout<<res<<endl;
    }
    return 0;
}