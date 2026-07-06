#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e3+100,M=1e4+100;
int n,w,a[N],dp[M];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>w;
    memset(dp,127,sizeof(dp));
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        for(int j=a[i];j<=w;j++)
            dp[j]=min(dp[j],dp[j-a[i]]+1);
    }
    cout<<dp[w];
    return 0;
}