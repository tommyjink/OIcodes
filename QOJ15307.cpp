#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,INF=2e18;
int a,b,c,n,m,dis[N],done[N],lim;
struct Point{int num,dis;};
bool operator <(Point x,Point y){return x.dis>y.dis;}
void dijkstra(int s)
{
    priority_queue<Point> q;
    for(int i=0;i<=b;i++)dis[i]=INF,done[i]=0;
    dis[s]=a;q.push((Point){s,a});
    while(!q.empty())
    {
        Point t=q.top();q.pop();
        if(done[t.num])continue;
        done[t.num]=true;
        for(int i=0;i<=lim;i++)
        {
            int d=(t.dis+i*b)^b;
            int v=d%b;
            if(d<dis[v])
            {
                dis[v]=d;
                q.push((Point){v,d});
            }
        }
    }
}
void solve()
{
    cin>>a>>b>>c;
    lim=1;
    while(lim<=b)lim<<=1;
    dijkstra(a%b);
    if(dis[c%b]<=c)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}