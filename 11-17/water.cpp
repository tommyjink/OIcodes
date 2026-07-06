#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1005;
int n,val[N],tot=0,fa[N],cnt=0;
int dp[N][2],g[N];
struct node
{
    int x,y,z;
}e1[N*2];
int head[N],tt=0;
struct node1
{
    int from,to,next,val;
}e[N*2];
void add(int x,int y,int z)
{
    e[++tt]=(node1){x,y,head[x],z};
    head[x]=tt;
}
bool cmp(node x,node y)
{
    return x.z<y.z;
}
int getfa(int x)
{
    if(x==fa[x])return fa[x];
    else return (fa[x]=getfa(fa[x]));
}
bool merge(int x,int y)
{
    x=getfa(x);
    y=getfa(y);
    if(x==y)return false;
    fa[x]=y;
    return true;
}
void dfs(int x,int fa)
{
    dp[x][1]=val[x];
    int num=0;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dfs(v,x);
        g[v]=dp[v][1]+e[i].val;
        dp[x][0]+=min(dp[v][0]+e[i].val,dp[v][1]);
        dp[x][1]+=min(dp[v][0]+e[i].val,dp[v][1]);
        if(!num||g[v]<g[num])num=v;
    }
    if(!num)return;
    int res=g[num];
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa||v==num)continue;
        res+=min(dp[v][0]+e[i].val,dp[v][1]);
    }
    dp[x][1]=min(dp[x][1],res);
}
signed main()
{
    // freopen("water.in","r",stdin);
    // freopen("water.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>val[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int x;
            cin>>x;
            if(i==j)continue;
            e1[++tot]=(node){i,j,x};
        }
    }
    sort(e1+1,e1+1+tot,cmp);
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=tot&&cnt<n-1;i++)
    {
        if(merge(e1[i].x,e1[i].y))
            add(e1[i].x,e1[i].y,e1[i].z),
            add(e1[i].y,e1[i].x,e1[i].z);
    }
    dfs(1,0);
    cout<<dp[1][1]<<endl;
    // for(int i=1;i<=n;i++)
    //     printf("dp[%lld][0]=%lld,dp[%lld][1]=%lld\n",i,dp[i][0],i,dp[i][1]);
    // for(int i=1;i<=cnt;i++)
    //     cout<<E[i].x<<" "<<E[i].y<<" "<<E[i].z<<endl;
    return 0;
}
/*

【样例输入】
4
5
4
4
3
0 2 2 2
2 0 3 3
2 3 0 4
2 3 4 0
【样例输出】
9



【样例输入】
7
3 7 6 2 2 4 1

0 5 7 9 9 9 9
5 0 9 3 1 9 9
7 9 0 9 9 4 5
9 3 9 0 9 9 9
9 1 9 9 0 9 9
9 9 4 9 9 0 9
9 9 5 9 9 9 0

【样例输出】
9
*/