#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,ans=0,p=998244353;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        if((i&1)||(i%4==0))
            ans=(ans+i)%p;
    }
    cout<<ans<<endl;
    return 0;
}