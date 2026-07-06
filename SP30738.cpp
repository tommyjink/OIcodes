#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6,M=1e5+10;
int n,q,a[N],sum[N];
bitset<100007> dp;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q;
    dp[0]=1;
    sum[0]=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        dp |= dp<<a[i];
    }
    for(int i=1;i<=M;i++)   
        sum[i]=sum[i-1]+dp[i];
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<sum[r]-sum[l-1]<<endl;
    }
    return 0;
}