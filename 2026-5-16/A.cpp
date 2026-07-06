#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=100005;
int n,m,Q,X,Y,Z,ans;
vector<int> a[N],t[N];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=m;i++)a[i].resize(n+5);
	for(int j=1;j<=n;j++)
		for(int i=1;i<=m;i++)
		{
			char ch;cin>>ch;
			a[i][j]=ch-'0';
		}
	for(int i=1;i<=m;i++)
	{
		int l[2]={};
		for(int j=1;j<=n;j++)
		{
			t[j].push_back(l[a[i][j]^1]);
			l[a[i][j]]=j;
		}
	}
	for(int i=1;i<=n;i++)sort(t[i].begin(),t[i].end());
	cin>>Q>>X>>Y>>Z;
	int A=1,B=n,q=0;
	for(int i=1;i<=Q;i++)
	{
		int L=min(A,B),R=max(A,B);
		q=lower_bound(t[R].begin(),t[R].end(),L)-t[R].begin();
		ans+=q;
		int nA=(A*X+q*Y+Z)%n+1,nB=(B*Y+q*Z+X)%n+1;
		A=nA,B=nB;
	}
	cout<<ans<<endl;
	return 0;
}
