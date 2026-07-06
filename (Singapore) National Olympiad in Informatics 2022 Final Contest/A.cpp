#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10,S=32,INF=1e16;
int n,m,k,q,head[N],tot=0,dis[N][S],done[N][S],o[N];
struct node{int to,next,val;}e[N*2];
void add(int x,int y,int z){e[++tot]={y,head[x],z},head[x]=tot;}
struct Point{int num,dis,s;};
bool operator<(Point x,Point y){return x.dis>y.dis;}
void dijkstra(int s,int *P)
{
    priority_queue<Point> q;
    for(int i=1;i<=n;i++)
        for(int j=0;j<S;j++)
            dis[i][j]=INF,done[i][j]=0;
    dis[s][0]=0;
    q.push({s,0,0});
    while(!q.empty())
    {
        Point t=q.top();q.pop();
        if(done[t.num][t.s])continue;
        done[t.num][t.s]=true;
        for(int i=head[t.num];i;i=e[i].next)
        {
            int v=e[i].to;
            if(t.dis+e[i].val<dis[v][t.s])
            {
                dis[v][t.s]=t.dis+e[i].val;
                q.push({v,dis[v][t.s],t.s});
            }
            for(int j=1;j<=5;j++)
            {
                if(P[j]==-1)continue;
                if(t.s&(1ll<<(j-1)))continue;
                int now=t.s|(1ll<<(j-1));
                if(t.dis+e[i].val*(10-j)/10+P[j]<dis[v][now])
                {
                    dis[v][now]=t.dis+e[i].val*(10-j)/10+P[j];
                    q.push({v,dis[v][now],now});
                }
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout<<log2(1e4)<<endl;
    // cout<<1e4*log2(1e4)*32*100<<endl;
    cin>>n>>m>>k;
    for(int i=1;i<=k;i++)cin>>o[i],o[i]++;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        x++,y++;
        add(x,y,z);
    }
    cin>>q;
    while(q--)
    {
        int s,P[6]={0};
        cin>>s>>P[1]>>P[2]>>P[3]>>P[4]>>P[5];s++;
        dijkstra(s,P);
        int ans=INF;
        // for(int i=1;i<=n;i++)
        //     cout<<dis[i][0]<<" ";
        // cout<<endl;
        for(int i=1;i<=k;i++)
            for(int j=0;j<S;j++)
                ans=min(ans,dis[o[i]][j]);
        if(ans==INF)cout<<-1<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}
/*
3 2 1
2
0 1 100
1 2 200
1
0 10 20 1000 2000 -1

280

*/