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
    // for(int i=0;i<=mx;i++)
    //     cout<<check(i)<<" ";
    // cout<<endl;
    int l=0,r=mx;
    while(r-l>2)
    {
        int len=(r-l)/3;
        int p1=l+len,p2=l+len*2;
        // cout<<l<<"~"<<r<<":"<<p1<<","<<p2<<endl;
        if(check(p1)<check(p2))r=p2;
        else l=p1;
    }
    int ans=1e18;
    // cout<<l<<","<<r<<endl;
    for(int i=max(0ll,l-10);i<=min(mx,l+10);i++)
    {
        ans=min(ans,check(i));
        // cout<<i<<":"<<check(i)<<endl;
    }
    for(int i=0;i<=mx;i++)
        cout<<i<<":"<<check(i)<<endl;
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