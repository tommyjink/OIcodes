#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl "\n"
using namespace std;
const int N=2e5+10,INF=4e18;
struct node{int x,y,z;};
int n,m,dep[N];
signed fa[N][21],mx0[N][21],mx1[N][21];
vector<node> e,e2;
vector<pii> g[N];
bool cmp(node x,node y){return x.z<y.z;}
struct DSU
{
    int fa[N];
    void init(){for(int i=1;i<=n;i++)fa[i]=i;}
    int get(int x){return x==fa[x]?x:fa[x]=get(fa[x]);}
}d;
void add(int x,int y,int z)
{
    g[x].push_back({y,z});
    g[y].push_back({x,z});
}
void dfs(int x,int f)
{
    queue<int> q;
    q.push(x);
    dep[x]=1;
    fa[x][0]=f;
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(pii i:g[u])
        {
            int v=i.first,val=i.second;
            if(v==fa[u][0])continue;
            dep[v]=dep[u]+1;
            fa[v][0]=u;
            if(val&1)mx1[v][0]=val;
            else mx0[v][0]=val;
            q.push(v);
        }
    }
}
void init()
{
    for(int i=1;i<=20;i++)
        for(int j=1;j<=n;j++)
            fa[j][i]=fa[fa[j][i-1]][i-1];
    for(int i=1;i<=20;i++)
        for(int j=1;j<=n;j++)
            mx0[j][i]=max(mx0[j][i-1],mx0[fa[j][i-1]][i-1]),
            mx1[j][i]=max(mx1[j][i-1],mx1[fa[j][i-1]][i-1]);
}
int lca(int x,int y)
{
    if(dep[x]<dep[y])swap(x,y);
    for(int i=20;i>=0;i--)
        if(dep[fa[x][i]]>=dep[y])
            x=fa[x][i];
    if(x==y)return x;
    for(int i=20;i>=0;i--)
        if(fa[x][i]!=fa[y][i])
            x=fa[x][i],y=fa[y][i];
    return fa[x][0];
}
int query0(int x,int y)
{
    int d=dep[lca(x,y)],res=-1;
    for(int i=20;i>=0;i--)
        if(dep[fa[x][i]]>=d)
            res=max(res,(long long)mx0[x][i]),x=fa[x][i];
    for(int i=20;i>=0;i--)
        if(dep[fa[y][i]]>=d)
            res=max(res,(long long)mx0[y][i]),y=fa[y][i];
    return res;
}
int query1(int x,int y)
{
    int d=dep[lca(x,y)],res=-1;
    for(int i=20;i>=0;i--)
        if(dep[fa[x][i]]>=d)
            res=max(res,(long long)mx1[x][i]),x=fa[x][i];
    for(int i=20;i>=0;i--)
        if(dep[fa[y][i]]>=d)
            res=max(res,(long long)mx1[y][i]),y=fa[y][i];
    return res;
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)g[i].clear();
    for(int i=0;i<=n;i++)dep[i]=0;
    for(int i=0;i<=n;i++)
        for(int j=0;j<21;j++)
            fa[i][j]=0,mx1[i][j]=mx0[i][j]=-1;
    d.init();
    e.clear(),e2.clear();
    for(int i=1;i<=m;i++)
    {
        int x,y,z;cin>>x>>y>>z;
        e.push_back({x,y,z});
    }
    sort(e.begin(),e.end(),cmp);
    int ans[2]={INF,INF},cnt=0,sum=0;
    for(auto now:e)
    {
        int x=d.get(now.x),y=d.get(now.y);
        if(x!=y)d.fa[x]=y,add(now.x,now.y,now.z),sum+=now.z,cnt++;
        else e2.push_back(now);
    }
    if(cnt<n-1)
    {
        cout<<"-1 -1"<<endl;
        return;
    }
    dfs(1,0);
    init();
    ans[sum&1]=sum;
    for(auto now:e2)
    {
        if(now.z&1)
        {
            int tmp=query0(now.x,now.y);
            if(tmp!=-1)ans[(sum&1)^1]=min(ans[(sum&1)^1],sum-tmp+now.z);
        }
        else
        {
            int tmp=query1(now.x,now.y);
            if(tmp!=-1)ans[(sum&1)^1]=min(ans[(sum&1)^1],sum-tmp+now.z);
        }
    }
    for(int i=0;i<2;i++)
        if(ans[i]==INF)ans[i]=-1;
    cout<<ans[0]<<" "<<ans[1]<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}
