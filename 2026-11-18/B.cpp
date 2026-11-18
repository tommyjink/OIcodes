#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=610,INF=1e16;
int n,c[N],w[N];
int dp[N][N][2];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>c[i]>>w[i];
    for(int i=1;i<=n;i++)
        dp[i][i][0]=dp[i][i][1]=w[i];
    for(int len=2;len<=n;len++)
    {
        for(int i=1;i<=n-len+1;i++)
        {
            int j=i+len-1;
            dp[i][j][0]=dp[i][j][1]=INF;
            if(c[i]!=c[j])
                dp[i][j][1]=min(dp[i][j][1],dp[i+1][j-1][0]+abs(w[i]-w[j]));
            else 
            {
                dp[i][j][0]=min(dp[i][j][0],dp[i+1][j-1][0]+abs(w[i]-w[j]));
                dp[i][j][1]=min(dp[i][j][1],dp[i+1][j-1][1]+abs(w[i]-w[j]));
            }
            for(int k=i;k<j;k++)
                dp[i][j][0]=min(dp[i][j][0],dp[i][k][0]+dp[k+1][j][0]),
                dp[i][j][1]=min({dp[i][j][1],dp[i][k][1]+dp[k+1][j][0],dp[i][k][0]+dp[k+1][j][1]});
            // cout<<i<<","<<j<<":"<<dp[i][j][0]<<","<<dp[i][j][1]<<endl;
        }
    }
    cout<<min(dp[1][n][0],dp[1][n][1])<<endl;
    return 0;
}