#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,col[N];
int head[N],tot=0,a[N],ans[N];
struct node
{
    int to,next;
}e[N*2];
void add(int x,int y)
{
    e[++tot]=(node){y,head[x]};
    head[x]=tot;
}
void dfs(int x,int fa)
{
    if(col[x])a[x]=1;
    else a[x]=-1;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dfs(v,x);
        if(a[v]>=0)a[x]+=a[v];
    }
}
void dfs1(int x,int fa,int val)
{
    ans[x]=a[x];
    if(val>=0)ans[x]+=val;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        if(a[v]>=0)
            dfs1(v,x,max(max(val,0ll)+a[x]-a[v],-1ll));
        else dfs1(v,x,max(max(val,0ll)+a[x],-1ll));
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>col[i];
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    dfs(1,0);
    dfs1(1,0,0);
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    return 0;
}