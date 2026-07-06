#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=3000+10,INF=1e16;
int n,k,a[N],w[N][N],f[N],d[N];
int check(int c)
{
    for(int i=1;i<=n;i++)f[i]=INF;
    for(int i=1;i<=n;i++)d[i]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=i-1;j++)
        {
            f[i]=min(f[i],f[j]+w[j+1][i]+c);
            if(f[i]==f[j]+w[j+1][i]+c)d[i]=max(d[i],d[j]+1);
        }
    }
    return d[n];
}
void WQS()
{
    int l=-1e8,r=1e8;
    while(l<r)
    {
        int mid=l+(r-l+1)/2;
        if(check(mid)<k)r=mid-1;
        else l=mid;
    }
    check(l);
    cout<<f[n]-k*l<<endl;
}
signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            w[i][j]=w[i][j-1]+a[j]-a[(i+j)/2];
            // printf("w[%lld][%lld]=%lld\n",i,j,w[i][j]);
    WQS();
    return 0;
}