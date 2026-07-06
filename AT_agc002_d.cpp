#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,head[N],tot=0,fa[N*2],val[N];
int f[N][21],dep[N];
struct node{int to,next;}e[N*2];
struct node1{int x,y,z;}q[N];
bool cmp(node1 x,node1 y){return x.z<y.z;}
void add(int x,int y){e[++tot]={y,head[x]},head[x]=tot;}
int getfa(int x){return x==fa[x]?x:fa[x]=getfa(fa[x]);}
void kruskal()
{
    int cnt=n;
    sort(q+1,q+1+m,cmp);
    for(int i=1;i<=2*n-1;i++)fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        int x=getfa(q[i].x),y=getfa(q[i].y);
        if(x==y)continue;
        fa[x]=fa[y]=++cnt;
        val[cnt]=q[i].z;
        add(cnt,x),add(cnt,y);
    }
}
void dfs(int x)
{
    if(x==2*n-1)dep[x]=1;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        f[v][0]=x,dep[v]=dep[x]+1;
        dfs(v);
    }
}
void init()
{
    for(int i=1;i<=20;i++)
        for(int j=1;j<=2*n-1;j++)
            f[j][i]=f[f[j][i-1]][i-1];
}   
int lca(int x,int y)
{
    if(dep[x]<dep[y])swap(x,y);
    for(int i=20;i>=0;i--)
        if(dep[f[x][i]]>=dep[y])
            x=f[x][i];
    if(x==y)return x;
    for(int i=20;i>=0;i--)
        if()
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        cin>>q[i].x>>q[i].y>>q[i].z;
    while(q--)
    {

    }
    return 0;
}