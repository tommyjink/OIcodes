#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,a[1000000];
int ans=0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i&1)ans+=a[i];
    }
    cout<<ans<<endl;
    return 0;
}