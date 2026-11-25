#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=4e5+10,INF=1e16;
int n,m1,m2,a[N],done[N];
int dis1[N],dis2[N];
vector<pii> g1[N],g2[N];
struct info{int num,dis;};
bool operator <(info x,info y){return x.dis>y.dis;}
set<info> s;
void dijkstra(int s,vector<pii> *g,int *dis)
{
    // cout<<s<<">>"<<endl;
    for(int i=1;i<=n;i++)
        dis[i]=INF,done[i]=0;
    dis[s]=0;
    priority_queue<info> q;
    q.push({s,0});
    while(!q.empty())
    {
        info t=q.top();q.pop();
        if(done[t.num])continue;
        done[t.num]=true;
        for(auto [v,val]:g[t.num])
        {
            if(done[v])continue;
            // cout<<v<<"!!"<<endl;
            if(dis[t.num]+val<dis[v])
            {
                dis[v]=dis[t.num]+val;
                q.push({v,dis[v]});
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m1>>m2;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m1;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        g1[x].push_back({y,z});
        g1[y].push_back({x,z});
    }
    for(int i=1;i<=m2;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        g2[x].push_back({y,z});
        g2[y].push_back({x,z});
    }
    dijkstra(1,g1,dis1);
    dijkstra(n,g2,dis2);
    // for(int i=1;i<=n;i++)
    //     cout<<dis1[i]<<" "<<dis2[i]<<endl;
    for(int i=1;i<=n;i++)
        s.insert({i,dis1[i]+dis2[i]*2*a[i]});
    int t;cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        auto p=s.find({x,dis1[x]+dis2[x]*2*a[x]});
        s.erase(p);
        a[x]=y;
        s.insert({x,dis1[x]+dis2[x]*2*a[x]});
        cout<<(prev(s.end())->dis)<<endl;
    }
    return 0;
}