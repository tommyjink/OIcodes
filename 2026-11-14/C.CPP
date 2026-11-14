#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=2e5+10;
map<int,int> mp[N];
int n,m,fa[N],u[N],d[N];
int vis[N],rt[N],cnt=0;
struct node{int a,b,c,d;};
vector<int> g[N];
vector<node> ans;
void repo(){cout<<"No"<<endl;exit(0);}
void dfs1(int x)
{
    if(mp[x].count(fa[x]))u[x]=true;
    if(mp[fa[x]].count(x))d[x]=true;
    vis[x]=true;
    for(int v:g[x])
    {
        if(vis[v])continue;
        fa[v]=x;
        dfs1(v);
    }
}
void dfs(int x)
{
    vis[x]=true;
    vector<int> a,b;
    for(int v:g[x])
    {
        if(vis[v])continue;
        dfs(v);
        if(u[v])a.push_back(v);
        if(d[v])b.push_back(v);
    }
    // cout<<x<<"!"<<endl;
    // for(int i:a)cout<<i<<",";
    // cout<<endl;
    // for(int i:b)cout<<i<<",";
    // cout<<endl;
    while(!a.empty()&&!b.empty())
    {
        ans.push_back({a.back(),x,x,b.back()});
        a.pop_back();
        b.pop_back();
    }

    // cout<<x<<"!"<<endl;
    // for(int i:a)cout<<i<<",";
    // cout<<endl;
    // for(int i:b)cout<<i<<",";
    // cout<<endl;
    if(a.size()+b.size()>1)repo();
    if(!a.empty())
    {
        if(!u[x])repo();
        u[x]=0;
        ans.push_back({a.back(),x,x,fa[x]});
    }
    if(!b.empty())
    {
        if(!d[x])repo();
        d[x]=0;
        // cout<<x<<"???"<<endl;
        ans.push_back({fa[x],x,x,b.back()});
    }
}
signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
        mp[x][y]=1;
    }
    for(int i=1;i<=n;i++)
        if(!vis[i])dfs1(i),rt[++cnt]=i;
    for(int i=1;i<=n;i++)
        vis[i]=0;
    for(int i=1;i<=cnt;i++)
        dfs(rt[i]);
    cout<<"Yes"<<endl;
    for(auto [a,b,c,d]:ans)
        cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    return 0;
}