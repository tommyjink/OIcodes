#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e6+10;
int n,m,q,s,tot=0,vis1[N],vis2[N];
vector<int> g[N],f[N],tim[N],id[N];
vector<pii> r[N];
map<int,int> num[N];
void dfs(int x,vector<int> *g,int *vis,int d)
{
    vis[x]=d;
    for(int v:g[x])
    {
        if(~vis[v])continue;
        dfs(v,g,vis,d);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>s;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        tim[x].push_back(z);
        tim[y].push_back(z);
        r[x].push_back({y,z});
    }
    for(int i=1;i<=n;i++)
    {
        tim[i].push_back(0);
        sort(tim[i].begin(),tim[i].end());
        tim[i].erase(unique(tim[i].begin(),tim[i].end()),tim[i].end());
        int lst=0;
        for(int j:tim[i])
        {
            id[i].push_back(++tot);
            num[i][j]=tot;
            if(lst)g[lst].push_back(tot);
            lst=tot;
        }
    }
    for(int x=1;x<=n;x++)
        for(auto [y,t]:r[x])
            g[num[x][t]].push_back(num[y][t]),
            f[num[y][t]].push_back(num[x][t]);
    memset(vis1,-1,sizeof(vis1));
    memset(vis2,-1,sizeof(vis2));
    for(int t:tim[s])dfs(num[s][t],f,vis1,t);
    reverse(tim[s].begin(),tim[s].end());
    for(int t:tim[s])dfs(num[s][t],g,vis2,t);
    reverse(tim[s].begin(),tim[s].end());
    cin>>q;
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        int l=0,r=tim[y].size()-1,t=vis1[id[x][0]];
        if(t==-1){cout<<-1<<endl;continue;}
        while(l<r)
        {
            int mid=(l+r)>>1;
            if(vis2[id[y][mid]]==-1||vis2[id[y][mid]]<t)l=mid+1;
            else r=mid;
        }
        if(l==tim[y].size())cout<<-1<<endl;
    }
    return 0;
}