#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6;
int n,m,k,q,b[10],tag[N];
int head[N],tot=0,dis[N][N],done[N];
queue<int> sav;
struct node
{
    int from,to,next,val,num;
}e[N*2];
void add(int x,int y,int z,int num)
{
    e[++tot]=(node){x,y,head[x],z,num};
    head[x]=tot;
}
void dijkstra(int s)
{
    queue<int> q;
    q.push(s);
    sav.push(s);
    dis[s][s]=0;
    while(!q.empty())
    {
        int t=q.front();q.pop();
        if(done[t])continue;
        done[t]=true;
        for(int i=head[t];i;i=e[i].next)
        {
            int v=e[i].to,val=e[i].val,num=e[i].num;
            if(done[v])continue;
            if(dis[t]+val<dis[v])
                dis[s][v]=dis[s][t]+val,
                sav.push(v);
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dis,127,sizeof(dis));
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z,i);
        add(y,x,z,i);
    }
    for(int i=1;i<=n;i++)
    {
        memset(done,0,sizeof(done));
        dijkstra(i);
        for(int j=1;j<=n;j++)
            printf("dis[%lld][%lld]=%lld\n",i,j,dis[i][j]);
    }
    // cin>>q;
    // while(q--)
    // {
    //     cin>>k;
    //     for(int i=1;i<=k;i++)
    //     {
    //         cin>>b[i];
    //         tag[b[i]]=true;
    //     }
    // }
    return 0;
}