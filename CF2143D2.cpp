#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e3+100,P=1e9+7;
int n,a[N],dp[N][3],b[N][4];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int ans=1;
    for(int i=1;i<=n;i++)
        b[i][1]=b[i][2]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            dp[j][1]=dp[j][2]=0;
        dp[a[i]][1]=1;
        for(int j=1;j<=n;j++)
        {
            if(j<=a[i])
            {
                dp[j][1]=(dp[j][1]+b[j][1])%P;
                dp[j][2]=(dp[j][2]+b[j][2])%P;
            }
            else
            {
                dp[a[i]][2]=(dp[a[i]][2]+b[j][1])%P;
            }
        }
        for(int j=1;j<=n;j++)
        {
            b[j][1]=(b[j][1]+dp[j][1])%P;;
            b[j][2]=(b[j][2]+dp[j][2])%P;
            printf("i=%lld,j=%lld:(1)%lld,(2)%lld\n",i,j,dp[j][1],dp[j][2]);
            // printf("B:i=%lld,j=%lld:(1)%lld,(2)%lld\n",i,j,b[j][1],b[j][2]);
        }
    }
    for(int i=1;i<=n;i++)
        ans=(ans+b[i][1]+b[i][2])%P;
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _t;
    cin>>_t;
    while(_t--)
    {
        solve();
    }
    return 0;
}