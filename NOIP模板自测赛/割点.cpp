#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
struct node
{
    int to,next;
}e[N*4];
int n,m,head[N],tot=0,cut[N];
int dfn[N],low[N],num=0;
void add(int x,int y)
{
    e[++tot]=(node){y,head[x]};
    head[x]=tot;
}
void dfs(int x,int fa,int root)
{
    dfn[x]=low[x]=++num;
    int cnt=0;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        if(!dfn[v]){
            dfs(v,x,root);
            low[x]=min(low[x],low[v]);
            cnt++;
            if(x!=root && low[v]>=dfn[x])cut[x]=true;
        }
        else low[x]=min(low[x],dfn[v]);
    }
    if(x==root&&cnt>1)cut[x]=true;
}
void tarjan()
{
    for(int i=1;i<=n;i++)
        if(!dfn[i])dfs(i,0,i);
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
    tarjan();
    int ans=0;
    for(int i=1;i<=n;i++)
        ans+=cut[i];
    cout<<ans<<endl;
    for(int i=1;i<=n;i++)
        if(cut[i])cout<<i<<" ";
    return 0;
}
/*
8 9
1 2
1 3
1 7
7 8
2 4
2 5
3 4
3 6
4 6
*/