#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],b[N],c[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]+=a[i-1];
        b[i]=i*i+i-a[i];
        c[i]=-i*i+i+a[i-1];
    }
    for(int i=n-1;i>=1;i--)
        b[i]=max(b[i],b[i+1]);
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=max(ans,a[n]+c[i]+b[i]);
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