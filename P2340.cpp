#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N=405,M=8e5+100,L=4e5;
int n,s[N],f[N],dp[M],ans=0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>s[i]>>f[i];
    memset(dp,128,sizeof(dp));
    dp[L]=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]<0)
            for(int j=0;j<M+s[i];j++)
                dp[j]=max(dp[j-s[i]]+f[i],dp[j]);
        else 
            for(int j=M-1;j>=max(0,s[i]);j--)
                dp[j]=max(dp[j-s[i]]+f[i],dp[j]);  
    }
    for(int i=L;i<M;i++)
        if(dp[i]>=0)
            ans=max(ans,dp[i]+i-L);
    cout<<ans<<endl;
    return 0;
}