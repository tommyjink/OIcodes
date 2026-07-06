#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5005,INF=1e16;
int n,m,k,head[N],tot=0,in[N];
int dis1[N],way1[N],way2[N],dis2[N];
double E[N];
struct node
{
    int to,next;
}e[N*20];
void add(int x,int y)
{
    e[++tot]=(node){y,head[x]};
    head[x]=tot;
}
void bfs(int s,int *dis,int *way)
{
    queue<int> q;
    for(int i=1;i<=n;i++)
        dis[i]=INF,way[i]=0,in[i]=0;
    way[s]=1,dis[s]=0;
    in[s]=1,q.push(s);
    while(!q.empty())
    {
        int x=q.front();q.pop();
        for(int i=head[x];i;i=e[i].next)
        {
            int v=e[i].to;
            if(dis[x]+1<dis[v])
            {
                dis[v]=dis[x]+1;
                way[v]=way[x];
                if(!in[v])q.push(v),in[v]=1;
            }
            else if(dis[x]+1==dis[v])
                way[v]+=way[x];
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        x++,y++;
        add(x,y);
        add(y,x);
    }
    // bfs(1,dis,way);
    // for(int i=1;i<=n;i++)
    //     cout<<dis[i]<<" ";
    // cout<<endl;
    // for(int i=1;i<=n;i++)
    //     cout<<way[i]<<" ";
    // cout<<endl;
    cin>>k;
    for(int i=1;i<=k;i++)
    {
        int x,y;
        cin>>x>>y;
        x++,y++;
        bfs(y,dis2,way2);
        bfs(x,dis1,way1);
        // for(int j=1;j<=n;j++)
        //     cout<<dis1[j]<<" ";
        // cout<<endl;
        // for(int j=1;j<=n;j++)
        //     cout<<dis2[j]<<" ";
        // cout<<endl;
        if(!way1[y])continue;
        for(int j=1;j<=n;j++)
            if(dis1[j]+dis2[j]==dis1[y])
                E[j]+=(double(way1[j])*double(way2[j]))/double(way1[y]);
    }
    // for(int i=1;i<=n;i++)
    //     cout<<E[i]<<" ";
    // cout<<endl;
    int ans=1;
    for(int i=1;i<=n;i++)
        if(E[i]>E[ans])ans=i;
    // for(int i=1;i<=n;i++)
    //     cout<<i<<":"<<E[i]<<endl;
    cout<<ans-1<<endl;
    return 0;
}
/*

15 19
0 3
1 3
1 4
1 5
2 5
3 6
3 7
4 7
5 7
6 10
7 9
7 10
7 11
8 11
9 12
9 13
10 13
11 13
11 14

2
4 10
3 8
*/