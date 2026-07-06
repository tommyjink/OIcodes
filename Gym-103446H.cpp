#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;
const int N=3e5+10;
int n,m,q,a[N],tot,head[N],fa[N],val[N];
int dep[N],f[N][21],sum[N],lim[N],st[N][21];
struct node{int to,next;}e[N*2];
void add(int x,int y){e[++tot]={y,head[x]},head[x]=tot;}
int getfa(int x){return x==fa[x]?x:fa[x]=getfa(fa[x]);}
struct node1{int x,y,z;}g[N];
bool cmp(node1 x,node1 y){return x.z<y.z;}
void kruskal()
{
    int cnt=n;
    sort(g+1,g+1+m,cmp);
    for(int i=1;i<=2*n-1;i++)fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        int x=getfa(g[i].x),y=getfa(g[i].y);
        if(x==y)continue;
        fa[x]=fa[y]=++cnt;
        val[cnt]=g[i].z;
        add(cnt,x),add(cnt,y);
    }
}
void dfs(int x)
{
    if(x==2*n-1)dep[x]=1;
    if(x<=n)sum[x]=a[x];
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        dep[v]=dep[x]+1;
        f[v][0]=x;
        dfs(v);
        sum[x]+=sum[v];
    }
}
void init()
{
    for(int i=1;i<=20;i++)
        for(int j=1;j<=2*n-1;j++)
            f[j][i]=f[f[j][i-1]][i-1];
    for(int i=1;i<=2*n-1;i++)
        lim[i]=val[f[i][0]]-sum[i];
    for(int i=1;i<=2*n-1;i++)
        st[i][0]=lim[i];
    for(int i=1;i<=20;i++)
        for(int j=1;j<=2*n-1;j++)
            st[j][i]=max(st[j][i-1],st[f[j][i-1]][i-1]);
}
int cal(int x,int k)
{
    for(int i=20;i>=0;i--)
        if(f[x][i]!=0&&st[x][i]<=k)
            x=f[x][i];
    return k+sum[x];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)   
        cin>>g[i].x>>g[i].y>>g[i].z;
    kruskal(),dfs(2*n-1),init();
    while(q--)
    {
        int x,k;
        cin>>x>>k;
        cout<<cal(x,k)<<endl;
    }
    return 0;
}