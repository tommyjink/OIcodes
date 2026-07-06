#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,INF=1e15;
int x,y,k,dp[N];
int gcd(int x,int y)
{
    return y?gcd(y,x%y):x;
}
int dfs(int x)
{
    if(dp[x]!=INF)return dp[x];
    if(x==1)return dp[x]=0;
    if(x<=k)return dp[x]=1;
    for(int i=2;i*i<=x;i++)
    {
        if(x%i)continue;
        if(i<=k)dp[x]=min(dp[x],dfs(x/i)+1);
        if(x/i<=k)dp[x]=min(dp[x],dfs(i)+1);
    }
    return dp[x];
}
void solve()
{
    cin>>x>>y>>k;
    int g=gcd(x,y);
    x/=g,y/=g;
    for(int i=1;i<=max(x,y);i++)
        dp[i]=INF;
    int res=dfs(x)+dfs(y);
    if(res<INF)cout<<res<<endl;
    else cout<<"-1"<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}