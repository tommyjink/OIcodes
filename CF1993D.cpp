#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,INF=1e15;
int n,k,a[N],b[N],dp[N][2];
int dfs(int i,int j)
{
    if(i<0||j<0||j*k>i)return -INF;
    if(i==0)return 0;
    if(dp[i][j-(i-1)/k]!=-INF)return dp[i][j-(i-1)/k];
    return dp[i][j-(i-1)/k]=max(dfs(i-1,j)+b[i],dfs(i-k,j-1));
}
bool check(int mid)
{
    for(int i=1;i<=n;i++)
        b[i]=(a[i]>=mid?1:-1),dp[i][0]=dp[i][1]=-INF;
    return dfs(n,(n-1)/k)>0;
}
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int l=1,r=1e9;
    while(l<r)
    {
        int mid=(l+r+1)>>1;
        if(check(mid))l=mid;
        else r=mid-1;
    }
    cout<<l<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}