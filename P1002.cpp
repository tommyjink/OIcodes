#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=50;
int n,m,dp[N][N],x,y;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>x>>y;
    dp[0][0]=1;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==x&&j==y)continue;
            if(abs(i-x)==1&&abs(j-y)==2)continue;
            if(abs(i-x)==2&&abs(j-y)==1)continue;
            if(i!=0)dp[i][j]+=dp[i-1][j];
            if(j!=0)dp[i][j]+=dp[i][j-1];
        }
    }
    cout<<dp[n][m];
    return 0;
}