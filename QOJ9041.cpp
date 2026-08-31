#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,tot,tim,need,tp,fl;
int head[N],dfn[N],low[N],du[N],h[N];
int st[N],q[N],ex[N],ey[N];
int to[N*2],nxt[N*2],tt;

struct node
{
    int to,nxt,id;
}e[N*2];

void add(int x,int y,int id)
{
    e[++tot]={y,head[x],id};
    head[x]=tot;
}

void add1(int x,int y)
{
    to[++tt]=y;
    nxt[tt]=h[x];
    h[x]=tt;
}

bool check(int id)
{
    int cnt=0,top=0,tmp=0,x=0,y=0,len=0;
    tt=0;
    while(1)
    {
        int t=st[tp--];
        cnt++;
        int u=ex[t],v=ey[t];
        if(!du[u])q[++top]=u;
        if(!du[v])q[++top]=v;
        du[u]++;
        du[v]++;
        add1(u,v);
        add1(v,u);
        if(t==id)break;
    }
    for(int i=1;i<=top;i++)
    {
        int u=q[i];
        if(du[u]>2)
        {
            tmp++;
            if(!x)x=u;
            else y=u;
        }
    }
    bool ok=true;
    if(cnt==1)ok=true;
    else if(tmp==0)len=cnt;
    else if(tmp==2)
    {
        if(du[x]!=du[y])ok=false;
        int lst=0;
        for(int i=h[x];i&&ok;i=nxt[i])
        {
            int pre=x,u=to[i],dis=1;
            while(u!=y)
            {
                if(u==x||du[u]!=2||dis>cnt)
                {
                    ok=false;
                    break;
                }
                int v=0;
                for(int j=h[u];j;j=nxt[j])
                    if(to[j]!=pre)
                    {
                        v=to[j];
                        break;
                    }
                pre=u;
                u=v;
                dis++;
            }
            if(lst&&lst!=dis)ok=false;
            lst=dis;
        }
        if(ok)len=2*lst;
    }
    else ok=false;
    if(ok&&len)
    {
        if(!need)need=len;
        else if(need!=len)ok=false;
    }
    for(int i=1;i<=top;i++)
    {
        int u=q[i];
        du[u]=0;
        h[u]=0;
    }
    return ok;
}

void dfs(int x,int fa)
{
    dfn[x]=low[x]=++tim;
    for(int i=head[x];i&&fl;i=e[i].nxt)
    {
        int y=e[i].to,id=e[i].id;
        if(id==fa)continue;
        if(!dfn[y])
        {
            st[++tp]=id;
            dfs(y,id);
            if(low[y]<low[x])low[x]=low[y];
            if(low[y]>=dfn[x])
                if(!check(id))
                {
                    fl=false;
                    return;
                }
        }
        else if(dfn[y]<dfn[x])
        {
            st[++tp]=id;
            if(dfn[y]<low[x])low[x]=dfn[y];
        }
    }
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        head[i]=0;
        dfn[i]=low[i]=0;
    }
    tot=tim=need=tp=0;
    fl=true;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        ex[i]=x;
        ey[i]=y;
        add(x,y,i);
        add(y,x,i);
    }
    for(int i=1;i<=n&&fl;i++)
        if(!dfn[i])dfs(i,0);
    if(fl)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--)solve();
    return 0;
}
