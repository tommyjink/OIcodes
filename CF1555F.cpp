#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,head[N],tot;
int lazy[N],dep[N],val[N],son[N],siz[N],top[N];
int dfn[N],num,nfd[N],fa[N];
struct xyz{int x,y,z;}q[N];
struct node
{
    int to,next,val;
}e[N*2];
struct DSU
{
    int fa[N];
    void init(int n){for(int i=1;i<=n;i++)fa[i]=i;}
    int getfa(int x){return x==fa[x]?x:fa[x]=getfa(fa[x]);}
    bool merge(int x,int y)
    {
        x=getfa(x),y=getfa(y);
        if(x==y)return false;
        fa[x]=y;
        return true;
    }
}D;
void add(int x,int y,int z)
{
    e[++tot]=(node){y,head[x],z};
    head[x]=tot;
}
struct tr
{
    int l,r,val;
}t[N*4];
void pushup(int k)
{
    t[k].val=max(t[k*2].val,t[k*2+1].val);
}
void pushdown(int k)
{
    t[k*2].val=max(t[k*2].val,lazy[k]);
    t[k*2+1].val=max(t[k*2+1].val,lazy[k]);
    lazy[k*2]=max(lazy[k*2],lazy[k]);
    lazy[k*2+1]=max(lazy[k*2+1],lazy[k]);
    lazy[k]=0;
}
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    if(l==r)return;
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    pushup(k);
}
int query(int k,int l,int r)
{
    if(t[k].l>r||t[k].r<l)return 0;
    if(l<=t[k].l&&t[k].r<=r)return t[k].val;
    pushdown(k);
    return max(query(k*2,l,r),query(k*2+1,l,r));
}
void modify(int k,int l,int r,int v)
{
    if(t[k].l>r||t[k].r<l)return;
    if(l<=t[k].l&&t[k].r<=r)
    {
        t[k].val=max(t[k].val,v);
        lazy[k]=max(lazy[k],v);
        return;
    }
    pushdown(k);
    modify(k*2,l,r,v);
    modify(k*2+1,l,r,v);
    pushup(k);
}
void dfs(int x)
{
    siz[x]=1,dep[x]=dep[fa[x]]+1;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa[x])continue;
        fa[v]=x;
        val[v]=val[x]^e[i].val;
        dfs(v);
        siz[x]+=siz[v];
        if(siz[v]>siz[son[x]])son[x]=v;
    }
}
void dfs1(int x,int tp)
{
    dfn[x]=++num;
    nfd[num]=x;
    top[x]=tp;
    if(son[x])dfs1(son[x],tp);
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa[x]||v==son[x])continue;
        dfs1(v,v);
    }
}
int lca(int x,int y)
{
    while(top[x]!=top[y])
    {
        if(dep[top[x]]<dep[top[y]])
            swap(x,y);
        x=fa[top[x]];
    }
    if(dep[x]>dep[y])swap(x,y);
    return x;
}
int queryline(int x,int y)
{
    int res=0;
    while(top[x]!=top[y])
    {
        if(dep[top[x]]<dep[top[y]])
            swap(x,y);
        res=max(res,query(1,dfn[top[x]],dfn[x]));
        x=fa[top[x]];
    }
    if(dep[x]>dep[y])swap(x,y);
    if(dfn[x]+1<=dfn[y])
        res=max(res,query(1,dfn[x]+1,dfn[y]));
    return res;
}
void modifyline(int x,int y)
{
    while(top[x]!=top[y])
    {
        if(dep[top[x]]<dep[top[y]])
            swap(x,y);
        modify(1,dfn[top[x]],dfn[x],1);
        x=fa[top[x]];
    }
    if(dep[x]>dep[y])swap(x,y);
    if(dfn[x]+1<=dfn[y])
        modify(1,dfn[x]+1,dfn[y],1);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    D.init(n);
    for(int i=1;i<=m;i++)
    {
        cin>>q[i].x>>q[i].y>>q[i].z;
        if(D.merge(q[i].x,q[i].y))
            add(q[i].x,q[i].y,q[i].z),
            add(q[i].y,q[i].x,q[i].z);
    }
    for(int i=1;i<=n;i++)
        if(!siz[i])dfs(i);
    for(int i=1;i<=n;i++)
        if(!dfn[i])dfs1(i,i);
    // for(int i=1;i<=n;i++)
    //     cout<<val[i]<<",";
    // cout<<endl;
    build(1,1,n);
    D.init(n);
    for(int i=1;i<=m;i++)
    {
        if(D.merge(q[i].x,q[i].y))
        {
            cout<<"YES"<<endl;
            continue;
        }
        int res=queryline(q[i].x,q[i].y);
        if(res==0&&(val[q[i].x]^val[q[i].y]^q[i].z)==1)
        {
            modifyline(q[i].x,q[i].y);
            cout<<"YES"<<endl;
            // cout<<(val[q[i].x]^val[q[i].y])<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}