#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=510;
int n,dp[N][N];
string s,t=" ";
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>s;
    s=" "+s;
    for(int i=1;i<=n;i++)
        if(s[i]!=s[i-1])
            t+=s[i];
    n=t.length()-1;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            dp[i][j]=1e14;
    for(int i=1;i<=n;i++)
        dp[i][i]=1;
    for(int len=2;len<=n;len++)
    {
        for(int i=1;i<=n-len+1;i++)
        {
            int j=i+len-1;
            if(t[i]==t[j])
                dp[i][j]=min(dp[i][j-1],dp[i+1][j]);
            dp[i][j]=min({dp[i][j],dp[i][j-1]+1,dp[i+1][j]+1});
            for(int k=i;k<j;k++)
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
        }
    }
    cout<<dp[1][n]<<endl;
    return 0;
}