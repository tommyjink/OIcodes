#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
struct node
{
    int to,next,from;
}e[N*4];
int n,m,tot=0,num=0,cnt=0;
int head[N],col[N],dfn[N],low[N],a[N],val[N],in[N],dp[N];
vector<int> E[N],V;
stack<int> st;
void add(int x,int y)
{
    e[++tot]=(node){y,head[x],x};
    head[x]=tot;
}
void dfs(int x)
{
    dfn[x]=low[x]=++num;
    st.push(x);
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(!dfn[v])dfs(v),low[x]=min(low[x],low[v]);
        else if(!col[v])low[x]=min(low[x],dfn[v]);
    }
    if(low[x]==dfn[x])
    {
        cnt++;
        while(!st.empty())
        {
            int t=st.top();
            st.pop();
            col[t]=cnt;
            val[cnt]+=a[t];
            if(t==x)break;
        }
    }
}
void tarjan()
{
    for(int i=1;i<=n;i++)
        if(!dfn[i])dfs(i);
}
void topo()
{
    queue<int> q;
    for(int i=1;i<=cnt;i++)
        if(!in[i])q.push(i);
    while(!q.empty())
    {
        int t=q.front();q.pop();
        V.emplace_back(t);
        for(auto v:E[t])
            if(!--in[v])q.push(v);
    }
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
    // return 0;
    tarjan();
    for(int i=1;i<=tot;i++)
        if(col[e[i].from]!=col[e[i].to])
            E[col[e[i].from]].emplace_back(col[e[i].to]),in[col[e[i].to]]++;
    topo();
    int ans=0;
    for(auto x:V)
    {
        dp[x]=max(dp[x],val[x]);
        for(auto v:E[x])
        {
            dp[v]=max(dp[v],dp[x]+val[v]);
        }
        ans=max(ans,dp[x]);
    }
    cout<<ans<<endl;
    return 0;
}