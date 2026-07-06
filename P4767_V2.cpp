#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=3000+10,INF=1e16;
int n,k,a[N],w[N][N],f[N][N];
void solve(int now,int l,int r,int optl,int optr)
{
    // cout<<l<<","<<r<<endl;
    if(l>r)return;
    int mid=(l+r)>>1,p=optl,val=0;
    for(int i=optl;i<=min(mid,optr);i++)
        if(f[now-1][i]+w[i+1][mid]<=f[now-1][p]+w[p+1][mid])
            p=i,val=f[now-1][i]+w[i+1][mid];
    f[now][mid]=val;
    solve(now,l,mid-1,optl,p);
    solve(now,mid+1,r,p,optr);
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
    for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)f[i][j]=INF;
    f[0][0]=0;
    for(int i=1;i<=k;i++)
        solve(i,1,n,0,n);
    cout<<f[k][n]<<endl;
    return 0;
}