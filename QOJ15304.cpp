#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,dep1[N],dep2[N],tag[N],fa1[N],fa2[N],fa3[N];
int maxdep[N],dep[N],deg[N],val[N],cnt=0,mn[N];
vector<int> g[N],g1[N],ans;
void dfs(int x,int *dep,int *fa,int &y)
{
    dep[x]=dep[fa[x]]+1;
    if(dep[x]>dep[y])y=x;
    for(int v:g[x])
    {
        if(v==fa[x])continue;
        fa[v]=x;
        dfs(v,dep,fa,y);
    }
}
void dfs1(int x,int *fa,int l)
{
    maxdep[x]=dep[x]=dep[fa[x]]+1;
    for(int v:g1[x])
    {
        if(v==fa[x])continue;
        fa[v]=x;
        dfs1(v,fa,l);
        maxdep[x]=max(maxdep[x],maxdep[v]);
    }
    if(maxdep[x]==l)tag[x]=true;
    for(int v:g1[x])
        if(v!=fa[x]&&tag[v])deg[x]++;
    if(tag[x]&&!deg[x])cnt++;
}
void dfs2(int x,int fa,int now)
{
    int vv=0;
    for(auto v:g1[x])
    {
        if(v==fa||!tag[v])continue;
        if(!vv||deg[v]<deg[vv])vv=v;
    }
    if(deg[vv])
    {
        ans.push_back(now+deg[x]-1);
        dfs2(vv,x,now+deg[x]);
    }
    else
    {
        ans.push_back(deg[x]);
        return;
    }
}
void bfs(int rt,int now,int *fa)
{
    queue<int> q;
    q.push(rt);
    mn[1]=deg[rt];
    while(!q.empty())
    {
        int t=q.front();q.pop();
        if(deg[t]>mn[dep[t]])continue;
        for(auto v:g1[t])
        {
            if(v==fa[t]||!tag[v])continue;
            mn[dep[v]]=min(mn[dep[v]],deg[v]);
            q.push(v);
        }
    }
    for(int i=1;mn[i];i++)
    {
        if(mn[i+1])
        {
            ans.push_back(now+mn[i]-1);
            now+=mn[i];
        }
        else
        {
            ans.push_back(mn[i]);
        }
    }
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n+1;i++)
        tag[i]=fa1[i]=fa2[i]=fa3[i]=deg[i]=val[i]=0,g[i].clear(),g1[i].clear(),mn[i]=n+1;
    ans.clear(),cnt=0;
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int x=0,y=0,rt=0,l=0,h=0;
    dfs(1,dep1,fa1,x);
    dfs(x,dep2,fa2,y);
    int now=y;
    vector<int> v;
    v.push_back(y);
    while(y!=x)y=fa2[y],v.push_back(y);
    if(v.size()&1)
    {
        rt=v[v.size()/2];
        for(int i=1;i<=n;i++)
            g1[i]=g[i];
        h=l=v.size()/2+1;
    }
    else 
    {
        rt=n+1;
        int xx=v[v.size()/2-1],yy=v[v.size()/2];
        for(int i=1;i<=n;i++)
            for(int j:g[i])
                if(!((i==xx&&j==yy)||(i==yy&&j==xx)))
                    g1[i].push_back(j);
        g1[rt].push_back(xx);
        g1[rt].push_back(yy);
        l=v.size()/2+1;
        h=l-1;
    }
    dfs1(rt,fa3,l);
    /*
    for(int i=1;i<=n;i++)
        g1[i].clear();
    for(int i=1;i<=n;i++)
        for(auto v:g[i])
            if(v<=n&&tag[i]&&tag[v])
                g1[i].push_back(v),
                g1[v].push_back(i);
    */
    for(int i=cnt;i<=cnt+h-1;i++)
        ans.push_back(i);
    deg[rt]--;
    // dfs2(rt,0,cnt+h);
    bfs(rt,cnt+h,fa3);
    for(int i:ans)cout<<i<<" ";
    cout<<endl;
}   
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}