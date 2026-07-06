#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e6+10;
int lazy[N*4],n,m,head[N],tot,tag[N],num=0,used[N];
int dfn[N],id[N],son[N],dep[N],siz[N],f[N][21],top[N];
map<pii,int> val;
vector<int> g[N];
vector<pii> sav;
struct node
{
	int l,r,cnt;
}t[N*4];
struct node1
{
	int to,next;
}e[N*2];
void add(int x,int y)
{
	e[++tot]={y,head[x]};
	head[x]=tot;
}
void pushdown(int k)
{
	if(lazy[k])
	{
		if(!lazy[k*2])lazy[k*2]=lazy[k],t[k*2].cnt=t[k*2].r-t[k*2].l+1;
		if(!lazy[k*2+1])lazy[k*2+1]=lazy[k],t[k*2+1].cnt=t[k*2+1].r-t[k*2+1].l+1;
	}
}
void pushup(int k)
{
	t[k].cnt=t[k*2].cnt+t[k*2+1].cnt;
}
void build(int k,int l,int r)
{
	t[k].l=l,t[k].r=r;
	if(l==r)return;
	int mid=(l+r)>>1;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
}
void modify(int k,int l,int r,int d)
{
	if(t[k].l>r||t[k].r<l)return;
	if(l<=t[k].l&&t[k].r<=r)
	{
		t[k].cnt=t[k].r-t[k].l+1;
		if(!lazy[k])lazy[k]=d;
		return;
	}
	pushdown(k);
	modify(k*2,l,r,d);
	modify(k*2+1,l,r,d);
	pushup(k);
}
int query(int k,int x)
{
	if(t[k].l==t[k].r)return lazy[k];
	pushdown(k);
	if(t[k*2].r>=x)return query(k*2,x);
	return query(k*2+1,x);
}
int querycnt(int k,int l,int r)
{
	if(t[k].l>r||t[k].r<l)return 0;
	if(l<=t[k].l&&t[k].r<=r)return t[k].cnt;
	pushdown(k);
	return querycnt(k*2,l,r)+querycnt(k*2+1,l,r);
}
void dfs1(int x,int fa)
{
	f[x][0]=fa;
	dep[x]=dep[fa]+1;
	siz[x]=1;
	for(int i=head[x];i;i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa)continue;
		dfs1(v,x);
		siz[x]+=siz[v];
		if(siz[v]>siz[son[x]])son[x]=v;
	}
}
void dfs2(int x,int tp)
{
	dfn[x]=++num;
	id[num]=x;
	top[x]=tp;
	if(son[x])dfs2(son[x],tp);
	for(int i=head[x];i;i=e[i].next)
	{
		int v=e[i].to;
		if(v==f[x][0]||v==son[x])continue;
		dfs2(v,v);
	}
}
void init()
{
	for(int i=1;i<=20;i++)
		for(int j=1;j<=n;j++)
			f[j][i]=f[f[j][i-1]][i-1];
}
int lca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	for(int i=20;i>=0;i--)
		if(dep[f[x][i]]>=dep[y])
			x=f[x][i];
	if(x==y)return x;
	for(int i=20;i>=0;i--)
		if(f[x][i]!=f[y][i])
			x=f[x][i],
			y=f[y][i];
	return f[x][0];
}
void modifyline(int x,int y,int d)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		modify(1,dfn[top[x]],dfn[x],d);
		x=f[top[x]][0];
	}
	if(dep[x]>dep[y])swap(x,y);
	modify(1,dfn[x],dfn[y],d);
}
int queryline(int x,int y)
{
	int res=0;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		res+=querycnt(1,dfn[top[x]],dfn[x]);
		x=f[top[x]][0];
	}
	if(dep[x]>dep[y])swap(x,y);
	res+=querycnt(1,dfn[x],dfn[y]);
	return res;
}
int jump(int x,int y)
{
	for(int i=20;i>=0;i--)
		if(dep[f[x][i]]>=dep[y]+1)
			x=f[x][i];
	return x;
}
signed main()
{
	cin>>n>>m;
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		sav.push_back(pii(x,y));
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(int i=1;i<=n-1;i++)
	{
		int x;
		cin>>x;
		tag[x]=true;
		add(sav[x-1].first,sav[x-1].second);
		add(sav[x-1].second,sav[x-1].first);
	}
	dfs1(1,0);
	dfs2(1,0);
	init();
	//~ while(1)
	//~ {
		//~ int x,y;
		//~ cin>>x>>y;
		//~ cout<<lca(x,y)<<endl;
	//~ }
	int now=1;
	for(int i=1;i<=m;i++)
	{
		//~ cout<<"_________"<<endl;
		//~ for(int j=1;j<=n;j++)
			//~ cout<<dfn[j]<<" ";
		//~ cout<<endl;
		//~ for(int j=1;j<=n;j++)
			//~ cout<<querycnt(1,j,j)<<" ";
		//~ cout<<endl;

		int x=sav[i-1].first;
		int y=sav[i-1].second;
		if(dfn[x]>dfn[y])swap(x,y);
		int o=lca(x,y),dis=0;
		if(x!=o)dis+=queryline(x,jump(x,o));
		if(y!=o)dis+=queryline(y,jump(y,o));
		//~ cout<<dis<<":::";
		dis=dep[x]+dep[y]-2*dep[o]-dis;
		//~ cout<<x<<","<<y<<","<<o<<":"<<dis<<endl;
		if(!tag[i])
		{
			if(x!=o)
			{
				int fx=jump(x,o);
				modifyline(x,fx,i);
			}
			if(y!=o)
			{
				int fy=jump(y,o);
				modifyline(y,fy,i);
			}
			val[pii(x,y)]=now+dis;
			used[now+dis]=true;
			now+=dis+1;
		}
		else
		{
			//~ cout<<dfn[y]<<">>>"<<query(1,dfn[y])<<">>>Q"<<endl;
			if(query(1,dfn[y]))continue;
			else 
			{
				modify(1,dfn[y],dfn[y],i);
				val[pii(x,y)]=now,used[now]=true,now++;
			}
		}
	}
	int p=1;
	for(int i=1;i<=m;i++)
	{
		int x=sav[i-1].first;
		int y=sav[i-1].second;
		if(dfn[x]>dfn[y])swap(x,y);
		if(val.count(pii(x,y)))cout<<val[pii(x,y)]<<" ";
		else
		{
			while(used[p])p++;
			used[p]=true;
			cout<<p<<" ";
		}
	}
	//~ while(1)
	//~ {
		//~ int op;cin>>op;
		//~ if(op==1)
		//~ {
			//~ int l,r,d;
			//~ cin>>l>>r>>d;
			//~ modify(1,l,r,d);
		//~ }
		//~ else
		//~ {
			//~ int x;
			//~ cin>>x;
			//~ cout<<query(1,x)<<endl;
		//~ }
	//~ }
	return 0;
}
/*


5
1 1 3 1
1 1 4 2
1 3 5 3
2 1 2 2 2 3 2 4 2 5
 


*/
