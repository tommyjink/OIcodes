#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,P=1e9+7;
int n,a[N],dp[N],ans=0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        vector<int> v;
        for(int j=1;j*j<=a[i];j++)
        {
            if(a[i]%j)continue;
            if(j<=i)v.emplace_back(j);
            if(a[i]/j!=j&&a[i]/j<=i)v.emplace_back(a[i]/j);
        }
        sort(v.begin(),v.end(),greater<int>());
        for(auto j:v)
            dp[j]=(dp[j]+dp[j-1])%P;
    }
    for(int i=1;i<=n;i++)ans=(ans+dp[i])%P;
    cout<<ans;
    return 0;
}