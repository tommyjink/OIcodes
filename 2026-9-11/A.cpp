#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=25;
int n,a[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1,u,v;i<n;i++)cin>>u>>v;
    cout<<(a[1]?"Si":"Yuan")<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
