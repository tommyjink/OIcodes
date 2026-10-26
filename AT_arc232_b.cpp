#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=4e6+10,INF=1e16;
int n,a[N],b[N],pl[N],pr[N];
int tot,head[N],now,dis[N],done[N];
vector<int> c[N];
struct node
{
    int to,next,from,val;
}e[N*2];
void add(int x,int y,int z)
{
    e[++tot]=(node){y,head[x],x,z};
    head[x]=tot;
}
struct Point
{
    int num,dis;
};
bool operator <(Point x,Point y)
{
    return x.dis>y.dis;
}
void dijkstra(int s)
{
    priority_queue<Point> q;
    for(int i=1;i<=now;i++)
        dis[i]=INF,done[i]=0;
    dis[s]=0;
    q.push({s,0});
    while(!q.empty())
    {
        Point t=q.top();q.pop();
        if(done[t.num])continue;
        done[t.num]=true;
        for(int i=head[t.num];i;i=e[i].next)
        {
            int v=e[i].to;
            if(done[v])continue;
            if(dis[v]>dis[t.num]+e[i].val)
            {
                dis[v]=dis[t.num]+e[i].val;
                q.push({v,dis[v]});
            }
        }
    }
}
int rev(int x)
{
    if(x<=n)return x+n;
    return x-n;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=6*n;i++)
        head[i]=0,c[i].clear();
    tot=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        c[a[i]].push_back(i);
        c[b[i]].push_back(i+n);
    }
    now=2*n;
    for(int i=1;i<=2*n;i++)
    {
        int lst=0;
        for(int j:c[i])
        {
            pl[j]=lst;
            add(lst,++now,0);
            add(j,now,0);
            lst=now;
        }
        lst=0;
        for(int jj=c[i].size()-1;jj>=0;jj--)
        {
            int j=c[i][jj];
            pr[j]=lst;
            add(lst,++now,0);
            add(j,now,0);
            lst=now;
        }
        for(int j:c[i])
        {
            if(pl[j])add(pl[j],rev(j),1);
            if(pr[j])add(pr[j],rev(j),1);
        }
    }
    dijkstra(1);
    if(dis[2+n]<1e9)cout<<dis[2+n]<<endl;
    else cout<<"-1"<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}