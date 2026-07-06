#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("dance.in","r",stdin);
    freopen("dance.out","w",stdout);
    int n;cin>>n;
    if(n&1)cout<<((n+2)/2)*((n+2)/2)+((n+2)/2+1)*((n+2)/2+1)-1;
    else cout<<(n/2+1)*(n/2+1);
    return 0;
}