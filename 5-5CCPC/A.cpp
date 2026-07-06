#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e3;
int n,k;
int t[N],l[N],w[N];
int check(int x)
{
    int res=0;
    for(int i=1;i<=n;i++)
    {
        int X=x/(t[i]*l[i]+w[i]),Y=x%(t[i]*l[i]+w[i]);
        res+=X*l[i]+min(l[i],Y/t[i]);
        if(res>=k)return false;
    }        
    return true;
}
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>t[i]>>l[i]>>w[i];
    int l=0,r=2e18;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(check(mid))l=mid+1;
        else r=mid;
    }
    cout<<l<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}