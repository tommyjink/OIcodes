#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=20,M=5e2+10;
int NUM,n,K;
string s[N],t;
int lens[N],m;
map<string,int> dir;
int f[M][M][M];
signed main()
{
	cin>>NUM>>n>>K;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		lens[i]=s[i].length();
		for(int i=0;i<=lens[i];i++)
			dir[s.substr(i)]=true;
	}
	cin>>t;m=t.length();
	for(int len=1;len<=m;i++)
	{
		for(int i=0;i<m+len-1;i++)
		{
			int j=i=len-1;
			if(mp[t.substr(i,len)])
				f[i][j][1]=true;
			for(int k=i;k<=j;k++)
			{
				
			}
		}
	}
	return 0;
}