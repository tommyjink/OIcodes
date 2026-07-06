#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,P=998244353;
int n,m,a[N],sum[N],ans=0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=m;i++)
    {
        int x;
        cin>>x;
        int p=upper_bound(a+1,a+1+n,x)-a-1;
        // cout<<p<<endl;
        ans=(ans+(p*x-sum[p])%P+(sum[n]-sum[p]-(n-p)*x)%P)%P;
    }
    cout<<ans<<endl;
    return 0;
}