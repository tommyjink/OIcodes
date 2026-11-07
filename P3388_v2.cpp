#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,dfn[N],low[N];
int num=0;
int head[N],tot=0,in[N];
int tag[N];
struct node
{
    int to,next,from;
}e[N*2];
void add(int x,int y)
{
    e[++tot]=(node){y,head[x],x};
    head[x]=tot;
}
void tarjan(int x,int rt)
{
    dfn[x]=low[x]=++num;
    int siz=0;
    in[x]=true;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(!dfn[v])
        {
            siz++;
            tarjan(v,rt);
            low[x]=min(low[x],low[v]);
            if(x!=rt&&low[v]>=dfn[x])
                tag[x]=true;
        }
        else if(in[v])
        {
            low[x]=min(low[x],dfn[v]);
        }
    }
    in[x]=false;
    if(x==rt&&siz>1)tag[x]=true;
}
void dfs(int x,int fa)
{
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dfs(v,x);
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
    for(int i=1;i<=n;i++)
        if(!dfn[i])tarjan(i,i);
    vector<int> ans;
    for(int i=1;i<=n;i++)
        if(tag[i])ans.push_back(i);
    cout<<ans.size()<<endl;
    for(int x:ans)cout<<x<<" ";
    return 0;
}