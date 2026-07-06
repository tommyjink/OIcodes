#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=105,M=2005,p=998244353;
int n,m,a[N][M],f[N][M*3],sum[N],ans=1;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            sum[i]=(sum[i]+a[i][j])%p;
        }
        ans=ans*(sum[i]+1)%p;
    }
    ans=(ans-1+p)%p;
    for(int i=1;i<=m;i++)
    {
        // printf("i=%lld:_______\n",i);
        memset(f,0,sizeof(f));
        f[0][0+M]=1;
        for(int j=1;j<=n;j++)
        {
            for(int k=-j;k<=j;k++)
            {
                f[j][k+M]=(f[j][k+M]+f[j-1][k+M-1]*a[j][i]%p)%p;
                f[j][k+M]=(f[j][k+M]+f[j-1][k+M])%p;
                f[j][k+M]=(f[j][k+M]+f[j-1][k+M+1]*(sum[j]-a[j][i])%p)%p;
                // printf("f[%lld][%lld]=%lld\n",j,k,f[j][k+M]);
            }
        }
        for(int j=1;j<=n;j++)
            ans=((ans-f[n][j+M])%p+p)%p;
    }
    cout<<ans<<endl;
    return 0;
}