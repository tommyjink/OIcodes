#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        int s,k,m,ans=0;
        cin>>s>>k>>m;
        m%=2*k;
        if(m<k)ans=s-m;
        else ans=min(s,k)-(m-k);
        cout<<max(0ll,ans)<<endl;
    }
    return 0;
}