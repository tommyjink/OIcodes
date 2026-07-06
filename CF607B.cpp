#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=505;
int n,a[N],dp[N][N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // for(int i=1;i<=500;i++)
    //     cout<<"1 ";
    cin>>n;
    memset(dp,127/3,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==a[i-1])
            dp[i-1][i]=1;
        else dp[i-1][i]=2;
        dp[i][i]=1;
    }
    for(int len=3;len<=n;len++)
    {
        for(int i=1;i<=n-len+1;i++)
        {
            int j=i+len-1;
            if(a[i]==a[j])
                dp[i][j]=dp[i+1][j-1];
            for(int k=i;k<=j-1;k++)
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
        }
    }
    cout<<dp[1][n];
    return 0;
}