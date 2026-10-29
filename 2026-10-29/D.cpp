#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl "\n"
using namespace std;
const int N=1e6+10,INF=3e18;
int n,m,k,tot=0,head[N],dis[N],bel[N];
struct node
{
    int to,next,val;
}e[N*2];
void add(int x,int y,int z)
{
    e[++tot]=(node){y,head[x],z};
    head[x]=tot;
}
void solve()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        head[i]=bel[i]=0,dis[i]=INF;
    tot=0;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
        add(y,x,z);
    }
    priority_queue<pii,vector<pii>,greater<pii>> q;
    for(int i=1;i<=k;i++)
    {
        int x;
        cin>>x;
        bel[x]=x;
        dis[x]=0;
        q.push({0,x});
    }
    while(!q.empty())
    {
        int x=q.top().second,d=q.top().first;
        q.pop();
        if(d!=dis[x])continue;
        for(int i=head[x];i;i=e[i].next)
        {
            int v=e[i].to;
            if(dis[v]>dis[x]+e[i].val)
            {
                dis[v]=dis[x]+e[i].val;
                bel[v]=bel[x];
                q.push({dis[v],v});
            }
        }
    }
    int ans=INF;
    for(int x=1;x<=n;x++)
        for(int i=head[x];i;i=e[i].next)
        {
            int v=e[i].to;
            if(bel[x]!=bel[v])
                ans=min(ans,dis[x]+dis[v]+e[i].val);
        }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
