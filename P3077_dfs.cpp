#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,r,a[N],ans=0;
int head[N],tot=0,f[2][N*2];
struct node
{
    int from,to,next;
}e[N*2];
void add(int x,int y)
{
    e[++tot]=(node){x,y,head[x]};
    head[x]=tot;
}
inline int dfs(int lnum,int mode)
{
    if(f[mode][lnum])
        return f[mode][lnum];
    int fa=e[lnum].from;
    int x=e[lnum].to;
    int res=a[x];
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(mode&&v<=fa)continue;
        else if(v>=fa)continue;
        if(f[mode][i])res=max(res,f[mode][i]);
        else res=max(res,dfs(i,mode));
    }
    f[mode][lnum]=res+a[fa];
    return f[mode][lnum];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>r;
    for(int i=1;i<=n;i++)
        cin>>a[i],ans=max(ans,a[i]);
    for(int i=1;i<=m;i++)
        cin>>a[i+n],ans=max(ans,a[i+n]);
    for(int i=1;i<=r;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y+n);
        add(y+n,x);
    }
    for(int i=1;i<=tot;i++)
        ans=max({ans,dfs(i,1),dfs(i,0)});
    cout<<ans<<endl;
    return 0;
}