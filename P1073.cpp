#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6;
int n,m,tot=0,num=0,cnt=0,tag=0;
int eval[N],dfn[N],head[N],low[N],inc[N],ans[N];
int in[N],col[N],maxval[N],minval[N],mind[N];
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
			maxval[cnt]=max(maxval[cnt],eval[t]);
			minval[cnt]=min(minval[cnt],eval[t]);
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
		for(int i=0;i<edge[t].size();i++)
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
	memset(minval,127,sizeof(minval));
	for(int i=1;i<=n;i++)
		cin>>eval[i];
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y);
		if(z==2)add(y,x);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])tarjan(i);
	for(int i=1;i<=tot;i++)
	{
		int x=col[e[i].from];
		int y=col[e[i].to];
		if(x!=y)edge[x].push_back(y),inc[y]++;
	}
	topo();
	// for(int i=1;i<=n;i++)
		// cout<<col[i]<<" ";
	// cout<<endl;
	// for(int i=1;i<=cnt;i++)
		// cout<<maxval[i]<<" ";
	// cout<<endl;
	
	for(int i=1;i<=cnt;i++)
		mind[i]=1e9,
		ans[i]=max(0ll,maxval[i]-minval[i]);
	mind[col[1]]=minval[col[1]];
	for(int i=0;i<tpx.size();i++)
	{
		int x=tpx[i];
		// cout<<x<<" ";
		if(mind[x]==1e9)continue;
		for(int j=0;j<edge[x].size();j++)
		{
			int v=edge[x][j];
			mind[v]=min(min(minval[v],mind[x]),mind[v]);
			ans[v]=max(ans[v],maxval[v]-mind[v]);
			ans[v]=max(ans[v],ans[x]);
		}
		// if(ans==99)
		// {
			// cout<<maxval[x]<<" "<<mind[x]<<endl;
			// cout<<x<<endl;
			// return 0;
		// }
	}
	// cout<<endl;
	cout<<ans[col[n]]<<endl;
	return 0;
}