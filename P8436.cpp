#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,tot=1,head[N],dfn[N],low[N],stk[N],in[N];
int num=0,top=0,ans=0;
vector<int> V[N];
struct node
{
    int to,next;
}e[N*4];
void add(int x,int y)
{
    e[++tot]=(node){y,head[x]};
    head[x]=tot;
}
void tarjan(int x,int rt,int fa)
{
    dfn[x]=low[x]=++num;
    stk[top++]=x;
    in[x]=true;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(i==(fa^1))continue;
        if(!dfn[v])
        {
            tarjan(v,rt,i);
            low[x]=min(low[x],low[v]);
        }
        else if(in[v])low[x]=min(low[x],dfn[v]);
    }
    if(low[x]==dfn[x])
    {
        ans++;
        while(1)
        {
            int t=stk[--top];
            V[ans].push_back(t);
            in[t]=false;
            if(t==x)break;
        }
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
        if(!dfn[i])tarjan(i,i,0);
    cout<<ans<<endl;
    for(int i=1;i<=ans;i++)
    {
        cout<<V[i].size()<<" ";
        for(auto j:V[i])cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}