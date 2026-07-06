#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10;
int n,a[N],k,dp[N];
void solve()
{
    int sum=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i],a[i]/=2,sum+=a[i];
    deque<int> q;
    q.push_back(1);
    dp[1]=a[1];
    for(int i=2;i<=n;i++)
    {
        while(!q.empty()&&q.front()<i-k-1)q.pop_front();
        while(!q.empty()&&dp[q.back()]>=dp[i])q.pop_back();
        q.push_back(i);
        dp[i]=dp[q.front()]+a[i];
    }
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