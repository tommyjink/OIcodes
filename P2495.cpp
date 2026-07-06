#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e6+10,INF=1e16;
int n,head[N],tot,m,f[N][21],g[N][21];
int dfn[N],cnt=0,dep[N],tag[N];
vector<pii> v[N];
struct node
{
    int to,next,val;
}e[N*2];
void add(int x,int y,int z)
{
    e[++tot]=(node){y,head[x],z};
    head[x]=tot;
}
void dfs(int x,int fa)
{
    dfn[x]=++cnt;
    f[x][0]=fa;
    dep[x]=dep[fa]+1;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        g[v][0]=e[i].val;
        dfs(v,x);
    }
}
void init()
{
    for(int i=1;i<=20;i++)
    {
        for(int j=1;j<=n;j++)
        {
            f[j][i]=f[f[j][i-1]][i-1];
            g[j][i]=min(g[j][i-1],g[f[j][i-1]][i-1]);
        }
    }
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
int cal(int x,int y)
{
    int o=lca(x,y),res=INF;
    for(int i=20;i>=0;i--)
        if(dep[f[x][i]]>=dep[o])
            res=min(res,g[x][i]),x=f[x][i];
    for(int i=20;i>=0;i--)
        if(dep[f[y][i]]>=dep[o])
            res=min(res,g[y][i]),y=f[y][i];
    return res;
}
void conn(int x,int y)
{
    int val=cal(x,y);
    v[x].push_back(pii(y,val));
    v[y].push_back(pii(x,val));
}
bool cmp(int x,int y)
{
    return dfn[x]<dfn[y];
}
void tree(vector<int> &a)
{
    sort(a.begin(),a.end(),cmp);
    int k=a.size();
    for(int i=1;i<k;i++) a.push_back(lca(a[i-1],a[i]));
    sort(a.begin(),a.end(),cmp);
    a.erase(unique(a.begin(),a.end()),a.end());
    k=a.size();
    for(int i=1;i<k;i++) conn(lca(a[i-1],a[i]),a[i]);
}
void clear(vector<int> &a)
{
    for(auto i:a)v[i].clear(),tag[i]=false;
    a.clear();
}
int dp(int x,int fa)
{
    int res=0;
    for(pii i:v[x])
    {
        int v=i.first,val=i.second;
        if(v==fa)continue;
        if(tag[v])res+=val;
        else res+=min(val,dp(v,x));
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
        add(y,x,z);
    }
    dfs(1,0);
    init();
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        int k;cin>>k;
        vector<int> a;
        for(int i=1;i<=k;i++)
        {
            int x;cin>>x;
            tag[x]=true;
            a.push_back(x);
        }
        a.push_back(1);
        tree(a);
        cout<<dp(1,0)<<endl;
        clear(a);
    }
    return 0;
}