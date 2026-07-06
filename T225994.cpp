#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int n,c[N],head[N*4],tot;
int siz[N];//cow sum on the son tree
int dep[N];//cow run sum spend
int f[N];//result
int ans=1e17;//answer
struct node
{
	int to,next,val;
}e[N*4];
void add(int x,int y,int z)
{
	e[++tot]=(node){y,head[x],z};
	head[x]=tot;
}
void dfs1(int x,int fa,int d)
{
	siz[x]=c[x],dep[x]=d;
	for(int i=head[x];i;i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa)continue;
		dfs1(v,x,d+e[i].val);
		siz[x]+=siz[v];
	}
}
void dfs2(int x,int fa)
{
	for(int i=head[x];i;i=e[i].next)
	{
		int v=e[i].to,val=e[i].val;
		if(v==fa)continue;
		f[v]=f[x]-2*siz[v]*val+siz[1]*val;
		dfs2(v,x);
	}
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	for(int i=1;i<=n-1;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z);
	}
	dfs1(1,0,0);
	for(int i=1;i<=n;i++)
		f[1]+=c[i]*dep[i];
	dfs2(1,0);
	for(int i=1;i<=n;i++)
		ans=min(ans,f[i]);
	cout<<ans;
	return 0;
}