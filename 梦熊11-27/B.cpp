#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int n,q,num[N];
struct node
{
	int p,t,x;
}a[N];
signed main()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].p>>a[i].t>>a[i].x;
		num[++num[0]]=a[i].p;
	}
		
	
	return 0;
}