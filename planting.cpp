#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000000;
int n,q,tot=0,root=1,tt=0;
int lazy[N],a[N],head[N],fa[N];
int top[N],d[N],son[N],siz[N],dfn[N],dfn2[N];
struct node
{
	int l,r,val;
}t[N];
struct node2
{
	int to,next;
}e[N];
void add(int x,int y)
{
	e[++tot].next=head[x];
	e[tot].to=y;
	head[x]=tot;
}
void push_down(int k)
{
	t[k*2].val+=lazy[k]*(t[k*2].r-t[k*2].l+1);
	t[k*2+1].val+=lazy[k]*(t[k*2+1].r-t[k*2+1].l+1);
	lazy[k*2]+=lazy[k];
	lazy[k*2+1]+=lazy[k];
	lazy[k]=0;
}
void push_up(int k)
{
	t[k].val=t[k*2].val+t[k*2+1].val;
}
void Build(int k,int l,int r)
{
	t[k].l=l,t[k].r=r;
	if(t[k].l==t[k].r)
	{
		return;
	}
	int mid=(l+r)>>1;
	Build(k*2,l,mid);
	Build(k*2+1,mid+1,r);
	push_up(k);
}
void SectionAdd(int k,int l,int r,int dd)
{
	if(t[k].l>r||t[k].r<l)	return;
	if(l<=t[k].l&&t[k].r<=r)
	{
		t[k].val+=dd*(t[k].r-t[k].l+1);
		lazy[k]+=dd;
		return;
	}
	push_down(k);
	SectionAdd(k*2,l,r,dd);
	SectionAdd(k*2+1,l,r,dd);
	push_up(k);
}
int SectionQuery(int k,int l,int r)
{
	if(t[k].l>r||t[k].r<l)	return 0;
	if(l<=t[k].l&&t[k].r<=r)
		return t[k].val;
	push_down(k);
	int sum=0;
	sum+=SectionQuery(k*2,l,r);
	sum+=SectionQuery(k*2+1,l,r);
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
	dfn[node]=++tt,dfn2[tt]=node;
	top[node]=topx;
	if(!son[node])	return;
	dfs2(son[node],topx);
	for(int i=head[node];i;i=e[i].next)
	{
		int v=e[i].to;
		if(v!=fa[node]&&v!=son[node])
			dfs2(v,v);
	}
}
void TreeSectionAdd(int x,int y,int dd)
{
	while(top[x]!=top[y])
	{
		if(d[top[x]]<d[top[y]])	swap(x,y);
		SectionAdd(1,dfn[top[x]],dfn[x],dd);
		x=fa[top[x]];
	}
	if(d[x]>d[y])	swap(x,y);
	SectionAdd(1,dfn[son[x]],dfn[y],dd);
}
int TreeSectionQuery(int x,int y)
{
    int sum=0;
	while(top[x]!=top[y])
	{
		if(d[top[x]]<d[top[y]])	swap(x,y);
		sum+=SectionQuery(1,dfn[top[x]],dfn[x]);
		x=fa[top[x]];
	}
	if(d[x]>d[y])	swap(x,y);
	sum+=SectionQuery(1,dfn[son[x]],dfn[y]);
    return sum;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y),add(y,x);
	}
	Build(1,1,n);
	dfs1(root,0);
	dfs2(root,root);
	while(q--)
	{
		char ch;
        int x,y;
		cin>>ch>>x>>y;
		if(ch=='P')
		{
			TreeSectionAdd(x,y,1);
		}
		if(ch=='Q')
		{
			printf("%lld\n",TreeSectionQuery(x,y));
		}
	}
	return 0;
}