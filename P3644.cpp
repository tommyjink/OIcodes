#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5;
int n,head[N],tot=0;
int incnt[N];
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
		if(incnt[i]==0)q.push(i);
	while(!q.empty())
	{
		int t=q.front();q.pop();
		cout<<t<<" ";
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
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		while(1)
		{
			int j;cin>>j;
			if(!j)break;
			add(i,j),incnt[j]++;
		}
	}
	topo();
	return 0;
}