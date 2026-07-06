#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+10;
int n,m,p;
struct matrix
{
	int m[N][N];
}a;
void print()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<a.m[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"________\n";
}
void init_matrix(matrix &x)
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			x.m[i][j]=1e9;
}
matrix operator *(const matrix &x,const matrix &y)
{
	matrix res;
	init_matrix(res);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				res.m[i][j]=min(res.m[i][j],x.m[i][k]+y.m[k][j]);
	return res;
} 
matrix quick_pow(matrix x,int k)
{
	matrix res;k--;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			res.m[i][j]=x.m[i][j];
	while(k)
	{
		if(k&1)res=res*x;
		k>>=1;
		x=x*x;
	}
	return res;
}
signed main()
{
	cin>>n;
	init_matrix(a);
	for(int i=1;i<=n-1;i++)
	{
		int x;cin>>x;
		a.m[i][i+1]=x;
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		a.m[x][y]=min(a.m[x][y],z);
	}
	cin>>p;
	a=quick_pow(a,p);
	// print();
	// a=a*a;
	// print();
	// a=a*a;
	// print();
	for(int i=1;i<=n;i++)
	{
		if(a.m[i][i]<1e9)
			cout<<a.m[i][i]<<endl;
		else cout<<"-1"<<endl;
	}
	return 0;
}