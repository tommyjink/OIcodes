#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],b[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    b[1]=max(a[1],a[n]);
    for(int i=1;i<=n-1;i++)
        b[i+1]=max(a[i],a[i+1]);
    sort(b+1,b+1+n);
    for(int i=1;i<=n;i++)
        b[i]+=b[i-1];
    cout<<b[n-1]<<endl;
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