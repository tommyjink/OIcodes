#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6;
int n,m,tot=0,head[N];
int incnt[N],mdis[N];
vector<int> tpx;
struct node
{
	int to,next,val;
}e[N*2];
void add(int x,int y,int z)
{
	e[++tot]=(node){y,head[x],z};
	head[x]=tot;
}
void topo()
{
	queue<int> q;
	for(int i=1;i<=n;i++)
		if(!incnt[i])q.push(i);
	while(!q.empty())
	{
		int t=q.front();q.pop();
		tpx.push_back(t);
		for(int i=head[t];i;i=e[i].next)
		{
			int v=e[i].to;
			if(--incnt[v]==0)
				q.push(v);
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
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z);
		incnt[y]++;
	}
	topo();
	memset(mdis,128,sizeof(mdis));
	mdis[1]=0;
	for(int i=0;i<(int)tpx.size();i++)
	{
		int x=tpx[i];
		for(int j=head[x];j;j=e[j].next)
		{
			int v=e[j].to,val=e[j].val;
			mdis[v]=max(mdis[v],mdis[x]+val);
		}
	}
	if(mdis[n]>-1e5)cout<<mdis[n]<<endl;
	else cout<<"-1"<<endl;
	return 0;
}