#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e3+10;
int n,mp[N][N],in[N];
int head[N],tot=0,fa[N];
int dfn[N],low[N],now=0,col[N];
int stk[N],top=0,cnt=0,ans=0;
struct node
{
    int from,to,next;
}e[N*2];
void add(int x,int y)
{
    e[++tot]=(node){x,y,head[x]};
    head[x]=tot;
}
void dfs(int x)
{
    dfn[x]=low[x]=++now;
    stk[top++]=x;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(!dfn[v])
        {
            dfs(v);
            low[x]=min(low[x],low[v]);
        }
        else if(!col[v])
        {
            low[x]=min(low[x],dfn[v]);
        }
    }
    if(dfn[x]==low[x])
    {
        cnt++;
        while(1)
        {
            int v=stk[--top];
            col[v]=cnt;
            if(v==x)break;
        }
    }
}

void tarjan()
{
    for(int i=1;i<=n;i++)
        if(!dfn[i])dfs(i);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(mp[i][j]&&col[i]!=col[j])
                in[col[j]]++;
    for(int i=1;i<=cnt;i++)
        if(in[i]==0)ans++;
}
signed main()
{
    freopen("news.in","r",stdin);
    freopen("news.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>mp[i][j];
            if(mp[i][j])add(i,j);
        }
    }
    tarjan();
    cout<<ans<<endl;
    return 0;
}
/*
8 
0 0 1 0 0 0 0 0 
1 0 0 1 0 0 0 0 
0 1 0 1 1 0 0 0 
0 0 0 0 0 1 0 0 
0 0 0 1 0 0 0 0 
0 0 0 1 0 0 0 0 
0 0 0 1 0 0 0 1 
0 0 0 0 0 0 1 0

5
0 1 0 0 0
1 0 0 0 0
0 0 0 1 0
0 0 1 0 0
0 0 0 1 0

*/