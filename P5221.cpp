#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1000005;
const int P=104857601;
int n,pri[N],tot;
bool vis[N];
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
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	int fac=1;
	for(int i=2;i<=n;i++)fac=fac*i%P;
	int ans=qpow(fac,2*n%(P-1));
	int den=1;
	for(int i=2;i<=n;i++)
	{
		if(!vis[i])pri[++tot]=i;
		for(int j=1;j<=tot&&i*pri[j]<=n;j++)
		{
			vis[i*pri[j]]=1;
			if(i%pri[j]==0)break;
		}
	}
	for(int j=1;j<=tot;j++)
	{
		int p=pri[j],cnt=0;
		for(int t=p;t<=n;t*=p)cnt=(cnt+(n/t)*(n/t))%(P-1);
		den=den*qpow(p,cnt)%P;
	}
	den=den*den%P;
	ans=ans*qpow(den,P-2)%P;
	cout<<ans<<endl;
	return 0;
}