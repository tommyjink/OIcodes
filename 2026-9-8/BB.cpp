#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N=1e6+10,INF=1e9;
int n,m,fa[N][22],done[N];
int tot,head[N],dis[N],b[N],cnt=0;
int rt1[N],rt2[N],num=0,dep[N*2];
struct path
{
    int sum,w;
}t[N*4];
struct Point
{
    int num,dis;
};
bool operator <(Point x,Point y)
{
    return x.dis>y.dis;
}
struct node
{
    int to,next,val,id;
}e[N*4];
inline void add(int x,int y,int z,int id)
{
    e[++tot]=(node){y,head[x],z,id};
    head[x]=tot;
}
int addp(int x,int val)
{
    t[++num]=(path){t[x].sum+val,val};
    fa[num][0]=x;
    for(int i=1;i<=20;i++)fa[num][i]=fa[fa[num][i-1]][i-1];
    dep[num]=dep[x]+1;
    return num;
}

priority_queue<Point> q;
inline void dijkstra(int s)
{
    for(int i=1;i<=n;i++)dis[i]=INF;
    dis[s]=0;
    q.push({s,0});
    while(!q.empty())
    {
        Point t=q.top();q.pop();
        if(done[t.num])continue;
        b[++cnt]=t.num;
        done[t.num]=true;
        for(int i=head[t.num];i;i=e[i].next)
        {
            int v=e[i].to;
            if(done[v])continue;
            if(dis[t.num]+e[i].val<dis[v])
            {
                dis[v]=dis[t.num]+e[i].val;
                q.push({v,dis[v]});
            }
        }
    }
}
bool cmp(int x,int y)
{
    int res=0;
    if(dep[x]<dep[y])swap(x,y),res=1;
    for(int i=20;i>=0;i--)
        if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
    if(x==y)return 0^res;
    for(int i=20;i>=0;i--)
        if(fa[x][i]!=fa[y][i])
            x=fa[x][i],y=fa[y][i];
    return (t[x].w<t[y].w)^res;

}
inline void upd(int x,int &rt1,int &rt2)
{
    if(!rt1||cmp(x,rt1))rt2=rt1,rt1=x;
    else if(!rt2||cmp(x,rt2))rt2=x;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z,i);
        add(y,x,z,i);
    }
    dijkstra(1);
    rt1[1]=++num;
    dep[1]=0;
    t[1].sum=0;
    for(int i=1;i<=n;i++)
    {
        int x=b[i];
        for(int j=head[x];j;j=e[j].next)
        {
            int y=e[j].to;
            if(dis[x]+e[j].val!=dis[y])continue;
            int p1=addp(rt1[x],e[j].id);
            upd(p1,rt1[y],rt2[y]);
            if(rt2[x])
            {
                int p1=addp(rt2[x],e[j].id);
                upd(p1,rt1[y],rt2[y]);
            }
        }
    }
    for(int i=1;i<=n;i++)
        if(!rt2[i])cout<<"-1 ";
        else cout<<t[rt2[i]].sum<<" ";
    return 0;
}