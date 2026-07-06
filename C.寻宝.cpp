// Version 1.0
#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1000;
int n, W, w[N], v[N], dp[N][N],ans=0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> W;
    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            for(int k=0;k*w[i]<=j;k++)
            {
                dp[i][j]=max(dp[i][j],dp[i-1][j-k*w[i]]+k*v[i]-(k-1)*k/2);
                // printf("k=%lld,%lld\n",j,dp[i-1][j-k*w[i]]+k*v[i]-(k-1)*k/2);
            }
            ans=max(ans,dp[i][j]);
            // printf("dp[%lld][%lld]=%lld\n",i,j,dp[i][j]);
        }
    }
    cout<<ans;
    return 0;
}