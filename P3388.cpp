#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,tot=0,num=0;
int head[N],dfn[N],low[N];
int tag[N];
vector<int> ans;
struct node
{
	int to,next;
}e[N*2];
void add(int x,int y)
{
	e[++tot]=(node){y,head[x]};
	head[x]=tot;
}
void tarjan(int x,int rt)
{
	int siz=0;dfn[x]=low[x]=++num;
	for(int i=head[x];i;i=e[i].next)
	{
		int v=e[i].to;
		if(!dfn[v])
		{
			tarjan(v,rt),low[x]=min(low[x],low[v]),siz++;
			if(low[v]>=dfn[x]&&x!=rt)tag[x]=true;
		}
		else low[x]=min(low[x],dfn[v]);
	}
	if(siz>1&&x==rt)tag[x]=true;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])tarjan(i,i);
	for(int i=1;i<=n;i++)
		if(tag[i])ans.push_back(i);
	cout<<(int)ans.size()<<endl;
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
	return 0;
}