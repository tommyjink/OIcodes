#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e3;
int n,m,vis[N],ans=1e10,now=0;
int head[N],tot=0,col[N];
struct node
{
    int from,to,next;
}e[N*2];
void add(int x,int y)
{
    e[++tot]=(node){x,y,head[x]};
    head[x]=tot;
}
void op(int x)
{
    col[x]^=1;
    if(col[x])now++;
    else now--;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        col[v]^=1;
        if(col[v])now++;
        else now--;
    }
}
void dfs(int x,int fa,int cnt)
{
    if(cnt>ans)return;
    if(now==n)
    {
        ans=min(ans,cnt);
        return;
    }
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa||vis[v])continue;
        vis[v]=true;
        dfs(v,x,cnt);
        op(v),dfs(v,x,cnt+1),op(v);
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
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    vis[1]=true;
    dfs(1,0,0);
    op(1),dfs(1,0,1);
    cout<<ans<<endl;
    return 0;
}