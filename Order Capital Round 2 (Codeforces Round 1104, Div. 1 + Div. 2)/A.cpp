#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N];
void solve()
{
    int ans=0;
    a[0]=1e9;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],a[i]=min(a[i],a[i-1]),ans+=a[i];
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