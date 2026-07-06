#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6;
int n,m,x,tot=0,head[N],cnt=0,inc[N],val[N],md=0,ans=0;
int dfn[N],low[N],num=0,in[N],col[N],mdis[N],mcnt[N];
vector<int> edge[N],tpx;
map<pair<int,int>,int> mp;
struct node
{
    int to,next;
}e[N*2];
void add(int x,int y)
{
    e[++tot]=(node){y,head[x]};
    head[x]=tot;
}
stack<int> stk;
void tarjan(int x)
{
    dfn[x]=low[x]=++num;
    stk.push(x),in[x]=true;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(!dfn[v])tarjan(v),low[x]=min(low[x],low[v]);
        else if(in[v])low[x]=min(low[x],dfn[v]);
    }
    if(low[x]==dfn[x])
    {
        cnt++;
        while(!stk.empty())
        {
            int t=stk.top();stk.pop();
            in[t]=false,col[t]=cnt;
            val[cnt]++;
            if(t==x)break;
        }
    }
}
void topo()
{
    queue<int> q;
    for(int i=1;i<=cnt;i++)
        if(!inc[i])q.push(i);
    while(!q.empty())
    {
        int t=q.front();q.pop();
        tpx.push_back(t);
        for(auto i:edge[t])
            if(--inc[i]==0)
                q.push(i);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>x;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        if(mp.count(make_pair(x,y)))
            continue;
        mp[make_pair(x,y)]=true;
        add(x,y);
    }
    mp.clear();
    for(int i=1;i<=n;i++)
        if(!dfn[i])tarjan(i);
    for(int x=1;x<=n;x++)
    {
        for(int i=head[x];i;i=e[i].next)
        {
            int v=e[i].to;
            if(col[x]!=col[v])
            {
                if(mp.count(make_pair(col[x],col[v])))
                    continue;
                mp[make_pair(col[x],col[v])]=true;
                edge[col[x]].push_back(col[v]),
                inc[col[v]]++;
            }
        }
    }
    topo();
    for(auto u:tpx)
    {
        if(mdis[u]<val[u])
            mdis[u]=val[u],mcnt[u]=1;
        for(auto v:edge[u])
        {
            if(mdis[v]==mdis[u]+val[v])
                mcnt[v]=(mcnt[v]+mcnt[u])%x;
            else if(mdis[v]<mdis[u]+val[v])
                mcnt[v]=mcnt[u];
            mdis[v]=max(mdis[v],mdis[u]+val[v]);
        }
        if(ans==mdis[u])
            md=(md+mcnt[u])%x;
        else if(ans<mdis[u])
            md=mcnt[u],ans=mdis[u];
    }
    cout<<ans<<endl<<md<<endl;
    return 0;
}