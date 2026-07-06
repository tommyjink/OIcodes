#include<bits/stdc++.h>
#define int long long
using namespace std;
priority_queue<int,vector<int>,greater<int> > q;
int n,a[100005],ans=0;
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		if(q.empty()||q.top()>=a[i])
		{
			q.push(a[i]);
			continue;
		}
		q.pop();
		q.push(a[i]);
		ans++;
	}
	cout<<n-ans;
	return 0;
}