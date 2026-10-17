#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,INF=1e15;
int n,x,c[N],dp[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>x;
    for(int i=1;i<=x;i++)dp[i]=INF;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        for(int j=c[i];j<=x;j++)
            dp[j]=min(dp[j],dp[j-c[i]]+1);
    }
    if(dp[x]>=INF)cout<<-1<<endl;
    else cout<<dp[x]<<endl;
    return 0;
}