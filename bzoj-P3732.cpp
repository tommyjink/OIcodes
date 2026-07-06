//https://hydro.ac/p/bzoj-P3732
#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,k,fa[N],val[N],tot=0,head[N],f[N][21];
int dep[N];
struct node1{int x,y,z;}q[N];
struct node{int to,next;}e[N*2];
void add(int x,int y){e[++tot]={y,head[x]},head[x]=tot;}
bool cmp(node1 x,node1 y){return x.z<y.z;}
int getfa(int x){return x==fa[x]?x:fa[x]=getfa(fa[x]);}
void kruskal()
{
    sort(q+1,q+1+m,cmp);
    int cnt=n;
    for(int i=1;i<=2*n-1;i++)fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        int x=getfa(q[i].x),y=getfa(q[i].y);
        if(x==y)continue;
        fa[x]=fa[y]=++cnt;
        val[cnt]=q[i].z;
        // cout<<x<<","<<y<<","<<cnt<<endl;
        add(cnt,x),add(x,cnt);
        add(cnt,y),add(y,cnt);
    }
}
void dfs(int x,int lst)
{
    f[x][0]=lst,dep[x]=dep[lst]+1;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==lst)continue;
        dfs(v,x);
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
        if(f[x][i]!=f[y][i])
            x=f[x][i],y=f[y][i];
    return f[x][0];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
        cin>>q[i].x>>q[i].y>>q[i].z;
    kruskal(),dfs(2*n-1,0),init();
    for(int i=1;i<=k;i++)
    {
        int x,y;cin>>x>>y;
        cout<<val[lca(x,y)]<<endl;
    }
    return 0;
}