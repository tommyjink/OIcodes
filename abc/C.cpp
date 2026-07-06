#include<bits/stdc++.h>
using namespace std;
int n,k,r[100];
int a[100];
void dfs(int pos,int cnt)
{
	if(pos>n)
	{
		if(cnt%k)return;
		for(int i=1;i<=n;i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<endl;
		return ;
	}
	for(int i=1;i<=r[pos];i++)
	{
		a[pos]=i;
		dfs(pos+1,cnt+i);
	}
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>r[i];
	dfs(1,0);
	return 0;
}