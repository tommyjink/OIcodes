#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10;
int n,m,a[N],head[N],tot=0;
int dfn[N],low[N],now=0;
int in[N],stk[N],top=0,num;
int col[N],sum[N],dp[N];
vector<int> g[N];
struct node
{
    int to,next,from;
}e[N*2];
void add(int x,int y)
{
    e[++tot]=(node){y,head[x],x};
    head[x]=tot;
}
void tarjan(int x)
{
    dfn[x]=low[x]=++now;
    stk[top++]=x;
    in[x]=true;
    // cout<<x<<" "<<dfn[x]<<" "<<low[x]<<endl;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(!dfn[v])tarjan(v),low[x]=min(low[x],low[v]);
        else if(!col[v])low[x]=min(low[x],dfn[v]);
    }
    if(dfn[x]==low[x])
    {
        num++;
        while(1)
        {
            int t=stk[--top];
            in[t]=false;
            col[t]=num;
            sum[num]+=a[t];
            if(t==x)break;
        }
    }
}
vector<int> topo()
{
    queue<int> q;
    vector<int> res;
    for(int i=1;i<=num;i++)
        if(!in[i])q.push(i);
    while(!q.empty())
    {
        int t=q.front();q.pop();
        res.push_back(t);
        for(int v:g[t])
            if(!--in[v])q.push(v);
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i])tarjan(i);
    // for(int i=1;i<=n;i++)
    //     cout<<col[i]<<" ";
    // cout<<endl;
    for(int i=1;i<=num;i++)
        in[i]=0;
    for(int i=1;i<=tot;i++)
    {
        int x=e[i].from,y=e[i].to;
        if(col[x]!=col[y])
            g[col[x]].push_back(col[y]),in[col[y]]++;
    }
    vector<int> V=topo();
    for(int i=1;i<=num;i++)
        dp[i]=sum[i];
    int ans=0;
    for(int x:V)
    {
        for(int v:g[x])
        {
            dp[v]=max(dp[v],dp[x]+sum[v]);
        }
        ans=max(ans,dp[x]);
    }
    cout<<ans<<endl;

    return 0;
}