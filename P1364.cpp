#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6;
int n,head[N],tot=0,val[N],root=0,dis[N];
int maxp[N]={1e9},All=0;
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
    dis[x]=val[x];
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dfs(v,x);
        dis[x]+=dis[v];
        maxp[x]=max(maxp[x],dis[v]);
    }
    maxp[x]=max(maxp[x],All-dis[x]);
    if(maxp[x]<maxp[root])root=x;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        val[i]=x,All+=x;
        if(y)add(i,y),add(y,i);
        if(z)add(i,z),add(z,i);
    }
    dfs(1,0);
    cout<<root;
    return 0;
}