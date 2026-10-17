#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10,P=998244353;
int n;
int f[N],g[N];
struct matrix
{
    int m[N];
}
void solve()
{
    cin>>n;
    for(int i=0;i<=n;i++)f[i]=0;
    f[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=n;j>=1;j--)
            f[j]=(f[j]*j%P+f[j-1])%P;
        f[0]=0;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=(ans+f[i])%P;;
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--)solve();
    return 0;
}