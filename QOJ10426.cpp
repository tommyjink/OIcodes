#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e6+10;
int n,a[N],fa[N],vis[N];
int tot,head[N],pos[N];
int same[N],mt[N],cnt=0;
vector<int> s,g[N];
vector<pii> ans;
struct node
{
    int to,next;
}e[N*2];
void add(int x,int y)
{
    e[++tot]=(node){y,head[x]};
    head[x]=tot;
}
void dfs(int x)
{
    s.push_back(x);
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa[x])continue;
        fa[v]=x;
        dfs(v);
    }
}
void dfs1(int x,int f,vector<int> &g)
{
    if(!x||vis[x])return;
    vis[x]=true;
    g.push_back(x);
    dfs1(same[x],x,g);
    dfs1(mt[x],x,g);
}
void solve()
{
    cin>>n;
    for(int i=1;i<=2*n;i++)
        fa[i]=same[i]=mt[i]=head[i]=pos[i]=vis[i]=0,
        g[i].clear();
    tot=cnt=0;
    s.clear();
    ans.clear();
    for(int i=1;i<=2*n;i++)
    {
        cin>>a[i];
        if(!pos[a[i]])pos[a[i]]=i;
        else same[i]=pos[a[i]],same[pos[a[i]]]=i;
    }
    for(int i=1;i<2*n;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    dfs(1);
    reverse(s.begin(),s.end());
    for(int now:s)
    {
        if(mt[now]||mt[fa[now]]||now==1)continue;
        mt[now]=fa[now];
        mt[fa[now]]=now;
    }
    for(int i=1;i<=2*n;i++)
        if(!mt[i]&&!vis[i])dfs1(i,0,g[++cnt]);
    for(int i=1;i<=2*n;i++)
        if(!vis[i])dfs1(i,0,g[++cnt]);
    for(int i=1;i<=cnt;i++)
    {
        int m=g[i].size()-1;
        for(int j=0;j<m-j-1;j++)
        {
            // cout<<g[i][j]<<" ";
            ans.push_back({g[i][j],g[i][m-j-1]});
        }
        // cout<<"!"<<endl;
    }
    cout<<ans.size()<<endl;
    for(pii i:ans)cout<<i.first<<" "<<i.second<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}