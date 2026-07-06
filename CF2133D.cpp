#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],f[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    f[1]=a[1];
    for(int i=2;i<=n;i++)
        f[i]=min(f[i-1]+a[i]-1,f[i-2]+a[i-1]+a[i]-min(a[i],i-1));
    cout<<f[n]<<endl;
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