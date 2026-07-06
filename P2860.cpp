#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,tot=0,head[N],dfn[N],low[N],num=0;
int in[N],cnt=0,col[N],cc[N];
stack<int> st;
vector<int> g[N];
map<pii,int> mp;
struct node
{
    int to,next,from;
}e[N*2];
void add(int x,int y)
{
    e[++tot]={y,head[x],x};
    head[x]=tot;
}
void tarjan(int x,int fa)
{
    dfn[x]=low[x]=++num;
    in[x]=true,st.push(x);
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        if(!dfn[v])tarjan(v,x),low[x]=min(low[x],low[v]);
        else if(in[v])low[x]=min(low[x],dfn[v]);
    }
    if(dfn[x]==low[x])
    {
        cnt++;
        while(!st.empty())
        {
            int v=st.top();
            st.pop();
            in[v]=false;
            col[v]=cnt;
            if(v==x)break;
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
        int x,y;
        cin>>x>>y;
        if(mp.count(pii(x,y)))continue;
        mp[pii(x,y)]=1;
        mp[pii(y,x)]=1;
        add(x,y);
        add(y,x);
    }
    tarjan(1,0);
    // for(int i=1;i<=n;i++)
    //     cout<<col[i]<<" ";
    // cout<<endl;
    for(int i=1;i<=tot;i++)
    {
        int x=e[i].from,y=e[i].to;
        if(col[x]!=col[y])
            g[col[x]].push_back(col[y]),cc[col[x]]++;
    }
    int ans=0;
    for(int i=1;i<=cnt;i++)
        if(cc[i]==1)ans++;
    // cout<<ans<<endl;
    cout<<(ans+1)/2<<endl;
    return 0;
}