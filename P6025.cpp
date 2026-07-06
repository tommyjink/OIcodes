#include<bits/stdc++.h>
#define int long long
#define lowbit(x) (x&(-x))
#define endl "\n"
using namespace std;
// int build(int k,int l,int r)
// {
//     if(l==r)return k;
//     int mid=(l+r)>>1;
//     return max(build(k*2,l,mid),build(k*2+1,mid+1,r));
// }
int build(int x,int y) {
	if(x==1) return y;
	if(x%2==0) return build(x/2,y*2+1);
	else if(lowbit(x/2)==x/2) return build(x/2+1,y*2);
	else return build(x/2,y*2+1);
}
int solve(int n)
{
    int now=1,res=0;
    while(now<=n)
    {
        int l=now;
        for(int i=35;i>=0;i--)
            if(now+(1ll<<i)<=n&&build(now+(1ll<<i),1)==build(now,1))
                now+=1ll<<i;
        if((now-l+1)&1)res^=build(now,1);
        now++;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int l,r;
    cin>>l>>r;
    cout<<(solve(r)^solve(l-1));
    return 0;
}