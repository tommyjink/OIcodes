#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5e5+100;;
int n,q,val[N],tot,head[N*2];
int dep[N],sum[N],cnt[N],f[N][25];
struct node
{
	int to,next;
}e[N*2];
void add(int x,int y)
{
	e[++tot]=(node){y,head[x]};
	head[x]=tot;
}
void dfs(int x,int fa)
{
	sum[x]=val[x];
	dep[x]=dep[fa]+1,f[x][0]=fa;
	for(int i=head[x];i;i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa)continue;
		dfs(v,x);
		sum[x]+=sum[v];
	}
}
void dfs1(int x,int fa)
{
	cnt[x]=sum[x];
	for(int i=head[x];i;i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa)continue;
		dfs1(v,x);
		cnt[x]+=cnt[v];
	}
}
void initfa()
{
	for(int i=1;i<=24;i++)
	{
		for(int j=1;j<=n;j++)
		{
			f[j][i]=f[f[j][i-1]][i-1];
		}
	}
}
int ff(int x,int k)
{
	for(int i=24;i>=0;i--)
		if((1LL<<i)<=k)k-=(1LL<<i),x=f[x][i];
	return x;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>val[i];
	for(int i=2;i<=n;i++)
	{
		int x;cin>>x;
		add(x,i),add(i,x);
	}
	dfs(1,0);
	dfs1(1,0);
	initfa();
	for(int i=1;i<=n;i++)
		cout<<cnt[i]<<" ";
	cout<<endl;
	for(int i=1;i<=n;i++)
		cout<<sum[i]<<" ";
	cout<<endl;
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int ans=cnt[y]-sum[y];
		if(f[x][0]==y)cout<<ans<<endl;
		else
		{
			int o=ff(x,dep[x]-dep[y]-1);
			cout<<ans+sum[o]-val[x]<<endl;
			
		}
	}
	return 0;
}