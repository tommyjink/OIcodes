#include<bits/stdc++.h>
#define int long long
#define lowbit(x) (x&(-x))
#define endl "\n"
using namespace std;
const int N=2e5+10;
int b[N],n,m,t[N],ans[N],tag[N];
void add(int x,int d){x++;for(;x<=n+1;x+=lowbit(x))t[x]+=d;}
int sum(int x){int res=0;x++;for(;x;x-=lowbit(x))res+=t[x];return res;}
struct node{int pos,time,val;}a[N];

bool cmp_val(node x,node y){return x.val<y.val;}
bool cmp_pos(node x,node y){return x.pos<y.pos;}
bool cmp_time(node x,node y){return x.time<y.time;}

void CDQ(int l,int r)
{
	if(l==r)return;
	int mid=(l+r)>>1;
	CDQ(l,mid);
	CDQ(mid+1,r);
	sort(a+l,a+1+mid,cmp_pos);
	sort(a+mid+1,a+1+r,cmp_pos);
	int i=l;
	for(int j=mid+1;j<=r;j++)
	{
		while(i<=mid&&a[i].pos<=a[j].pos)add(a[i].time,1),i++;
		ans[a[j].time]+=sum(a[j].time);
	}
	for(int j=l;j<i;j++)add(a[j].time,-1);
}

signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		a[b[i]].pos=i;
		a[b[i]].val=b[i];
	}
	for(int i=0;i<=n;i++)t[i]=0;
	for(int i=m;i>=1;i--)
	{
		int x;cin>>x;
		a[x].time=i; 
		tag[x]=true;
	}
	
	int cur = 0; 
	for(int i=1;i<=n;i++)
	{
		if(tag[b[i]])continue;
		add(b[i],1);
		cur += sum(n)-sum(b[i]);
	}
	for(int i=0;i<=n;i++) t[i]=0;
	for(int i=1;i<=n;i++) a[i].pos=-a[i].pos; 
	sort(a+1, a+1+n, cmp_val); 
	CDQ(1,n);
	for(int i=1;i<=n;i++) a[i].pos=-a[i].pos; 
	sort(a+1, a+1+n, cmp_val);
	reverse(a+1, a+1+n); 
	CDQ(1,n);
	vector<int> total(m + 1, 0);
	for(int i=1; i<=m; i++) {
		cur += ans[i];
		total[i] = cur;
	}
	for(int i=m; i>=1; i--) {
		cout << total[i] << endl;
	}
	
	return 0;
}
