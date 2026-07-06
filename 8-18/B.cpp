#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10;
int n,m,a[N],b[N],dp[N][2];
bool check(int l,int r)
{
    for(int i=1;i<=n;i++)
    {
        if(l<=a[i]&&a[i]<=r)
            dp[i][1]=dp[i-1][0]+1;
        else dp[i][1]=0;
        dp[i][0]=max(dp[i-1][1],dp[i-1][0]);
    }
    return max(dp[n][1],dp[n][0])>=m;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i],b[i]=a[i];
    sort(b+1,b+1+n);
    int ans=1e15;
    for(int i=1;i<=n;i++)
    {
        int l=0,r=n-i;
        while(l<r)
        {
            int mid=(l+r)>>1;
            if(check(b[i],b[i+mid]))r=mid;
            else l=mid+1;
        }
        // printf("i=%lld,l=%lld,b[i+l]=%lld,b[i]=%lld\n",i,l,b[i+l],b[i]);
        if(check(b[i],b[i+l]))ans=min(ans,b[i+l]-b[i]);
    }
    cout<<ans<<endl;
    return 0;
}