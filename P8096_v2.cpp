#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=105,M=1005,P=1e9+7;
int n,h[N],dp[N][M];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>h[i];
    int ans=0;
    while(1)
    {
        for(int i=0;i<=n;i++)
            for(int j=0;j<M;j++)dp[i][j]=0;
        for(int i=0;i<M;i++)dp[0][i]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=min(h[i],h[i-1]);j++)
                dp[i][j]=dp[i-1][h[i-1]-j];
            for(int j=1;j<M;j++)dp[i][j]=(dp[i][j]+dp[i][j-1])%P;
        }
        ans=(ans+dp[n][h[n]])%P;
        if(n%2==0)break;
        int mn=M;
        for(int i=1;i<=n;i++)
            h[i]--,mn=min(mn,h[i]);
        if(mn<0)break;
    }
    cout<<ans<<endl;
    return 0;
}