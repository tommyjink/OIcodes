#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;

const int N=200000+5,LOG=20;

int n,q,tot;
int head[N],dep[N],dfn[N],ed[N],fa[N][LOG],bit[N],a[N];
int now;
struct node
{
    int to,next;
}e[N*2];
int t[N<<2],lazy[N<<2];

void add(int x,int y)
{
    e[++tot]=(node){y,head[x]};
    head[x]=tot;
}

void dfs(int rt)
{
    static int st[N],it[N],fa0[N];
    int top=1;
    st[1]=rt;
    fa0[rt]=0;
    dep[rt]=0;
    it[rt]=head[rt];
    while(top)
    {
        int x=st[top];
        if(!dfn[x])
        {
            dfn[x]=++now;
            fa[x][0]=fa0[x];
            for(int i=1;i<LOG;i++)
                fa[x][i]=fa[fa[x][i-1]][i-1];
        }
        if(it[x])
        {
            int y=e[it[x]].to;
            it[x]=e[it[x]].next;
            if(y==fa0[x])continue;
            fa0[y]=x;
            dep[y]=dep[x]+1;
            it[y]=head[y];
            st[++top]=y;
        }
        else
        {
            ed[x]=now;
            top--;
        }
    }
}

bool check(int x,int y)
{
    return dfn[x]<=dfn[y]&&ed[y]<=ed[x];
}

int jump(int x,int k)
{
    for(int i=0;i<LOG;i++)
        if(k>>i&1)
            x=fa[x][i];
    return x;
}

void pushdown(int k)
{
    if(!lazy[k])return;
    t[k*2]+=lazy[k];
    t[k*2+1]+=lazy[k];
    lazy[k*2]+=lazy[k];
    lazy[k*2+1]+=lazy[k];
    lazy[k]=0;
}

void change(int k,int l,int r,int ql,int qr,int v)
{
    if(r<ql||l>qr)return;
    if(ql<=l&&r<=qr)
    {
        t[k]+=v;
        lazy[k]+=v;
        return;
    }
    if(l==r)return;
    pushdown(k);
    int mid=(l+r)>>1;
    if(ql<=mid)change(k*2,l,mid,ql,qr,v);
    if(qr>mid)change(k*2+1,mid+1,r,ql,qr,v);
    t[k]=min(t[k*2],t[k*2+1]);
}

void addsub(int x,int v)
{
    change(1,1,n,dfn[x],ed[x],v);
}

void ins(int x,int v)
{
    for(;x<=n;x+=x&-x)
        bit[x]+=v;
}

int qry(int x)
{
    int res=0;
    for(;x;x-=x&-x)
        res+=bit[x];
    return res;
}

int ask(int l,int r)
{
    return qry(r)-qry(l-1);
}

int gets()
{
    return t[1];
}

void addside(int x,int y,int v)
{
    if(!check(x,y))
    {
        addsub(x,v);
        return;
    }
    int z=jump(y,dep[y]-dep[x]-1);
    change(1,1,n,1,n,v);
    addsub(z,-v);
}

void solve()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    dfs(1);
    for(int i=1;i<=n;i++)
    {
        int x=a[i];
        int v=ask(dfn[x],ed[x]);
        int o=i-1-v;
        addsub(x,o);
        for(int j=head[x];j;j=e[j].next)
        {
            int y=e[j].to;
            if(fa[y][0]!=x)continue;
            int s=ask(dfn[y],ed[y]);
            change(1,1,n,1,n,s);
            addsub(y,-s);
        }
        ins(dfn[x],1);
    }
    cout<<gets()<<endl;
    while(q--)
    {
        int x;
        cin>>x;
        int u=a[x],v=a[x+1];
        addside(v,u,-1);
        addside(u,v,1);
        swap(a[x],a[x+1]);
        cout<<gets()<<endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
