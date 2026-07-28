#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e7+10,INF=1e18;
int a,b,c,L,lim=1,dis[N];
vector<pii> g[N];
int gcd(int x,int y){return y==0?x:gcd(y,x%y);}
int lcm(int x,int y){return x/gcd(x,y)*y;}
void dijkstra(int s)
{
    deque<int> q;
    q.push_back(s);
    dis[s]=0;
    while(!q.empty())
    {
        int t=q.front();q.pop_front();
        for(auto [v,val]:g[t])
        {
            if(dis[v]>dis[t]+val)
            {
                dis[v]=dis[t]+val;
                if(val==0)q.push_front(v);
                else q.push_back(v);
            }
        }
    }
}

void solve()
{
    cin>>a>>b>>c;
    lim=1;
    while(lim<=b)lim<<=1;
    L=lcm(lim,b);
    for(int i=0;i<L;i++)
    {
        g[i].clear();
        if(i+b>=L)g[i].push_back({(i+b)%L,1});
        else g[i].push_back({(i+b)%L,0});
        g[i].push_back({i^b,0});
        dis[i]=INF;
    }
    dijkstra(a%L);
    if(dis[c%L]<=c/L-a/L)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}