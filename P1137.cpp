#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,tot=0,head[N];
int mdis[N],incnt[N];
struct node
{
	int to,next;
}e[N*2];
void add(int x,int y)
{
	e[++tot]=(node){y,head[x]};
	head[x]=tot;
}
void topo()
{
	queue<int> q;
	for(int i=1;i<=n;i++)
		if(!incnt[i])
			q.push(i),mdis[i]=1;
	while(!q.empty())
	{
		int t=q.front();q.pop();
		for(int i=head[t];i;i=e[i].next)
		{
			int v=e[i].to;
			if(--incnt[v]==0)
				q.push(v),mdis[v]=max(mdis[v],mdis[t]+1);
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
		incnt[y]++;
	}
	topo();
	for(int i=1;i<=n;i++)
		cout<<mdis[i]<<endl;
	return 0;
}