#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e3+10,INF=1e18;
int n,m,a[N][N],b[N][N],c[N][N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    for(int i=1;i<=n;i++)
    {
        int sum=0,mn=0;
        for(int j=1;j<=m;j++)
        {
            sum+=a[i][j];
            b[i][j]=sum-mn;
            mn=min(mn,sum);
        }
        sum=0,mn=0;
        for(int j=m;j>=1;j--)
        {
            sum+=a[i][j];
            b[i][j]=max(b[i][j],sum-mn);
            mn=min(mn,sum);
        }
    }
    for(int j=1;j<=m;j++)
    {
        int sum=0,mn=0;
        for(int i=1;i<=n;i++)
        {
            sum+=a[i][j];
            c[i][j]=sum-mn;
            mn=min(mn,sum);
        }
        sum=0,mn=0;
        for(int i=n;i>=1;i--)
        {
            sum+=a[i][j];
            c[i][j]=max(c[i][j],sum-mn);
            mn=min(mn,sum);
        }
    }
    int ans=-INF;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            ans=max(ans,b[i][j]+c[i][j]-a[i][j]);
        }
    }
    cout<<ans<<endl;
    return 0;
}