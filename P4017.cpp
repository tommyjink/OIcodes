#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6,P=80112002;
int n,m,head[N],tot=0;
int tpx[N],val[N],ans=0;
int incnt[N],outcnt[N];
vector<int> fr[N];
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
		if(!incnt[i])q.push(i),val[i]=1;
	while(!q.empty())
	{
		int t=q.front();q.pop();
		tpx[++tpx[0]]=t;
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
		int x,y;
		cin>>x>>y;
		add(x,y);
		fr[y].push_back(x);
		incnt[y]++;
		outcnt[x]++;
	}
	topo();
	for(int i=1;i<=n;i++)
		for(int j=0;j<(int)fr[tpx[i]].size();j++)
			val[tpx[i]]+=val[fr[tpx[i]][j]],val[tpx[i]]%=P;
	for(int i=1;i<=n;i++)
		if(outcnt[i]==0)ans=(ans+val[i])%P;
	cout<<ans<<endl;
	return 0;
}