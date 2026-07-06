#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6;
int n,q,a[N],b[N];
int tot,t[N*4],L[N],R[N];
inline int lowbit(int x)
{
	return x&(-x);
}
void add(int x,int d)
{
	for(int i=x;i<=n;i+=lowbit(i))
		t[i]+=d;
}
int query(int x)
{
	int res=0;
	for(int i=x;i>0;i-=lowbit(i))
		res+=t[i];
	return res;
}
signed main()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	tot=unique(b+1,b+1+n)-b-1;
	for(int i=1;i<=n;i++)
		a[i]=lower_bound(b+1,b+1+tot,a[i])-b;
	// for(int i=1;i<=n;i++)
		// cout<<a[i]<<" ";
	for(int i=1;i<=n;i++)
	{
		L[i]=i-1-query(a[i]-1);
		add(a[i],1);
	}
	memset(t,0,sizeof(t));
	for(int i=n;i>=1;i--)
	{
		R[i]=n-i-query(a[i]-1);
		add(a[i],1);
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		// printf("L[%lld]=%lld,R:%lld\n",x,L[x],R[x]);
		int rkx=L[x]+R[x]+1;
		if(rkx<=y)cout<<"0"<<endl;
		else
		{
			int del=rkx-y,ld=0,rd=0;
			// cout<<del<<"!!"<<endl;
			// printf("%lld,%lld\n",L[x],R[x]);
			if(del/2<=L[x])
				ld+=del/2,del-=del/2;
			else del-=L[x],ld+=L[x];
			if(del<=R[x])
				rd+=del,del=0;
			else rd+=R[x],del-=R[x];
			if(del)ld+=del;
			cout<<max(ld,rd)<<endl;
		}
	}
	return 0;
}