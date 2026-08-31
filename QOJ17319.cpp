#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10;
vector<int> g[N],V;
int n,deg[N],d[N];
int head[N],tot=0,vis[N];
struct node
{
    int from,to,next,val;
}e[N*2];
void add(int x,int y,int z)
{
    e[++tot]=(node){x,y,head[x],z};
    head[x]=tot;
}
void adde(int x,int y,int z)
{
    add(x,y,z);
    add(y,x,-z);
}
int dfs(int x,int fa)
{
    sort(g[x].begin(),g[x].end());
    deg[x]=g[x].size();
    int res=0;
    for(int i=0;i<g[x].size();i++)
    {
        int v=g[x][i];
        if(v==fa){res=i;continue;}
        int cnt=dfs(v,x);
        int w=0;
        if(v<x)w=deg[v]-cnt;
        else w=-cnt;
        adde(v,x+n,w);
        if(v>x)w=deg[x]-i;
        else w=-i;
        adde(x,v+n,w);
    }
    return res;
}
void dfs1(int x)
{
    // cout<<x<<" "<<d[x]<<endl;
    V.push_back(x);
    vis[x]=true;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(vis[v])continue;
        // cout<<x<<"-"<<v<<":"<<e[i].val<<endl;
        int val=e[i].val;
        d[v]=d[x]+val;
        dfs1(v);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0);
    for(int i=1;i<=2*n;i++)
    {
        if(vis[i])continue;
        V.clear();
        dfs1(i);
        int mn=1e18;
        for(auto j:V)mn=min(mn,d[j]);
        for(auto j:V)d[j]=d[j]-mn+n;
    }
    for(int i=1;i<=n;i++)
        cout<<d[i]<<" ";
    return 0;
}