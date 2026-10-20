#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,x,y,a[N],b[N];
int check(int mid)
{
    int res=mid*x,now=0;
    for(int i=1;i<=n;i++)
    {
        now=max(0ll,now-(a[i]-a[i-1]));
        int cnt=max(0ll,b[i]-mid);
        res+=max(0ll,cnt-now)*y;
        now=max(now,cnt);
    }
    return res;
}
void solve()
{
    cin>>n>>x>>y;
    int mx=0;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i],mx=max(mx,b[i]);
    int ans=1e18;
    // cout<<l<<","<<r<<endl;
    for(int i=0;i<=mx;i++)
        ans=min(ans,check(i));
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}