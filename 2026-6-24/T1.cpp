#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],dp[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            dp[i]=max(dp[i],dp[j]+(a[j]&a[i]));
        }

    }
    cout<<dp[n]<<endl;
    return 0;
}