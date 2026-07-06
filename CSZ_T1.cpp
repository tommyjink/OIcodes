#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
string s;
int len,lst[N];
int ans=0,l[N],r[N];
signed main()
{
	cin>>s;
	len=s.length();
	s=' '+s;
	for(int i=1;i<=len;i++)
	{
		r[lst[s[i]-'a']]=i;
		l[i]=lst[s[i]-'a'];
		lst[s[i]-'a']=i;
	}
	for(int i=1;i<=len;i++)
	{
		if(r[i]==0)r[i]=len+1;
		ans+=(r[i]-i-1+1)*(i-l[i]-1+1);
		// cout<<i<<" "<<(r[i]-i-1+1)<<" "<<(i-l[i]-1+1)<<endl;
	}
	cout<<ans;
	return 0;
}