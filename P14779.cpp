#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e6+5;
int n,m,tot=0,cnt=0;
int head[N],deg[N],match[N],f[N],pre[N],inc[N];
bool vis[N];
vector<int> edge[N],tpx;
struct node
{
    int from,to,next;
}e[N*2];
void add(int x,int y)
{
    e[++tot]=(node){x,y,head[x]};
    head[x]=tot;
}
void topo()
{
    queue<int> q;
    for(int i=1;i<=2*n;i++)
        if(!inc[i])q.push(i);
    while(!q.empty())
    {
        int t=q.front();q.pop();
        tpx.push_back(t);
        for(int i=0;i<edge[t].size();i++)
        {
            int v=edge[t][i];
            if(--inc[v]==0)q.push(v);
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        add(u,v);
        add(v,u);
        deg[u]++,deg[v]++;
    }
    queue<int> q;
    for(int i=1;i<=2*n;i++)
        if(deg[i]==1)q.push(i);
    while(!q.empty())
    {
        int u=q.front();q.pop();
        if(match[u])continue;
        for(int i=head[u];i;i=e[i].next)
        {
            int v=e[i].to;
            if(!match[v])
            {
                match[u]=v,match[v]=u;
                for(int j=head[v];j;j=e[j].next)
                {
                    int to=e[j].to;
                    if(!match[to]&&--deg[to]==1)q.push(to);
                }
                break;
            }
        }
    }
    for(int u=1;u<=2*n;u++)
    {
        for(int i=head[u];i;i=e[i].next)
        {
            int v=e[i].to;
            if(v!=match[u])
                edge[u].push_back(match[v]),inc[match[v]]++;
        }
    }
    topo();
    int s=1;
    for(int i=1;i<=2*n;i++)f[i]=1;
    for(int i=0;i<tpx.size();i++)
    {
        int u=tpx[i];
        if(f[u]>f[s])s=u;
        for(int j=0;j<edge[u].size();j++)
        {
            int v=edge[u][j];
            if(f[u]+1>f[v])
                f[v]=f[u]+1,pre[v]=u;
        }
    }
    vector<int> res;
    int cur=s;
    while(cur)
    {
        res.push_back(cur);
        cur=pre[cur];
    }
    reverse(res.begin(),res.end());
    cout<<res.size()*2<<endl;
    for(int i=0;i<res.size();i++)
    {
        int u=res[i];
        cout<<match[u]<<" "<<u<<" ";
    }
    cout<<endl;
    return 0;
}