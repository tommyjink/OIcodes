#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int n,head[N*4],tot;
int dep[N],res[N],siz[N];
int ans=0,id;
struct node
{
	int to,next;
}e[N*4];
void add(int x,int y)
{
	e[++tot]=(node){y,head[x]};
	head[x]=tot;
}
void dfs1(int x,int fa,int d)
{
	siz[x]=1,dep[x]=d;
	for(int i=head[x];i;i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa)continue;
		dfs1(v,x,d+1);
		siz[x]+=siz[v];
	}
}
void dfs2(int x,int fa)
{
	if(x!=1)
		res[x]=res[fa]-2*siz[x]+siz[1];
	ans=max(ans,res[x]);
	if(res[x]==ans)id=x;
	for(int i=head[x];i;i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa)continue;
		dfs2(v,x);
	}
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	dfs1(1,0,0);
	for(int i=1;i<=n;i++)
		res[1]+=dep[i];
	dfs2(1,0);
	// for(int i=1;i<=n;i++)
		// cout<<siz[i]<<" ";
	// cout<<endl;
	// for(int i=1;i<=n;i++)
		// cout<<i<<" "<<res[i]<<endl;
	cout<<id<<endl;
	return 0;
}