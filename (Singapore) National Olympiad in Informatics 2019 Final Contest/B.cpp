#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e7+10;
int n,m,tot=0,cnt=0;
pii d[N],e[N];
struct node{int l,r;};
signed main()
{
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		vector<int> b;
		int k,l=1,r=m;cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x;cin>>x;
			b.push_back(x);
			l+=x;
		}
		if(l>r)continue;
		vector<node> v;
		v.push_back({l,r});
		for(int j=k-1;j>=0;j--)
		{
			l-=b[j],r-=b[j];
			v.push_back({l,r});
		}
		for(int j=v.size()-1;j>=0;j--)
		{
			int nowl=v[j].l,nowr=v[j].r,jj=j;
			while(jj>=0&&v[jj].l<=nowr)nowr=v[jj].r,jj--;
			//~ cout<<nowl<<","<<nowr<<"!!"<<endl;
			d[++tot]=pii(nowl,1);
			d[++tot]=pii(nowr+1,-1);
			j=jj+1;
		}
	}
	int now=0,ans=0;
	sort(d+1,d+1+tot);
	for(int i=1;i<=tot;i++)
	{
		now+=d[i].second;
		if(d[i].first!=d[i+1].first&&now==n)
			ans+=d[i+1].first-d[i].first;
	}
	cout<<m-ans<<endl;
	return 0;
}
/*
11 3
2 2 3
1 7
2 4 1


3
*/
