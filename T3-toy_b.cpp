#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6;
int n,a[N],f[N][4],sum[N],ans=1e15;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++)
    {
        // cout<<a[i]<<endl;
        f[i][1]=f[i][2]=f[i][3]=1e15;
        for(int j=0;j<i;j++)
        {
            int p=lower_bound(a+j,a+1+i,(a[i]+a[j]+1)/2)-a;
            // printf("%lld,%lld:%lld\n",i,j,p);
            int val=(i-p+1)*a[i]-(sum[i]-sum[p-1])+(sum[p-1]-sum[j-1])-(p-1-j+1)*a[j];
            f[i][1]=i*a[i]-sum[i];
            f[i][2]=min(f[i][2],f[j][1]+val);
            f[i][3]=min(f[i][3],f[j][2]+val);
            ans=min(ans,f[i][3]+(sum[n]-sum[i-1])-(n-i+1)*a[i]);
        }
        for(int j=1;j<=3;j++)
            printf("f[%lld][%lld]=%lld\n",i,j,f[i][j]);
    }
    cout<<ans<<endl;
    return 0;
}   

/*
6
1 2 4 5 30 60

3 30 60

1 2 3
*/