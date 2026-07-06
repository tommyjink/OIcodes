#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+100,INF=1e10;
int n,m;
int head[N],tot=0,ans=INF;
struct node
{
    int from,to,next,val;
}e[N*2];
struct node1
{
    int x,y,val;
}a[N];
bool cmp(node1 x,node1 y)
{
    return x.val<y.val;
}
void add(int x,int y,int z)
{
    e[++tot]=(node){x,y,head[x],z};
    head[x]=tot;
}
void dfs(int x,int fa,int val,int now)
{
    if(val>=ans)return;
    if(x==n)
    {
        ans=min(ans,val);
        return;
    }
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dfs(v,x,val+abs(now-e[i].val),e[i].val);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        cin>>a[i].x>>a[i].y>>a[i].val;
    sort(a+1,a+1+m,cmp);
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        x=a[i].x,y=a[i].y,z=a[i].val;
        add(x,y,z);
        add(y,x,z);
    }
    dfs(1,0,0,0);
    cout<<ans<<endl;
    return 0;
}