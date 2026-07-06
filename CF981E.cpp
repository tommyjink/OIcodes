#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e4+10;
int n,q;
bitset<N> f[N],dp[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q;
    for(int i=1;i<=q;i++)
    {
        int l,r,x;
        cin>>l>>r>>x;
        if(x>n)continue;
        for(int j=l;j<=r;j++)
            f[x][j]=1;
    }
    for(int i=1;i<=n;i++)
        dp[0][i]=1;
    for(int i=1;i<=n;i++)
        for(int j=n;j>=i;j--)
            dp[j]=dp[j]|(dp[j-i]&f[i]);
    int ans=0;
    for(int i=1;i<=n;i++)
        if(dp[i].count())ans++;
    cout<<ans<<endl;
    for(int i=1;i<=n;i++)
        if(dp[i].count())
            cout<<i<<" ";
    return 0;
}