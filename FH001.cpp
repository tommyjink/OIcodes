#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,k,a[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i],a[i]+=a[i-1];
        if(i>=k)ans=max(ans,a[i]-a[i-k]);
    }
    cout<<ans<<endl;
    return 0;
}