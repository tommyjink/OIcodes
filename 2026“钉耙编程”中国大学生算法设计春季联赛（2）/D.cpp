#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,k;
void solve()
{
    cin>>n>>k;
    if(n==2)
    {
        cout<<2<<' '<<k+2<<endl;
        return;
    }
    cout<<2<<' '<<k+n;
    for(int i=3;i<=n;i++) cout<<' '<<1;
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
