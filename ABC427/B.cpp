#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int cal(int x)
{
    int res=0;
    while(x)
    {
        res+=x%10;
        x/=10;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    int ans=1;
    for(int i=2;i<=n;i++)
    {
        ans=ans+cal(ans);
    }
    cout<<ans<<endl;
    return 0;
}