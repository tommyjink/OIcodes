#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int n,q,tot=0,head[N*2];
int siz[N],f[N],ans[N];
int msiz[N];
struct node
{
	int to,next;
}e[N*4];
void add(int x,int y)
{
	e[++tot]=(node){y,head[x]};
	head[x]=tot;
}
void dfs(int x,int fa)
{
	siz[x]=1,f[x]=fa,ans[x]=x;
	for(int i=head[x];i;i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa)continue;
		dfs(v,x);
		siz[x]+=siz[v];
		msiz[x]=max(msiz[x],siz[v]);
	}
	for(int i=head[x];i;i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa)continue;
		int p=ans[v];
		while(p!=x)
		{
			if(max(msiz[p],siz[x]-siz[p])<=siz[x]/2)
			{
				ans[x]=p;
				break;
			}
			else p=f[p];
		}
	}
}
signed main()
{
	cin>>n>>q;
	for(int i=2;i<=n;i++)
	{
		int x;cin>>x;
		add(x,i),add(i,x);
	}
	dfs(1,0);
	while(q--)
	{
		int x;cin>>x;
		cout<<ans[x]<<endl;
	}
	return 0;
}