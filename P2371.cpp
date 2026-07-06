#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,INF=1e16;
int n,l,r,a[N],tot=0,head[N];
int dis[N],done[N];
struct node
{
    int to,next,val;
}e[N*10];
struct Point
{
    int num,dis;
};
bool operator >(Point x,Point y)
{
    return x.dis>y.dis;
}
priority_queue<Point,vector<Point>,greater<Point>> q;
void add(int x,int y,int z)
{
    // cout<<x-1<<","<<y-1<<" "<<z<<endl;
    e[++tot]=(node){y,head[x],z};
    head[x]=tot;
}
void dijkstra(int s)
{
    for(int i=1;i<=a[1];i++)
        dis[i]=INF;
    q.push((Point){s,0});
    dis[s]=0;
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
int cal(int l)
{
    int res=0;
    for(int i=0;i<a[1];i++)
    {
        if(l<dis[i])continue;
        res+=(l-dis[i])/a[1]+1;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    cin>>m>>l>>r;
    for(int i=1;i<=m;i++)
    {
        int x;cin>>x;
        if(x)a[++n]=x;
    }
    sort(a+1,a+1+n);

    for(int i=0;i<a[1];i++)
    {
        for(int j=1;j<=n;j++)
        {
            int x=(i+a[j])%a[1];
            add(i+1,x+1,a[j]);
            // cout<<i<<"!"<<x<<":"<<a[j]<<endl;
        }
    }
    dijkstra(0+1);
    for(int i=0;i<a[1];i++)dis[i]=dis[i+1];
    // for(int i=0;i<a[1];i++)cout<<dis[i]<<" ";
    // cout<<endl;
    // for(int i=1;i<=20;i++)
    //     cout<<i<<":"<<cal(i)<<endl;
    cout<<cal(r)-cal(l-1)<<endl;
    return 0;
}