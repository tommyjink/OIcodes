#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10,P=998244353;
string s,t=" mori";
int n,dp[5];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>s;
    s=" "+s;
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='?')
        {
            for(int j=4;j>=0;j--)
            {
                if(j<4)dp[j]=dp[j]*3%P;
                else dp[j]=dp[j]*4%P;
                if(j>0)dp[j]=(dp[j]+dp[j-1])%P;
            }
        }
        else
        {
            for(int j=4;j>=1;j--)
            {
                if(s[i]==t[j])
                {
                    dp[j]=(dp[j]+dp[j-1])%P;
                    dp[j-1]=0;
                }
            }
        }
        // for(int j=1;j<=4;j++)
        //     cout<<dp[j]<<" ";
        // cout<<endl;
    }
    cout<<dp[4]<<endl;
    return 0;
}