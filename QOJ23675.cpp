#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10,INF=1e12;
int n,m,in[N],tag[N],ans=0;
int head[N],tot,dp[N];
vector<int> l;
struct node
{
    int to,next,from;
}e[N*2];
void add(int x,int y)
{
    e[++tot]=(node){y,head[x],x};
    head[x]=tot;
    in[y]++;
}
void topo()
{
    queue<int> q;
    for(int i=1;i<=n;i++)
        if(!in[i])q.push(i);
    while(!q.empty())
    {
        int t=q.front();q.pop();
        l.push_back(t);
        tag[t]=true;
        ans++;
        for(int i=head[t];i;i=e[i].next)
        {
            int v=e[i].to;
            if(!--in[v])q.push(v);
        }
    }
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        head[i]=in[i]=tag[i]=dp[i]=0;
    tot=ans=0;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
    }
    topo();
    reverse(l.begin(),l.end());
    for(int x:l)
    {
        dp[x]=INF;
        for(int i=head[x];i;i=e[i].next)
        {
            int v=e[i].to;
            dp[x]=min(dp[x],dp[v]+1);
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}