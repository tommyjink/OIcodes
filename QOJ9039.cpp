#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
void solve()
{
    int l,r;cin>>l>>r;
    int p=l+(l%2==0);
    if(p*2<=r)
    {
        if(l&1)cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }
    else
    {
        if((r-l+1)&1)cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}