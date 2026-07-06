#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,INF=1e16;
int n,k,a[N],f[N][2],d[N][2],ans;
int check(int c)
{
    for(int i=0;i<=n;i++)f[i][0]=f[i][1]=-INF;
    for(int i=0;i<=n;i++)d[i][0]=d[i][1]=0;
    for(int i=1;i<=n;i++)a[i]-=c;
    f[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        f[i][0]=max(f[i-1][0],f[i-1][1]);
        if(f[i][0]==f[i-1][0])d[i][0]=max(d[i][0],d[i-1][0]);
        if(f[i][0]==f[i-1][1])d[i][0]=max(d[i][0],d[i-1][1]);
        f[i][1]=f[i-1][0]+a[i];
        d[i][1]=d[i-1][0]+1;
    }
    int cnt=0;
    ans=max(f[n][0],f[n][1]);
    if(ans==f[n][0])cnt=max(cnt,d[n][0]);
    if(ans==f[n][1])cnt=max(cnt,d[n][1]);
    for(int i=1;i<=n;i++)a[i]+=c;
    return cnt;
}
void WQS()
{
    if(check(0)<=k)cout<<ans<<endl,exit(0);
    int l=-1e6,r=1e6;
    while(l<r)
    {
        int mid=l+(r-l+1)/2;
        if(check(mid)<k)r=mid-1;
        else l=mid;
    }
    check(l);
    cout<<ans+l*k<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    WQS();
    return 0;
}