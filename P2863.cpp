#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6;
int n,m,tot=0,num=0,cnt=0,ans=0;
int head[N],in[N],col[N];
int dfn[N],low[N],cc[N];
struct node
{
	int to,next;
}e[N*2];
void add(int x,int y)
{
	e[++tot]=(node){y,head[x]};
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
		else if(in[v])low[x]=min(low[x],low[v]);
	}
	if(dfn[x]==low[x])
	{
		cnt++;
		while(!stk.empty())
		{
			int t=stk.top();stk.pop();
			in[t]=false,col[t]=cnt;
			if(++cc[cnt]==2)ans++;
			if(x==t)break;
		}
	}
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
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])tarjan(i);
	cout<<ans<<endl;
	return 0;
}