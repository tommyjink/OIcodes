#include<bits/stdc++.h>
#include "citymapping.h"
using namespace std;
typedef long long ll;
const int N=1e3+10;
int rt=1,cnt=0;
ll d[N][N];
struct node{int x,y,z;}ans[N*2];
// ll get_distance(int x,int y)
// {
// 	cout<<x<<","<<y<<":";
// 	int res;cin>>res;return res;
// }
inline ll dis(int x,int y)
{
	if(x==y)return 0;
	if(x>y)swap(x,y);
	if(d[x][y])return d[x][y];
	return d[x][y]=get_distance(x,y);
}
void solve(int rt,vector<int> &a)
{
	vector<int> b,c;
	b.push_back(a[0]);
	int k=a.size();
	for(int i=1;i<k;i++)
		if(dis(a[0],a[i])==dis(rt,a[0])+dis(rt,a[i]))
			c.push_back(a[i]);
		else b.push_back(a[i]);
	int now=b[0];
	for(int i:b)if(dis(rt,i)<dis(rt,now))
		now=i;
	ans[++cnt]={rt,now,(int)dis(rt,now)};
	vector<int> bb;
	for(int i:b)if(i!=now)bb.push_back(i);
	if(bb.size())solve(now,bb);
	if(c.size())
	{
		now=c[0];
		for(int i=0;i<c.size();i++)
			if(dis(rt,c[i])<dis(rt,now))
				now=c[i];
		ans[++cnt]={rt,now,(int)dis(rt,now)};
		vector<int> cc;
		for(int i:c)if(i!=now)cc.push_back(i);
		if(cc.size())solve(now,cc);
	}
}
void find_roads(int n, int q, int A[], int B[], int W[]) {
	for(int i=1;i<=n;i++)
		if(dis(1,i)>dis(1,rt))rt=i;
	vector<int> a;
	for(int i=1;i<=n;i++)
		a.push_back(i);
	solve(rt,a);
	for(int i=1;i<=cnt;i++)
		A[i-1]=ans[i].x,
		B[i-1]=ans[i].y,
		W[i-1]=ans[i].z;
	return;
}
// signed main()
// {
// 	int a[100],b[100],c[100];
// 	find_roads(4,1000,a,b,c);
// 	for(int i=1;i<=3;i++)
// 		cout<<a[i]<<","<<b[i]<<","<<c[i]<<endl;
// }
