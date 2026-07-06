#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10,M=1005;
int n,w[N],dp[N][M];
int head[N],tot=0;
struct node
{
	int from,to,next,val;
}e[N*2];
void add(int x,int y,int z)
{
	e[++tot]=(node){x,y,head[x],z};
	head[x]=tot;
}
void dfs(int x,int fa)
{
	int maxval=0;
	if(!head[x])
	{
		for(int i=0;i<=1000;i++)
			dp[x][i]=i*w[x];
		return;
	}
	for(int i=head[x];i;i=e[i].next)
	{
		int v=e[i].to,val=e[i].val;
		if(v==fa)continue;
		dfs(v,x);
		maxval=max(maxval,val);
	}
	for(int i=0;i<=maxval;i++)
	{
		dp[x][i]=dp[x][i-1];
		int tmp=i*w[x];
		for(int j=head[x];j;j=e[j].next)
		{
			int v=e[j].to,val=e[i].val;
			if(j==fa)continue;
			tmp+=dp[v][val-i];
		}
		dp[x][i]=max(dp[x][i],tmp);
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("d.in","w",stdin);
	freopen("d.out","r",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>w[i];
	for(int i=1;i<=n-1;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z);
	}
	dfs(1,0);
	int ans=0;
	for(int i=0;i<=2000;i++)ans=max(ans,dp[1][i]);
	cout<<ans<<endl;
	return 0;
}
/*
3
1 2 3
1 2 3
2 3 4


*/