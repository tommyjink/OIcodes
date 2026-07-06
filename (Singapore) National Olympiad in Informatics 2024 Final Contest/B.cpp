#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,col[N],now=0,vis[N];
vector<int> g[N];
struct node{int x,y,z;}e[N*2];
bool cmp(node x,node y){return x.z<y.z;}
struct DSU
{
    int fa[N],siz[N];
    void init(int n){for(int i=1;i<=n;i++)fa[i]=i,siz[i]=1;}
    int getfa(int x){return x==fa[x]?x:fa[x]=getfa(fa[x]);}
    bool merge(int x,int y)
    {
        x=getfa(x),y=getfa(y);
        if(x==y)return false;
        if(siz[x]==1)now++;
        if(siz[y]==1)now++;
        fa[y]=x,siz[x]+=siz[y];
        return true;
    }
}d;
void dfs(int x,int fa)
{
    vis[x]=true;
    col[x]=col[fa]^1;
    for(auto v:g[x])
    {
        if(v==fa)continue;
        dfs(v,x);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        cin>>e[i].x>>e[i].y>>e[i].z;
    sort(e+1,e+1+m,cmp);
    d.init(n);
    for(int i=1;i<=m;i++)
    {
        int x=e[i].x,y=e[i].y,z=e[i].z;
        if(!d.merge(x,y))continue;
        g[x].push_back(y);
        g[y].push_back(x);
        if(now==n)
        {
            for(int i=1;i<=n;i++)
                if(!vis[i])dfs(i,0);
            cout<<z<<endl;
            for(int i=1;i<=n;i++)
                if(col[i]==1)cout<<"B";
                else cout<<"D";
            return 0;
        }
    }
    return 0;
}