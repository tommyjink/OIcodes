#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int n,tot=0,head[N*2];
int num=0,id[N],siz[N];
int dep[N],L[N],R[N],son[N];
int ans[N];
struct node
{
	int to,next;
}e[N*2];
struct node1
{
	int l,r,val,num;
}t[N*4];
void pushup(int k)
{
	t[k].val=max(t[k*2].val,t[k*2+1].val);
	if(t[k*2].val>=t[k*2+1].val)t[k].num=t[k*2].num;
	else t[k].num=t[k*2+1].num;
}
void build(int k,int l,int r)
{
	t[k].l=l,t[k].r=r;
	if(l==r)
	{
		t[k].num=l;
		return;
	}
	int mid=(l+r)>>1;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	pushup(k);
}
void modify(int k,int pos,int d)
{
	if(t[k].l>pos||t[k].r<pos)return;
	if(t[k].l==t[k].r)
	{
		t[k].val+=d;
		return;
	}
	modify(k*2,pos,d);
	modify(k*2+1,pos,d);
	pushup(k);
}
int query(int k,int l,int r,int &tnum)
{
	if(t[k].l>r||t[k].r<l)
	{
		tnum=0;
		return 0;
	}
	if(l<=t[k].l&&t[k].r<=r)
	{
		tnum=t[k].num;
		return t[k].val;
	}
	int t1=0,t2=0;
	int res1=query(k*2,l,r,t1);
	int res2=query(k*2+1,l,r,t2);
	if(res1>=res2)tnum=t1;
	else tnum=t2;
	return max(res1,res2);
}
void addedge(int x,int y)
{
	e[++tot]=(node){y,head[x]};
	head[x]=tot;
}
void add(int x)
{
	modify(1,dep[x],1);
}
void del(int x)
{
	modify(1,dep[x],-1);
}
void dfs1(int x,int fa,int d)
{
	L[x]=++num,id[num]=x;
	siz[x]=1,dep[num]=d;
	for(int i=head[x];i;i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa)continue;
		dfs1(v,x,d+1);
		siz[x]+=siz[v];
		if(!son[x]||siz[v]>siz[son[x]])
			son[x]=v;
	}
	R[x]=num;
}
void dfs2(int x,int fa,bool keep)
{
	for(int i=head[x];i;i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa||v==son[x])continue;
		dfs2(v,x,false);
	}
	if(son[x])dfs2(son[x],x,true);
	for(int i=head[x];i;i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa||v==son[x])continue;
		for(int j=L[v];j<=R[v];j++)
			add(j);
	}
	add(L[x]);
	query(1,dep[L[x]],n,ans[x]);
	ans[x]-=dep[L[x]];
	if(!keep)
		for(int i=L[x];i<=R[x];i++)
			del(i);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		addedge(x,y);
		addedge(y,x);
	}
	build(1,1,n);
	dfs1(1,0,1);
	dfs2(1,0,true);
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<endl;
		
	// test(passed!)
	// cin>>n;
	// build(1,1,n);
	// while(1)
	// {
		// int kkk=0;
		// for(int i=1;i<=n;i++)
			// cout<<query(1,i,i,kkk)<<" ";
		// cout<<endl;
		// int ch;cin>>ch;
		// if(ch==1)//modify
		// {
			// int x,y;
			// cin>>x>>y;
			// modify(1,x,y);
		// }
		// if(ch==2)//query
		// {
			// int x,y,z=0;
			// cin>>x>>y;
			// query(1,x,y,z);
			// cout<<query(1,x,y,z)<<"! ";
			// cout<<z<<endl;
		// }
	// }
	return 0;
}