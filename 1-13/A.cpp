#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=35;
int x,y,k,a[N],dp[N],b[N];
inline int cal()
{
    memset(dp,63,sizeof(dp));
    dp[0]=b[0]*a[0];
    for(int i=1;i<=31;i++)
    {
        dp[i]=dp[i-1]+b[i]*a[i];
        // cout<<dp[i]<<"!!!"<<i<<endl;
        int cnt=0;
        for(int j=i;j>=0;j--)
        {
            if(!b[j])cnt+=a[j];
            if(j==0)dp[i]=min(dp[i],a[i+1]+a[0]+cnt);
            else dp[i]=min(dp[i],dp[j-1]+a[i+1]+a[j]+cnt);
        }
        // cout<<dp[i]<<"???"<<i<<endl;
    }
    // for(int i=0;i<=5;i++)cout<<dp[i]<<" ";
    // cout<<endl;
    return dp[31];
}
void solve()
{
    cin>>x>>y>>k;
    x=abs(x-y);
    for(int i=0;i<=30;i++)b[i]=bool(x&(1ll<<i));
    for(int i=0;i<=k;i++)cin>>a[i];
    for(int i=1;i<=k;i++)a[i]=min(a[i],a[i-1]*2);
    for(int i=k+1;i<=32;i++)a[i]=a[i-1]*2;
    cout<<cal()<<endl;
    // cout<<cal(x)<<",,"<<cal(limit-x)+a[y]<<":"<<limit<<"!!!"<<y<<endl;
    // int res1=cal(x),res2=cal(limit-x)+a[y];
    // cout<<min(res1,res2)<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}
/*

2
10 10 2
1 1 1
0 8 3
10 10 10 1

0
1
*/