#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

void solve()
{
    int n;
    cin>>n;
    int ans=n;
    for(int i=2;i<=n-2;i++)
    {
        int j=n-i;
        ans=min(ans,abs(i-j));
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