#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int a[N],b[N],c[N];
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],b[i]=c[i]=0;
    for(int i=1;i<=n;i++)
        b[i]=b[i-1]+a[i],
        c[i]=max(c[i-1],a[i]);
    for(int i=1;i<=n;i++)
        cout<<b[n]-b[n-i+1]+c[n-i+1]<<" ";
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