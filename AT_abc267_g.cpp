#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=5005,mod=998244353;
int n,k,a[N],f[N],cnt[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        if(a[i]==a[i-1])
            cnt[i]=cnt[i-1]+1;
    }
    f[0] = 1;
    for(int i=1;i<=n;i++)
    {
        for(int j=i-cnt[i];j>=1;j--)
            f[j]=(f[j-1]*(i-j-cnt[i])%mod+f[j]*(j+cnt[i]+1)%mod)%mod;
        f[0]=f[0]*(cnt[i]+1)%mod;
    }
    cout<<f[k]<<endl;
    return 0;
}
