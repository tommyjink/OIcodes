#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1005,K=15,P=1e9+9;
int n,m,k,a[N],b[N],f[K][N][N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)cin>>b[i];
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            f[0][i][j]=1;
    for(int t=1;t<=k;t++)
    {
        for(int i=t;i<=n;i++)
        {
            for(int j=t;j<=m;j++)
            {
                if(a[i]<=b[j])continue;
                f[t][i][j]=f[t-1][i-1][j-1];
            }
        }
        for(int i=0;i<=n;i++)
            for(int j=1;j<=m;j++)
                f[t][i][j]=(f[t][i][j]+f[t][i][j-1])%P;
        for(int i=1;i<=n;i++)
            for(int j=0;j<=m;j++)
                f[t][i][j]=(f[t][i][j]+f[t][i-1][j])%P;
        
    }
    cout<<f[k][n][m]<<endl;
    return 0;
}