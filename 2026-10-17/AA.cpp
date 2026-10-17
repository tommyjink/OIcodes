#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N];
bool check(int mid)
{
    for(int i=1;i<=min(n,(n>>1)<<1);i++)
        if(i>1&&a[i]+mid*i<a[i-1]+mid*(i-1))return false;
    if((n&1)&&a[n]<a[n-1]+mid*(n-1))return false;
    return true;
}
void solve()
{
    cin>>n;
    int mx=0;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=2;i<=(n>>1)<<1;i++)
        mx=max(mx,a[i-1]-a[i]);
    if((n&1)&&a[n-1]+mx*(n-1)>a[n])cout<<"-1"<<endl;
    else cout<<mx<<endl;
    // int l=0,r=1e12;
    // while(l<r)
    // {
    //     int mid=(l+r)>>1;
    //     if(check(mid))r=mid;
    //     else l=mid+1;
    // }
    // if(l>=1e12)cout<<"-1"<<endl;
    // else cout<<l<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}