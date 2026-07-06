#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+100;
int n,s,tot=0,maxd=0,ans=0;
int head[N],val[N],tag[N],dep[N];
struct node
{
	int to,next,val;
}e[N*2];
vector<int> point[N];
void add(int x,int y,int z)
{
	e[++tot]=(node){y,head[x],z};
	head[x]=tot;
}
void dfs(int x,int fa,int d)
{
	point[d].push_back(x);
	maxd=max(maxd,d);
	val[x]=dep[x];
	for(int i=head[x];i;i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa)continue;
		dep[v]=dep[x]+e[i].val;
		dfs(v,x,d+1);
		val[x]=max(val[x],val[v]);
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>s;
	for(int i=1;i<=n-1;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z);
	}
	dfs(s,0,1);
	for(int i=1;i<=maxd;i++)
	{
		int maxv=0;
		for(int j=0;j<point[i].size();j++)
			val[point[i][j]]+=tag[point[i][j]],
			maxv=max(maxv,val[point[i][j]]);
		for(int j=0;j<point[i].size();j++)
		{
			int x=point[i][j];
			tag[x]+=maxv-val[x];
			ans+=maxv-val[x];
			for(int k=head[x];k;k=e[k].next)
				tag[e[k].to]=tag[x];
		}
		
	}
	cout<<ans<<endl;
	return 0;
}