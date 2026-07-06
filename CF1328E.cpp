#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10;
int n,m,tot=0,head[N],dep[N],b[N],k,f[N][30];
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
    dep[x]=dep[fa]+1;
    f[x][0]=fa;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dfs(v,x);
    }
}
bool cmp(int x,int y)
{
    return dep[x]>dep[y];
}
int lca(int x,int y)
{
    if(dep[x]<dep[y])swap(x,y);
    for(int i=29;i>=0;i--)
        if(dep[f[x][i]]>=dep[y])
            x=f[x][i];
    if(x==y)return x;
    for(int i=29;i>=0;i--)
        if(f[x][i]!=f[y][i])
            x=f[x][i],y=f[y][i];
    return f[x][0];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    dfs(1,1);
    for(int i=1;i<=29;i++)
        for(int j=1;j<=n;j++)
            f[j][i]=f[f[j][i-1]][i-1];
    while(m--)
    {
        cin>>k;
        for(int i=1;i<=k;i++)
            cin>>b[i],b[i]=f[b[i]][0];
        sort(b+1,b+1+k,cmp);
        int tag=1;
        for(int i=2;i<=k;i++)
            if(lca(b[i-1],b[i])!=b[i])
                tag=0;
        if(tag)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}