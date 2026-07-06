#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=1e6+10;
int n,k,tag[N],now[N];
vector<pii> r[N];
vector<int> u[N];
queue<pii> q[N];
queue<int> Q;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			int x;cin>>x;
			r[j].push_back(pii(x,i));
		}
	}
	for(int i=1;i<=n;i++)
	{
		u[i].push_back(0);
		for(int j=1;j<=k;j++)
		{
			int x;cin>>x;
			u[i].push_back(x);
		}
	}
	for(int i=1;i<=k;i++)
	{
		sort(r[i].begin(),r[i].end());
		for(auto j:r[i])q[i].push(j);
	}
	for(int i=1;i<=k;i++)
	{
		while(!q[i].empty()&&!q[i].front().first)
		{
			int id=q[i].front().second;
			tag[id]++;
			if(tag[id]==k)Q.push(id);
				// for(int j=1;j<=k;j++)
				// 	now[j]+=u[id][j];
			q[i].pop();
		}
	}
	int ans=0;
	while(!Q.empty())
	{
		ans++;
		int x=Q.front();Q.pop();
		for(int i=1;i<=k;i++)
		{
			now[i]+=u[x][i];
			while(!q[i].empty()&&q[i].front().first<=now[i])
			{
				int id=q[i].front().second;
				tag[id]++;
				if(tag[id]==k)Q.push(id);
				q[i].pop();
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
