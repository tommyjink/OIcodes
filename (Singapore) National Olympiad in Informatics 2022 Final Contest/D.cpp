#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int tot=0,head[N],f[N][21],dfn[N];
int dep[N],son[N],siz[N],val[N],top[N];
struct node{int to,next,val;}e[N*2];
void add(int x,int y,int z){e[++tot]={y,head[x],z},head[x]=tot;}
void dfs(int x,int fa)
{
    f[x][0]=fa;
    siz[x]=1;
    dep[x]=dep[fa]+1;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        val[v]=val[x]+e[i].val;
        dfs(v,x);
        siz[x]+=siz[v];
        if(siz[v]>siz[son[x]])
            son[x]=v;
    }
}
void dfs2(int x,int tp)
{
    top[x]=tp;
    if(son[x])
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}