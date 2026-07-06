#include<bits/stdc++.h>
#define int long long
// #define double long double
#define endl "\n"
using namespace std;
const int N=1e6;
int dp[N],s[N];
int _sqrt(int x)
{
    long double res=sqrt((long double)x);
    return (int)res;
}
void solve()
{
    int x;
    cin>>x;
    int ans=0,n=_sqrt(x);
    for(int i=1;i*i<=n;i++)
        ans+=dp[i]*(min(n+1,(i+1)*(i+1))-i*i);
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    dp[1]=1;
    for(int i=2;i<N;i++)
        dp[i]=dp[i-1]+dp[(int)sqrt(i)];
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}