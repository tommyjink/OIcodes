#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=205,INF=1e13;
int n,K,a[N],b[N],f[N][N*N];
int ans=0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>K;
    for(int i=0;i<=K;i++)
        for(int j=0;j<=30*n;j++)
            f[i][j]=-INF;
    f[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        while(x%2==0)x/=2,a[i]++;
        while(x%5==0)x/=5,b[i]++;

        for(int k=K;k>=1;k--)
        {
            for(int p=30*n;p>=b[i];p--)
            {
                f[k][p]=max(f[k][p],f[k-1][p-b[i]]+a[i]);
                ans=max(ans,min(p,f[k][p]));
            }
        }   
    }
    cout<<ans<<endl;
    return 0;
}