#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e7;
int n,k,a[N],ans1=-1e18,ans2=1e18;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i],a[i]+=a[i-1];
    for(int i=0;i<=n-k;i++)
    {
        ans1=max(ans1,a[i+k]-a[i]);
        ans2=min(ans2,a[i+k]-a[i]);
    }
    cout<<ans2<<" "<<ans1;
    return 0;
}