#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=505,INF=1e17;
int n,a[N][N],b[N][N],f[N][N],g[N][N];
void solve()
{
    cin>>n;
    for(int i=0;i<=n+1;i++)
        for(int j=0;j<=n+1;j++)
            a[i][j]=b[i][j]=0,f[i][j]=g[i][j]=INF;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
        for(int j=1;j<=n;j++)
            b[i][j]=a[i][j-1]+a[i][j+1];
        if(i==1)for(int j=1;j<=n;j++)
            f[i][j]=b[i][j];
        else for(int j=1;j<=n;j++)
            f[i][j]=min(f[i-1][j-1]+b[i][j],f[i-1][j+1]+b[i][j]);
    }
    for(int i=n;i>=1;i--)
    {
        if(i==n)for(int j=1;j<=n;j++)
            g[i][j]=b[i][j];
        else for(int j=1;j<=n;j++)
            g[i][j]=min(g[i+1][j-1]+b[i][j],g[i+1][j+1]+b[i][j]);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<min(f[i][j-1]+g[i][j-1]-b[i][j-1],f[i][j+1]+g[i][j+1]-b[i][j+1])<<" ";
        }
        cout<<endl;
    }
    
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}