#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=14;
int l,r,mi[N]={1ll},f[N],ansl[10],ansr[10];
void cal(int x,int *ans)
{
	int cnt=0,a[N]={0},tmp=x;
	while(x)a[++cnt]=x%10,x/=10;
	for(int i=cnt;i>=1;i--)
	{
		for(int j=0;j<a[i];j++)ans[j]+=mi[i-1];
		ans[0]-=mi[i-1];
		tmp-=a[i]*mi[i-1],ans[a[i]]+=tmp+1;
		for(int j=0;j<10;j++)ans[j]+=f[i-1]*a[i];
	}
}
signed main()
{ 
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for(int i=1;i<N;i++)mi[i]=mi[i-1]*10;
	for(int i=1;i<N;i++)f[i]=f[i-1]*10+mi[i-1];
	cin>>l>>r;
	cal(r,ansr),cal(l-1,ansl);
	// for(int i=0;i<10;i++)
	// 	cout<<ansl[i]<<" ";
	// cout<<endl;
	// for(int i=0;i<10;i++)
	// 	cout<<ansr[i]<<" ";
	// cout<<endl;
	for(int i=0;i<10;i++)
		cout<<ansr[i]-ansl[i]<<" ";
	return 0;
}