#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10,P=1e9+7;
string s,t=" mori";
int n,dp[5];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>s;
    n=s.length();
    s=" "+s;
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=4;j>=1;j--)
        {
            if(s[i]==t[j])dp[j]=(dp[j]+dp[j-1])%P;
        }
    }
    cout<<dp[4]<<endl;
    return 0;
}