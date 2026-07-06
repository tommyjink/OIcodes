#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,INF=1e16;
int n,a[4],h,tot,head[N],dis[N],done[N];
struct node{int to,next,val;}e[N*10];
struct Point{int num,dis;};
bool operator <(Point x,Point y){return x.dis>y.dis;}
void add(int x,int y,int z)
{
    e[++tot]=(node){y,head[x],z};
    head[x]=tot;
}
void dijkstra(int s)
{
    priority_queue<Point> q;
    for(int i=1;i<=n;i++)dis[i]=INF,done[i]=0;
    dis[s]=0;q.push((Point){s,0});
    while(!q.empty())
    {
        Point t=q.top();q.pop();
        if(done[t.num])continue;
        done[t.num]=true;
        for(int i=head[t.num];i;i=e[i].next)
        {
            int v=e[i].to;
            if(done[v])continue;
            if(t.dis+e[i].val<dis[v])
            {
                dis[v]=t.dis+e[i].val;
                q.push((Point){v,dis[v]});
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>h>>a[1]>>a[2]>>a[3];
    sort(a+1,a+4);
    n=a[1];
    for(int i=0;i<a[1];i++)
    {   
        for(int j=1;j<=3;j++)
        {
            add(i+1,(i+a[j])%a[1]+1,a[j]);
        }
    }
    dijkstra(0+1);
    int ans=0;
    for(int i=0;i<a[1];i++)
    {
        // cout<<dis[i+1]<<" ";
        if(dis[i+1]==INF)continue;
        if(h<dis[i+1])continue;
        ans+=(h-dis[i+1]+a[1]-1)/a[1];
    }
    cout<<ans<<endl;
    return 0;
}