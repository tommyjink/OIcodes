#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,tot,head[N],tag[N];
int dfn[N],low[N],now;
struct node
{
    int to,next;
}e[N*2];
void add(int x,int y)
{
    e[++tot]=(node){y,head[x]};
    head[x]=tot;
}
void tarjan1(int x,int rt)
{
    dfn[x]=low[x]=++now;
    int siz=0;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(!dfn[v])
        {
            tarjan1(v,rt);
            low[x]=min(low[x],low[v]);
            siz++;
            if(low[v]>=dfn[x]&&x!=rt)tag[x]=true;
        }
        else low[x]=min(low[x],dfn[v]);
    }
    if(siz>1&&x==rt)tag[x]=true;
}
void tarjan2(int x,int fa)
{
    dfn[x]=low[x]=++now;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        if(!dfn[v])
        {
            tarjan2(v,x);
            low[x]=min(low[x],low[v]);
            if(low[v]>dfn[x])
                tag[x]=tag[v]=0;
        }
        else low[x]=min(low[x],dfn[v]);
    }
}
void solve()
{
    cin>>n>>m;
    tot=now=0;
    for(int i=1;i<=n;i++)
        head[i]=tag[i]=0;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    for(int i=1;i<=n;i++)
        dfn[i]=low[i]=0;
    for(int i=1;i<=n;i++)
        if(!dfn[i])tarjan1(i,i);
    for(int i=1;i<=n;i++)
        dfn[i]=low[i]=0;
    now=0;
    for(int i=1;i<=n;i++)
        if(!dfn[i])tarjan2(i,0);
    int cnt=0;
    for(int i=1;i<=n;i++)
        if(tag[i])cout<<i<<" ",cnt++;
    if(!cnt)cout<<"Empty";
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}