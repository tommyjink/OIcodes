#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,INF=1e16;
int n,k,a[N],f[N][2],d[N][2],res;
int check(int c)
{
    for(int i=0;i<=n;i++)f[i][0]=f[i][1]=-INF*10;
    for(int i=0;i<=n;i++)d[i][0]=d[i][1]=0;
    f[0][0]=0,d[0][0]=0;
    f[0][1]=-INF*10,d[0][1]=0;
    for(int i=1;i<=n;i++)
    {
        f[i][0]=max(f[i-1][0],f[i-1][1]);
        if(f[i][0]==f[i-1][0])d[i][0]=max(d[i][0],d[i-1][0]);
        if(f[i][0]==f[i-1][1])d[i][0]=max(d[i][0],d[i-1][1]);
        f[i][1]=max(f[i-1][0]+a[i]-c,f[i-1][1]+a[i]);
        if(f[i][1]==f[i-1][0]+a[i]-c)d[i][1]=max(d[i][1],d[i-1][0]+1);
        if(f[i][1]==f[i-1][1]+a[i])d[i][1]=max(d[i][1],d[i-1][1]);
    }
    res=max(f[n][0],f[n][1]);
    int cnt=0;
    if(res==f[n][0])cnt=max(cnt,d[n][0]);
    if(res==f[n][1])cnt=max(cnt,d[n][1]);
    return cnt;
}
void WQS()
{
    if(check(0)<=k)cout<<res<<endl,exit(0);
    int l=-INF,r=INF;
    // cout<<"!"<<check(l)<<","<<check(r)<<endl;
    while(l<r)
    {
        int mid=l+(r-l+1)/2;
        if(check(mid)<k)r=mid-1;
        else l=mid;
    }
    check(l);
    // cout<<"!"<<l<<","<<check(l)<<endl;
    cout<<res+k*l<<endl;
}
signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    cin>>n>>k;n=2*n+1;
    for(int i=2;i<=n;i+=2)cin>>a[i];
    // check(-1e9-10);
    // for(int i=1;i<=n;i++)
    //     printf("f/d[%lld][0] : %lld,%lld\nf/d[%lld][1] : %lld,%lld\n",i,f[i][0],d[i][0],i,f[i][1],d[i][1]);
    WQS();
    return 0;
}