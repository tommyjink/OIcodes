#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e7+10,P=1e9+7;
int n,x,c[N],dp[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>x;
    for(int i=1;i<=n;i++)
        cin>>c[i];
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=c[i];j<=x;j++)
            dp[j]=(dp[j]+dp[j-c[i]])%P;
    }
    cout<<dp[x]<<endl;
    return 0;
}