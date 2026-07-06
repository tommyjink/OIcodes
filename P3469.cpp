#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
int n,m,head[maxn],num=0;
int dfn[maxn],low[maxn],size[maxn],tot=0;
long long ans[maxn];
bool cut[maxn];
struct node{
	int v,nex;
}e[maxn];
void add(int u,int v)
{
	e[++num].v=v;
	e[num].nex=head[u];
	head[u]=num;
}
void tarjan(int u)
{
	dfn[u]=low[u]=++tot;
	size[u]=1;
	int flag=0,sum=0;
	for(int i=head[u];i;i=e[i].nex)
	{
		int v=e[i].v;
		if(!dfn[v])
		{
			tarjan(v);
			size[u]+=size[v];
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u])
			{
				ans[u]+=(long long)size[v]*(n-size[v]);
				sum+=size[v];
				flag++;
				if(u!=1||flag>1) cut[u]=true;
			}
		}
		else low[u]=min(low[u],dfn[v]);
	}
	if(!cut[u]) ans[u]=2*(n-1);
	else ans[u]+=(long long)(n-sum-1)*(sum+1)+(n-1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y),add(y,x);
	}
	tarjan(1);
	for(int i=1;i<=n;i++) printf("%lld\n",ans[i]);
	return 0;
}