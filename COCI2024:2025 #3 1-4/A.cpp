#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
// const int N=1e3;
int n,ans=1e9;
struct node
{
	int l,r;
};
vector<node> A;
vector<node> B;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string s;cin>>s;
		int a,b,c,d,x,y;
		scanf("%lld:%lld--%lld:%lld",&a,&b,&c,&d);
		x=a*60+b,y=c*60+d;
		if(x>y)y+=24*60;
		// cout<<x<<" "<<y<<endl;
		if(s[0]=='Z')A.push_back((node){x,y});
		else B.push_back((node){x,y});
	}
	for(int i=0;i<(int)A.size();i++)
	{
		for(int j=0;j<(int)B.size();j++)
		{
			int tmp=B[j].r-A[i].l+1;
			if(B[j].l<=A[i].r)tmp+=24*60;
			ans=min(ans,tmp);
		}
	}
	if(ans==1e9)
	{
		cout<<"NEMOGUCE";
		return 0;
	}
	cout<<ans/60<<":";
	if(ans%60<10)cout<<"0";
	cout<<ans%60;
	return 0;
}