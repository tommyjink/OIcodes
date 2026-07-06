#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e6+10,P=998244353;
int n,m,head[N*2],tot=0;
int rt1=1,rt2=0,dep[N];
int mson[N],cson[N],son[N];
int public_maxl=0,ans=0;
int hei[N],maxl[N],sp[N];
int dmax[N],sumdmax[N];
struct node
{
	int to,next;
}e[N*2];
void add(int x,int y)
{
	e[++tot]=(node){y,head[x]};
	head[x]=tot;
}
void dfs1(int x,int fa,int d)
{
	dep[x]=d;hei[x]=0;
	for(int i=head[x];i;i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa)continue;
		son[x]++;
		dfs1(v,x,d+1);
		hei[x]=max(hei[x],hei[v]+1);
		if(mson[x]==0||hei[mson[x]]<hei[v])
			cson[x]=mson[x],mson[x]=v;
		else if(hei[cson[x]]<=hei[v])
			cson[x]=v;
	}
}
void dfs2(int x,int fa,int fal)
{
	maxl[x]=max(hei[x],fal);
	public_maxl=max(public_maxl,maxl[x]);
	for(int i=head[x];i;i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa)continue;
		if(v==mson[x])
			if(son[x]==1)
				dfs2(v,x,fal+1);
			else dfs2(v,x,max(hei[cson[x]]+2,fal+1));
		else dfs2(v,x,max(hei[mson[x]]+2,fal+1));
	}
}
void cal_maxl()
{
	dfs1(rt1,0,0);
	dfs1(rt2,0,0);
	dfs2(rt1,0,0);
	dfs2(rt2,0,0);
}
int mul(int x,int y)
{
	int res=0;
	x%=P,y%=P;
	while(y)
	{
		if(y&1)res=(res+x)%P;
		y>>=1;
		x=(x+x)%P;
	}
	return res;
}
void solve()
{
	for(int i=1;i<=m;i++)
		dmax[i]=maxl[n+i];
	sort(dmax+1,dmax+1+m);
	for(int i=m;i>=1;i--)
		sumdmax[i]=(sumdmax[i+1]+dmax[i])%P; 
	for(int i=1;i<=n;i++)
	{
		int t=public_maxl-maxl[i]-1;
		int p=upper_bound(dmax+1,dmax+1+m,t)-dmax-1;
		if(p<=m)ans=(ans+mul(p,public_maxl)+sumdmax[p+1]+mul(maxl[i],(m-p))+(m-p))%P;
		else ans=(ans+mul(m,public_maxl))%P;
	}
}
signed main()
{
	cin>>n>>m;rt2=n+1;
	for(int i=1;i<=n-1;i++)
	{
		int x,y;
		scanf("%lld%lld",&x,&y);
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=m-1;i++)
	{
		int x,y;
		scanf("%lld%lld",&x,&y);
		x+=n,y+=n;
		add(x,y);
		add(y,x);
	}
	cal_maxl();
	solve();
	printf("%lld",ans);
	return 0;
}