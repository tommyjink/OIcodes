#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=n-1;i>=1;i--)
        a[i]+=a[i+1];
    sort(a+2,a+1+n);
    int ans=a[1];
    cout<<a[1]<<" ";
    for(int i=n;i>=2;i--)
    {
        ans+=a[i];
        cout<<ans<<" ";
    }
    cout<<endl;
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