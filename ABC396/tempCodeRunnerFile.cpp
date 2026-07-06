#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=100;
int n,m,vis[N],ans=1e17;
int head[N],tot=0;
struct node
{
    int from,to,next,val;
}e[N*2];
void add(int x,int y,int z)
{
    e[++tot]=(node){x,y,head[x],z};
    head[x]=tot;
}
void dfs(int x,int val)
{
    if(x==n)
    {
        ans=min(ans,val);
        return ;
    }
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(vis[v])continue;
        vis[v]=true;
        dfs(v,val^e[i].val);
        vis[v]=false;
    }
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
        add(x,y,z);
        add(y,x,z);
    }
    vis[1]=true;
    dfs(1,0);
    cout<<ans<<endl;
    return 0;
}