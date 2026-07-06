#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,a[N];
int calc(int len,int x)
{
    if(len<x)return 0;
    int k=0;
    while((len>>k)>=2*x)k++;
    int cnt=1ll<<k;
    int q=len>>k;
    int r=len&(cnt-1);
    int res=0;
    if(q>=x)res+=cnt-r;
    if(r>0)
    {
        if(q+1>=x)
        {
            if(q+1<2*x)res+=r;
            else res+=2*r;
        }
    }
    return res;
}
bool check(int x)
{
    if(x==0)return true;
    int target=(n+m+1)/2;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        cnt+=calc(a[i],x);
        if(cnt>=target)return true;
    }
    return cnt>=target;
}
void solve()
{
    cin>>n>>m;
    int mx=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    int l=1,r=mx,ans=1;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}