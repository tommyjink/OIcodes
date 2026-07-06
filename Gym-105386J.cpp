#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e6+10,INF=1e16;
int n,m,k,head[N],tot=0;
int a[N],b[N],done[N],p[N];
struct node1{int c,l;}dis[N];
struct Point{int num;node1 dis;};
struct node{int to,next;node1 val;}e[N*4];
bool operator <(node1 x,node1 y)
{
    return x.c==y.c?x.l<y.l:x.c<y.c;
}
bool operator <(Point x,Point y)
{
    return !(x.dis<y.dis);
}
void add(int x,int y,node1 z)
{
    e[++tot]=(node){y,head[x],z};
    head[x]=tot;
}
priority_queue<Point> q;
void dijkstra(int s)
{
    for(int i=1;i<=n;i++)dis[i]={INF,INF},done[i]=0;
    q.push({s,{1,0}});
    dis[s]={1,0};
    while(!q.empty())
    {
        Point t=q.top();q.pop();
        if(done[t.num])continue;
        done[t.num]=true;
        for(int i=head[t.num];i;i=e[i].next)
        {
            int v=e[i].to;
            if(done[v])continue;
            node1 disv=t.dis;
            if(t.dis.c<e[i].val.c)disv=e[i].val;
            else if(t.dis.c>e[i].val.c)continue;
            else if(t.dis.l+e[i].val.l>b[t.dis.c])continue;
            else disv.l=t.dis.l+e[i].val.l;
            if(disv<dis[v])
            {
                dis[v]=disv;
                q.push((Point){v,dis[v]});
            }
        }
    }
}
void solve()
{
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int x,y,c,l;
        cin>>x>>y>>c>>l;
        add(x,y,{c,l});
    }
    for(int i=1;i<=k;i++)
        cin>>a[i]>>b[i];
    dijkstra(1);
    for(int i=1;i<=n;i++)cout<<dis[i].c<<","<<dis[i].l<<endl;
    for(int i=1;i<=n;i++)
    {
        if(dis[i].c<INF)cout<<"1";
        else cout<<"0";
    }
    cout<<endl;
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