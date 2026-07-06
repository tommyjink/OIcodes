#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,val[N],fa[N],vis[N],dp[N][2];
int tot=-1,head[N],ban[N*4];
vector<int> rt;
struct node
{
    int to,next,from;
}e[N*4];
void add(int x,int y)
{
    e[++tot]=(node){y,head[x],x};
    head[x]=tot;
}
int getfa(int x)
{
    if(x==fa[x])return fa[x];
    else return (fa[x]=getfa(fa[x]));
}
void merge(int x,int y)
{
    x=getfa(x);
    y=getfa(y);
    if(x==y)return;
    fa[x]=y;
}
int dfs(int x,int from)
{
    // cout<<"!"<<x<<"!"<<endl;
    vis[x]=true;
    for(int i=head[x];~i;i=e[i].next)
    {
        int v=e[i].to;
        if((i^1)==from)continue;
        if(vis[v])return i;
        int res=dfs(v,i);
        if(res!=-1)return res;
    }
    return -1;
}
void dfs1(int x,int fa)
{
    dp[x][0]=0;
    dp[x][1]=val[x];
    for(int i=head[x];~i;i=e[i].next)
    {
        int v=e[i].to;
        if(ban[i]||v==fa)continue;
        dfs1(v,x);
        dp[x][1]+=dp[v][0];
        dp[x][0]+=max(dp[v][0],dp[v][1]);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        head[i]=-1;
    for(int i=1;i<=n;i++)
        fa[i]=i;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>val[i]>>x;
        add(i,x);
        add(x,i);
        merge(x,i);
    }
    int ans=0;
    for(int x=1;x<=n;x++)
    {
        if(getfa(x)!=x)continue;
        int res=dfs(x,tot+5);
        // if(res==-1)cout<<"-1";
        int p1=e[res].from,p2=e[res].to;
        ban[res]=ban[res^1]=1;
        dfs1(p1,0);
        int res1=dp[p1][0];
        dfs1(p2,0);
        int res2=dp[p2][0];
        ans+=max(res1,res2);
    }
    cout<<ans<<endl;

    return 0;
}
/*
10

10 2
20 3
30 1
10 5
20 4
10 7
20 8
30 9
20 6
10 6

*/