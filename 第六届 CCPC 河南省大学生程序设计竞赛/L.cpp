#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6;
int n,m,a[N],dp[N];
int f(int x)
{
    if(x>30000)return 1e18;
    return x*x*x*x;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        cin>>a[i];
    memset(dp,127,sizeof(dp));
    dp[0]=0;
    for(int i=1;i<=m;i++)
        for(int j=max(0ll,i-100);j<i;j++)
            dp[i]=min(dp[i],dp[j]+f(i-j)+a[i]);
    cout<<dp[m];
    return 0;
}
/*
20 20
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20


221
*/