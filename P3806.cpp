#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5,M=1e3,INF=0x3f3f3f3f3f3f;
int n,m,head[N],tot=0,qr[M],judge[N*200];
int maxp[N],root,vis[N],sum;
int size[N];
int dis[N],ans[M];
vector<int> rem(N);
struct node{int to,next,val;}e[N];
void add(int x,int y,int z)
{
	e[++tot]=(node){y,head[x],z};
	head[x]=tot;
}
void getroot(int x,int fa)
{
	size[x]=1,maxp[x]=0;
	for(int i=head[x];i;i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa||vis[v])continue;
		getroot(v,x);
		size[x]+=size[v];
		maxp[x]=max(maxp[x],size[v]);
	}
	maxp[x]=max(maxp[x],sum-size[x]);
	if(maxp[x]<maxp[root])root=x;
}
void getdis(int x,int fa)
{
	rem.push_back(dis[x]);
	for(int i=head[x];i;i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa||vis[v])continue;
		dis[v]=dis[x]+e[i].val;
		getdis(v,x);
	}
}
void calc(int x)
{
	queue<int> q;
	for(int i=head[x];i;i=e[i].next)
	{
		int v=e[i].to;
		if(vis[v])continue;
		dis[v]=e[i].val;rem.clear();
		getdis(v,x);
		for(int j=0;j<(int)rem.size();j++)
			for(int k=1;k<=m;k++)
				if(qr[k]>=rem[j]&&judge[qr[k]-rem[j]])
					ans[k]=true;
		for(int j=0;j<(int)rem.size();j++) 
			judge[rem[j]]=true,q.push(rem[j]);
	}
	while(!q.empty()) judge[q.front()]=false,q.pop();
}
void solve(int x)
{
	vis[x]=judge[0]=1,calc(x);
	for(int i=head[x];i;i=e[i].next)
	{
		int v=e[i].to;
		if(vis[v])continue;
		sum=size[v],maxp[root=0]=INF;
		getroot(v,0),solve(root);
	}
}
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n-1;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z),add(y,x,z);
	}
	for(int i=1;i<=m;i++)cin>>qr[i];
	maxp[root]=n,sum=n;
	getroot(1,0);
	solve(root);
	for(int i=1;i<=m;i++)
		cout<<(ans[i]?"AYE":"NAY")<<endl;
	return 0;
}