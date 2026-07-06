#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,L,Q[N],head=1,tail=1;
double sum[N],dp[N];
double c[N];
inline double a(int i){return sum[i]+i;}
inline double b(int i){return sum[i]+i+L+1;}
inline double x(int i){return b(i);}
inline double y(int i){return dp[i]+b(i)*b(i);}
inline double slope(int i,int j){return (y(i)-y(j))/(x(i)-x(j));}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>L;
	for(int i=1;i<=n;i++)
		cin>>sum[i],sum[i]+=sum[i-1];
	for(int i=1;i<=n;i++)
	{
		while(head<tail&&slope(Q[head],Q[head+1])<2.0*a(i))head++;
		dp[i]=dp[Q[head]]+(a(i)-b(Q[head]))*(a(i)-b(Q[head]));
		while(head<tail&&slope(Q[tail-1],Q[tail])>slope(i,Q[tail-1]))tail--;
		Q[++tail]=i;
	}
	cout<<(int)dp[n]<<endl;
	return 0;
}