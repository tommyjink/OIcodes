#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6;
int n,a[N],dp[N][2];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    dp[0][0]=0,dp[0][1]=-1e13;
    for(int i=1;i<=n;i++)
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]+2*a[i]),
        dp[i][1]=max(dp[i-1][1],dp[i-1][0]+a[i]);
    cout<<max(dp[n][0],dp[n][1]);
    return 0;
}