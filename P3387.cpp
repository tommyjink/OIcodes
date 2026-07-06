#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6;
int n,m,tot=0,num=0,cnt=0,ans=0;
int eval[N],head[N],col[N],inc[N];
int dfn[N],low[N],in[N],val[N],mdis[N];
vector<int> edge[N],tpx;
struct node
{
	int from,to,next;
}e[N*2];
void add(int x,int y)
{
	e[++tot]=(node){x,y,head[x]};
	head[x]=tot;
}
stack<int> stk;
void tarjan(int x)
{
	dfn[x]=low[x]=++num;
	stk.push(x),in[x]=true;
	for(int i=head[x];i;i=e[i].next)
	{
		int v=e[i].to;
		if(!dfn[v])tarjan(v),low[x]=min(low[x],low[v]);
		else if(in[v])low[x]=min(low[x],dfn[v]);
	}
	if(low[x]==dfn[x])
	{
		cnt++;
		while(!stk.empty())
		{
			int t=stk.top();stk.pop();
			in[t]=false,col[t]=cnt;
			val[col[t]]+=eval[t];
			if(t==x)break;
		}
	}
}
void topo()
{
	queue<int> q;
	for(int i=1;i<=cnt;i++)
		if(!inc[i])q.push(i);
	while(!q.empty())
	{
		int t=q.front();q.pop();
		tpx.push_back(t);
		for(int i=0;i<(int)edge[t].size();i++)
		{
			int v=edge[t][i];
			if(--inc[v]==0)
				q.push(v);
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>eval[i];
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])tarjan(i);
	for(int i=1;i<=tot;i++)
	{
		int x=col[e[i].from],y=col[e[i].to];
		if(x!=y)edge[x].push_back(y),inc[y]++;
	}
	topo();
	// for(int i=1;i<=n;i++)
		// cout<<col[i]<<" ";
	// cout<<endl;
	// for(int i=1;i<=cnt;i++)
		// cout<<val[i]<<" ";
	// cout<<endl;
	for(int i=0;i<tpx.size();i++)
	{
		int x=tpx[i];
		mdis[x]=max(mdis[x],val[x]);
		for(int j=0;j<edge[x].size();j++)
		{
			int v=edge[x][j];
			mdis[v]=max(mdis[v],mdis[x]+val[v]);
		}
		ans=max(ans,mdis[x]);
	}
	cout<<ans<<endl;
	return 0;
}