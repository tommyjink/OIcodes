#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=6005,INF=1e16;
int n,k,a[N],f[N][N],w[N][N],b[N];
void cal(int now,int l,int r,int optl,int optr)
{
    if(l>r)return;
    int mid=(l+r)>>1,p=optl,val=0;
    for(int i=optl;i<=min(mid-1,optr);i++)
        if(i==optl||f[now-1][i]+w[i+1][mid]<f[now-1][p]+w[p+1][mid])
            p=i,val=f[now-1][i]+w[i+1][mid];
    f[now][mid]=val;
    cal(now,l,mid-1,optl,p);
    cal(now,mid+1,r,p,optr);       
}
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            f[i][j]=INF;
    f[0][0]=0;
    for(int i=n;i>=1;i--)
    {
        int cnt=0;
        for(int j=i+1;j<=n;j++)
        {
            cnt+=(a[i]>a[j]);
            w[i][j]=w[i+1][j]+cnt;
        }
    }
    for(int i=1;i<=min(k+1,n);i++)
        cal(i,i,n,i-1,n-1);
    cout<<f[min(k+1,n)][n]<<endl;
}
signed main()
{
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}