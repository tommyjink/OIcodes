#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n;
void solve()
{
    cin>>n;
    int ans=0;
    for(int l=1,r=0;l<=n;l=r+1)
    {
        int k=n/l;
        r=n/k;
        ans+=k*(r-l+1);
    }
    cout<<ans<<endl;
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