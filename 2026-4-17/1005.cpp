#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
void solve()
{
    int n;cin>>n;
    if(n&1)cout<<__builtin_popcountll(n)-1<<endl;
    else cout<<__builtin_popcountll(n)+1<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}