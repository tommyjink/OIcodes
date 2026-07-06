#include<bits/stdc++.h>
#define int long long
#define pss pair<string,string>
#define endl "\n"
using namespace std;
const int N=60;
int n;
string s,t;
pss dp[N][N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("pairing.in","r",stdin);
    freopen("pairing.out","w",stdout);
    cin>>s>>t;n=s.length();
    s=" "+s,t=" "+t;
    string ans;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {

            if(dp[i-1][j-1].first+s[i]+dp[i-1][j-1].second+t[i]>dp[i-1][j].first+dp[i-1][j].second)
                dp[i][j]={dp[i-1][j-1].first+s[i],dp[i-1][j-1].second+t[i]};
            else dp[i][j]=dp[i-1][j];
            ans=max(ans,dp[i][j].first+dp[i][j].second);
        }
    }
    cout<<ans<<endl;
    return 0;
}
