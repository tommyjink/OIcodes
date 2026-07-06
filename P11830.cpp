#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl "\n"
using namespace std;
const int N=1e6+100;
int n;
pii a[N],c[N];
bool check1(int mid)
{
    int sum=0,sum1=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i].first>mid)sum1+=c[i].first;
        else sum+=c[i].second;
    }
    return sum>=(sum+sum1+1)/2;
}
bool check2(int mid)
{
    int sum=0,sum1=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i].second<mid)sum+=c[i].first;
        else sum1+=c[i].second;
    }
    return sum<(sum+sum1+1)/2;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>c[i].first>>c[i].second>>a[i].first>>a[i].second;
    // cout<<check2(3)<<endl;
    int l=0,r=1e9;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(check1(mid))r=mid;
        else l=mid+1;
    }
    int L=l;l=0,r=1e9;
    while(l<r)
    {
        int mid=(l+r+1)>>1;
        if(check2(mid))l=mid;
        else r=mid-1;
    }
    int R=l,ans=0,now=L-1;
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        ans+=(max(min(R,a[i].second)-max(a[i].first,now+1)+1,0ll));
        now=max(now,a[i].second);
    }
    // cout<<L<<","<<R<<endl;
    cout<<ans<<endl;

}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _,T;
    cin>>_>>T;
    while(T--)solve();
    return 0;
}