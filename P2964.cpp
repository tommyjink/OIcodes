#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N=2e3+100;
int n,a[N],f[N][N];
signed main()
{
    // freopen("P2964_2.in","r",stdin);
    // freopen("P2964.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],a[i]+=a[i-1];
    for(int i=0;i<=n;i++)
        f[n+1][i]=0;
    for(int i=n;i>=1;i--)
    {
        for(int k=1;k<=n-i+1;k++)
            f[i][k]=a[n]-a[i-1]-f[i+k][2*k];
        for(int k=2;k<=n-i+1;k++)
            f[i][k]=max(f[i][k],f[i][k-1]);
        for(int k=n-i+2;k<=n;k++)
            f[i][k]=f[i][k-1];
    }
    cout<<max(f[1][1],f[1][2]);
    return 0;
}