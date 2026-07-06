#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,dp[N][4];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    dp[1][0]=dp[1][1]=dp[1][2]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i][0]=dp[i-1][1]+dp[i-1][0];
        dp[i][1]=dp[i-1][0]+dp[i-1][1]+dp[i-1][2];
        dp[i][2]=dp[i-1][1]+dp[i-1][2];
    }
    cout<<dp[n][0]+dp[n][1]+dp[n][2];
    return 0;
}