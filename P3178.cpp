#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000000;
int n,m,tot=0,tt=0,root=1;
int a[N],lazy[N],head[N],fa[N],d[N],siz[N],son[N],top[N],dfn[N],dfn2[N];
struct node
{
    int to,next;
}e[N];
struct node1
{
    int l,r,val;
}t[N];
void add(int x,int y)
{
    e[++tot].to=y;
    e[tot].next=head[x];
    head[x]=tot;
}
void push_up(int k)
{
    t[k].val=t[k*2].val+t[k*2+1].val;
}
void push_down(int k)
{
    t[k*2].val+=lazy[k]*(t[k*2].r-t[k*2].l+1);
    t[k*2+1].val+=lazy[k]*(t[k*2+1].r-t[k*2+1].l+1);
    lazy[k*2]+=lazy[k];
    lazy[k*2+1]+=lazy[k];
    lazy[k]=0;
}
void build_tree(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    if(l==r)
    {
        t[k].val=a[dfn2[l]];
        return;
    }
    int mid=(l+r)>>1;
    build_tree(k*2,l,mid);
    build_tree(k*2+1,mid+1,r);
    push_up(k);
}
void add_single_tree(int k,int x,int dd)
{
    if(t[k].l>x||t[k].r<x)  return;
    if(t[k].l==t[k].r) 
    {
        t[k].val+=dd;
        return;
    }
    push_down(k);
    add_single_tree(k*2,x,dd);
    add_single_tree(k*2+1,x,dd);
    push_up(k);
}
void add_section_tree(int k,int l,int r,int dd)
{
    if(t[k].r<l||t[k].l>r)  return;
    if(l<=t[k].l&&t[k].r<=r)
    {
        t[k].val+=dd*(t[k].r-t[k].l+1);
        lazy[k]+=dd;
        return;
    }
    push_down(k);
    add_section_tree(k*2,l,r,dd);
    add_section_tree(k*2+1,l,r,dd);
    push_up(k);
}
int query_section_tree(int k,int l,int r)
{
    if(l>t[k].r||r<t[k].l)	return 0;
	if(l<=t[k].l&&r>=t[k].r)
		return t[k].val;
	push_down(k);
	int sum=0;
	sum+=query_section_tree(k*2,l,r);
	sum+=query_section_tree(k*2+1,l,r);
	return sum;	
}
void dfs1(int node,int f)
{
    fa[node]=f;
    d[node]=d[f]+1;
    siz[node]=1;
    for(int i=head[node];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v!=f)
        {
            dfs1(v,node);
            siz[node]+=siz[v];
            if(!son[node]||siz[son[node]]<siz[v])
                son[node]=v;
        }
    }
}
void dfs2(int node,int topx)
{
    dfn[node]=++tt;
    dfn2[tt]=node;
    top[node]=topx;
    if(!son[node])  return;
    dfs2(son[node],topx);
    for(int i=head[node];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v!=fa[node]&&v!=son[node])
            dfs2(v,v);
    }
}
void add_single(int x,int dd)
{
    add_single_tree(1,dfn[x],dd);
}
void add_root(int x,int dd)
{
    add_section_tree(1,dfn[x],dfn[x]+siz[x]-1,dd);
}
int query_tree(int x)
{
    int sum=0;
    while(x)
    {
        sum+=query_section_tree(1,dfn[top[x]],dfn[x]);
        x=fa[top[x]];
    }
    return sum;
}
signed main()
{
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        scanf("%lld%lld",&x,&y);
        add(x,y),add(y,x);
    }
    dfs1(root,0);
    dfs2(root,root);
    build_tree(1,1,n);
    while(m--)
    {
        int ch;
        scanf("%lld",&ch);
        if(ch==1)
        {
            int x,y;
            scanf("%lld%lld",&x,&y);
            add_single(x,y);
        }
        if(ch==2)
        {
            int x,y;
            scanf("%lld%lld",&x,&y);
            add_root(x,y);
        }
        if(ch==3)
        {
            int x;
            scanf("%lld",&x);
            printf("%lld\n",query_tree(x));
        }
    }
    return 0;
}