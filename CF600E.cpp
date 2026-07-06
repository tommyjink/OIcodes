#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,head[N],tot=0;
int son[N],siz[N];
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
    siz[x]=1;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dfs(v,x);
        siz[x]+=siz[v];
    }
}
void dfs1(int x,int fa)
{
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}