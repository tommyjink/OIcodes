#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,INF=1e16;
int n,k,tot,head[N],d[N],ans[N];
string s;
struct node
{
    int to,next;
}e[N*2];
void add(int x,int y)
{
    e[++tot]=(node){y,head[x]};
    head[x]=tot;
}
void dfs1(int x,int fa)
{
    d[x]=(s[x]=='1')?0:INF;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dfs1(v,x);
        d[x]=min(d[x],d[v]+1);
    }
}
void dfs2(int x,int now,int res,int fa)
{
    if(now>=d[x])now=max(now,k-d[x]);
    ans[x]=res+(s[x]=='0');
    if(now==0)now=k,res++;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dfs2(v,now-1,res,x);
    }
}
void solve()
{
    cin>>n>>k>>s;
    tot=0;
    for(int i=1;i<=n;i++)head[i]=0,d[i]=0;
    s=" "+s;
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    dfs1(1,0);
    dfs2(1,k,0,0);
    for(int i=2;i<=n;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}