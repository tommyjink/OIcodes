#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=3000005;
const int P=998244353;
int n,k,m,fac[N],inv[N];
int qpow(int x,int y)
{
	int res=1;
	while(y)
	{
		if(y&1)res=res*x%P;
		x=x*x%P;
		y>>=1;
	}
	return res;
}
int C(int n,int m)
{
	if(m<0||m>n)return 0;
	return fac[n]*inv[m]%P*inv[n-m]%P;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>k>>m;
	int lim=n+k;
	fac[0]=1;
	for(int i=1;i<=lim;i++)fac[i]=fac[i-1]*i%P;
	inv[lim]=qpow(fac[lim],P-2);
	for(int i=lim;i>=1;i--)inv[i-1]=inv[i]*i%P;
	int ans1=0,ans2=0;
	for(int i=0;i<=min(k/(m+1),n);i++)
	{
		int now=C(n,i)*C(k-i*(m+1)+n-1,n-1)%P;
		if(i&1)ans1=(ans1-now+P)%P;
		else ans1=(ans1+now)%P;
	}
	for(int i=0;i<=min((k-1)/m,n);i++)
	{
		int now=C(n,i)*C(k-1-i*m+n-1,n-1)%P;
		if(i&1)ans2=(ans2-now+P)%P;
		else ans2=(ans2+now)%P;
	}
	cout<<(ans1-ans2+P)%P<<endl;
	return 0;
}
