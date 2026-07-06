#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int n,m,c[N],L[N],R[N];
int tot=0,siz[N],son[N];
int id[N],cnt[N],cnttot=0;
int ans[N];
vector<int> e[N];
void add(int x)
{
	if(cnt[c[x]]==0)cnttot++;
	cnt[c[x]]++;
}
void del(int x)
{
	cnt[c[x]]--;
	if(cnt[c[x]]==0)cnttot--;
}
void dfs1(int x,int fa)
{
	L[x]=++tot,siz[x]=1,id[tot]=x;
	for(int i=0;i<(int)e[x].size();i++)
	{
		int v=e[x][i];
		if(v==fa)continue;
		dfs1(v,x);
		siz[x]+=siz[v];
		if(!son[x]||siz[v]>siz[son[x]])
			son[x]=v;
	}
	R[x]=tot;
}
void dfs2(int x,int fa,bool keep)
{
	for(int i=0;i<(int)e[x].size();i++)
	{
		int v=e[x][i];
		if(v==fa||v==son[x])continue;
		dfs2(v,x,false);
	}
	if(son[x])dfs2(son[x],x,true);
	for(int i=0;i<(int)e[x].size();i++)
	{
		int v=e[x][i];
		if(v==fa||v==son[x])continue;
		for(int j=L[v];j<=R[v];j++)
			add(id[j]);
	}
	add(x);
	ans[x]=cnttot;
	if(!keep)
		for(int i=L[x];i<=R[x];i++)
			del(id[i]);
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
		cin>>c[i];
	dfs1(1,0);
	dfs2(1,0,true);
	cin>>m;
	while(m--)
	{
		int x;
		cin>>x;
		cout<<ans[x]<<endl;
	}
	return 0;
}