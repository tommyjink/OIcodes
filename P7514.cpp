
#include <bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;

int n, m;
ll a[1000005], b[1000005], c[2000020];
ll mxl[1000005], mxr[1000005], mnl[1000005], mnr[1000005];

inline ll rd() {
	ll x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return x*f;
}

inline bool chk(ll L, ll R) {
	int l=0, r=n+1, Lp, Rp;
	while(l+1<r) {
		int mid=(l+r)>>1;
		if(a[mid]<L) l=mid; else r=mid;
	}
	Lp=l;
	l=0, r=n+1;
	while(l+1<r) {
		int mid=(l+r)>>1;
		if(a[mid]<=R) l=mid; else r=mid;
	}
	Rp=l;
	if(n-Rp+Lp>m) return 0;
	if((mxl[Lp]>R||mnl[Lp]<L)&&Lp) return 0;
	if((mxr[Rp+1]>R||mnr[Rp+1]<L)&&Rp!=n) return 0;
	return 1;
}

int main() {
	n=rd(); m=rd();
	a[n+1]=1e18;
	rep(i,1,n) a[i]=rd(),c[i]=a[i];
	rep(i,1,n) b[i]=rd(),c[i+n]=b[i];
	mnl[0]=mnr[n+1]=1e18;
	rep(i,1,n) mnl[i]=min(mnl[i-1],b[i]);
	rep(i,1,n) mxl[i]=max(mxl[i-1],b[i]);
	per(i,n,1) mnr[i]=min(mnr[i+1],b[i]);
	per(i,n,1) mxr[i]=max(mxr[i+1],b[i]);
	sort(c+1,c+2*n+1);
	ll ans=1e18;
	for(int i=1,j=1;i<=2*n&&j<=2*n;) {
		if(chk(c[i],c[j])) ans=min(ans,c[j]-c[i]),++i;
		else ++j;
	}
	printf("%lld\n",ans);
	return 0;
}


