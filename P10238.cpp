#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=2e5+10,M=30;
int n,q,tot=0,head[N],fa[N],Q[N],tag[N*2],ds[N],ans[N];
int dis[N],mdis=0,mnum=0,X[N],Y[N],dep[N],f[N][M+10];

struct node
{
	int to,next,val,from;
}e[N*2];
void add(int x,int y,int z)
{
	e[++tot]=(node){y,head[x],z,x};
	head[x]=tot;
}
void init()
{
	for(int i=1;i<=n;i++)
		head[i]=0,fa[i]=i;
	tot=0;
	for(int i=1;i<=q;i++)
		Q[i]=0,ans[i]=0;
}
int getfa(int x)
{
	if(x==fa[x])return fa[x];
	else return (fa[x]=getfa(fa[x]));
}
void merge(int x,int y)
{
	if(getfa(x)!=getfa(y))
		fa[getfa(y)]=getfa(x);
}
void dfs0(int x,int fa,int d,int dd)
{
	dep[x]=d;
	ds[x]=dd;
	f[x][0]=fa;
	for(int i=head[x];i;i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa)continue;
		dfs0(v,x,d+e[i].val,dd+1);
	}
}
void dfs(int x,int fa,int d)
{
	dis[x]=d;
	if(dis[x]>mdis)
	{
		mdis=dis[x];
		mnum=x;
	}
	for(int i=head[x];i;i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa||tag[i])continue;
		dfs(v,x,d+e[i].val);
	}
}
void init_fa()
{
	for(int i=1;i<=M;i++)
		for(int j=1;j<=n;j++)
			f[j][i]=f[f[j][i-1]][i-1];
}
int lca(int x,int y)
{
	if(ds[x]<ds[y])swap(x,y);
	for(int i=M;i>=0;i--)
		if(ds[f[x][i]]>=ds[y])
			x=f[x][i];
	if(x==y)return x;
	for(int i=M;i>=0;i--)
		if(f[x][i]!=f[y][i])
			x=f[x][i],y=f[y][i];
	return f[x][0];
}
int cal(int x,int y)
{
	int o=lca(x,y);
	return dep[x]+dep[y]-2*dep[o];
}
void solve()
{
	cin>>n>>q;
	init();
	for(int i=1;i<=n-1;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z);
	}
	dfs0(1,1,0,1);
	for(int i=1;i<=q;i++)
	{
		cin>>Q[i];
		tag[Q[i]*2]=true;
		tag[Q[i]*2-1]=true;
	}
	for(int i=1;i<=tot;i++)
		if(!tag[i])merge(e[i].from,e[i].to);
	for(int i=1;i<=n;i++)
	{
		if(fa[i]!=i)continue;
		mdis=-1,mnum=0;
		dfs(i,i,0);
		X[i]=mnum;
		mdis=-1,mnum=0;
		dfs(X[i],X[i],0);
		Y[i]=mnum;
		ans[q]=max(ans[q],mdis);
	}
	init_fa();
	for(int i=q;i>=1;i--)
	{
		
		int x=e[Q[i]*2].from,y=e[Q[i]*2].to;
		int a[4]={X[getfa(x)],Y[getfa(x)],X[getfa(y)],Y[getfa(y)]};
		int mdis=-1,mx=0,my=0;
		for(int j=0;j<4;j++)
			for(int k=j+1;k<4;k++)
				if(cal(a[j],a[k])>mdis)
				{
					mdis=cal(a[j],a[k]);
					mx=a[j],my=a[k];
				}
		ans[i-1]=max({ans[i-1],mdis,ans[i]});
		merge(x,y);
		X[getfa(x)]=mx;
		Y[getfa(x)]=my;
	}
	for(int i=1;i<=q;i++)
		cout<<ans[i]<<endl;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}