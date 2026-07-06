#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5;
int n,head[N],tot=0,cnt=0;
int incnt[N],num=0;
map<int,int> mp,loc;
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
	for(int i=1;i<=num;i++)
		if(loc[i]&&!incnt[i])q.push(i);
	while(!q.empty())
	{
		int t=q.front();q.pop();cnt++;
		// cout<<t<<endl;
		for(int i=head[t];i;i=e[i].next)
		{
			int v=e[i].to;
			if(!loc[v])continue;
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
		int x,m;
		cin>>x>>m;
		if(!mp[x])mp[x]=++num;
		x=mp[x],loc[x]=true;
		while(m--)
		{
			int y;cin>>y;
			if(!mp[y])mp[y]=++num;
			y=mp[y];
			add(x,y),incnt[y]++;
			// cout<<x<<" "<<y<<endl;
		}
	}
	topo();
	// cout<<n<<"!"<<cnt<<endl;
	if(cnt!=n)cout<<n-cnt;
	else cout<<"YES"<<endl;
	return 0;
}