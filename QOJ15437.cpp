#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e6+10;
int n,m,k,p[N],rk[N],dfn[N],low[N],tot=0,col[N],stk[N],top=0;
int cnt=0,rem=0,in[N],nxt[N],U[N],V[N];
bool use[N];
vector<pii> e;
vector<int> g[N],rg[N];
void solve1()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        e.push_back({x,y});
    }
    cin>>k;
    int cnt=0;
    for(int i=1;i<=k;i++)
        cin>>p[i],rk[p[i]]=++cnt;
    for(int i=1;i<=n;i++)
        if(!rk[i])rk[i]=++cnt;
    for(auto &i:e)if(rk[i.first]>rk[i.second])swap(i.first,i.second);
    for(auto i:e)
        if(i.first==p[1]&&i.second==p[k])cout<<p[k]<<" "<<p[1]<<endl;
        else cout<<i.first<<" "<<i.second<<endl;
}
void tarjan(int x)
{
    dfn[x]=low[x]=++tot;
    stk[top++]=x;
    for(auto id:g[x])
    {
        int v=V[id];
        if(!dfn[v])tarjan(v),low[x]=min(low[x],low[v]);
        else if(!col[v])low[x]=min(low[x],dfn[v]);
    }
    if(dfn[x]==low[x])
    {
        cnt++;
        int cc=0;
        while(1)
        {
            int t=stk[--top];
            col[t]=cnt;
            cc++;
            if(t==x)break;
        }
        if(cc>1)rem=cnt;
    }
}
void solve2()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>U[i]>>V[i];
        g[U[i]].push_back(i);
        rg[V[i]].push_back(i);
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i])tarjan(i);
    int sz=0,now=0;
    for(int i=1;i<=n;i++)
        if(col[i]==rem)
            sz++,now=i;
    for(int i=1;i<=m;i++)
        if(col[U[i]]==rem&&col[V[i]]==rem)
            use[i]=1,in[V[i]]++;
    queue<int> q;
    for(int i=1;i<=n;i++)
        if(col[i]==rem&&in[i]==1)
            q.push(i);
    while(!q.empty())
    {
        int t=q.front();q.pop();
        if(in[t]!=1)continue;
        int id=0;
        for(auto j:rg[t])
            if(use[j])
            {
                id=j;
                break;
            }
        if(!id)continue;
        int u=U[id];
        if(nxt[u])continue;
        nxt[u]=t;
        for(auto j:g[u])
        {
            if(!use[j]||j==id)continue;
            use[j]=0;
            int v=V[j];
            in[v]--;
            if(in[v]==1)q.push(v);
        }
    }
    for(int i=1;i<=sz;i++)
    {
        cout<<now<<" ";
        now=nxt[now];
    }
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int op;
    cin>>op;
    if(op==1)solve1();
    else solve2();
    return 0;
}