#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int n,m,cc[N],tot=0,head[N*2];
int L[N],R[N],id[N],qk[N],num=0;
int dep[N],siz[N],son[N],c[N];
int cnt[N],ctot=0,t[N],ans[N];
vector<int> qid[N];
struct node
{
	int to,next;
}e[N*2];
void addedge(int x,int y)
{
	e[++tot]=(node){y,head[x]};
	head[x]=tot;
}
inline int lowbit(int x)
{
	return x&(-x);
}
void treeadd(int x,int d)
{
	if(x==0)return;
	for(int i=x;i<=n;i+=lowbit(i))
		t[i]+=d;
}
int treequery(int x)
{
	x=min(x,n);
	int res=0;
	for(int i=x;i>0;i-=lowbit(i))
		res+=t[i];
	return res;
}
void add(int x)
{
	// cout<<x<<" "<<id[x]<<" "<<c[x]<<"!\n";
	treeadd(cnt[c[x]],-1);
	cnt[c[x]]++;
	if(cnt[c[x]]==1)ctot++;
	treeadd(cnt[c[x]],1);
}
void del(int x)
{
	treeadd(cnt[c[x]],-1);
	if(cnt[c[x]]==1)ctot--;
	cnt[c[x]]--;
	treeadd(cnt[c[x]],1);
}
void dfs1(int x,int fa,int d)
{
	L[x]=++num,id[num]=x;
	dep[num]=d,siz[num]=1;
	c[num]=cc[x];
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
	for(int i=0;i<(int)qid[x].size();i++)
		ans[qid[x][i]]=ctot-treequery(qk[qid[x][i]]-1);//treequery(qk[qid[x][i]]-1)
	if(!keep)
		for(int i=L[x];i<=R[x];i++)
			del(i);
}
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>cc[i];
	for(int i=2;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		addedge(x,y);
		addedge(y,x);
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		qk[i]=y;
		qid[x].push_back(i);
	}
	dfs1(1,0,1);
	// for(int i=1;i<=n;i++)
		// printf("%lld %lld %lld %lld\n",i,id[i],c[i],L[id[i]]);
	dfs2(1,0,true);
	
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<endl;
	return 0;
}