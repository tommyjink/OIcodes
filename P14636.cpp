#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5010,P=998244353;
int c,t;
int n,m,a[N],b[N];
int fac[N],inv[N],f2[N];
int qpow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)res=res*x%P;
        y>>=1;
        x=x*x%P;
    }
    return res;
}
void init()
{
    fac[0]=inv[0]=f2[0]=1;
    for(int i=1;i<N;i++)
        fac[i]=fac[i-1]*i%P,
        f2[i]=f2[i-1]*2%P;
    inv[N-1]=qpow(fac[N-1],P-2);
    for(int i=N-2;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%P;
}
int C(int x,int y)
{
    if(y>x||y<0)return 0;
    return fac[x]*inv[y]%P*inv[x-y]%P;
}
void solve()
{
    int ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>b[i],a[i]=b[i]*2;
    sort(a+1,a+1+n,greater<int>());
    sort(b+1,b+1+n,greater<int>());
    a[n+1]=b[n+1]=0;
    // for(int i=1;i<=n;i++)
    //     cout<<a[i]<<" ";
    // cout<<endl;
    // for(int i=1;i<=n;i++)
    //     cout<<b[i]<<" ";
    // cout<<endl;
    for(int i=1;i<=n;i++)
    {
        int p=0,r=n+1;
        while(p<n&&a[p+1]>b[i])p++;
        for(int l=1;l<=p;l++)
        {
            while(r>p+1&&a[r-1]+a[l]<b[i]*2)r--;
            if(a[r]+a[l]>=b[i]*2)continue;
            int tar=m-2-(i-1);
            int cnt=(r==n+1)?1:f2[n-r+1];
            ans=(ans+C(l-2,tar)*cnt%P)%P;
            // cout<<i<<" "<<l<<" "<<r<<"!!!"<<C(l-1,tar)*cnt%P<<" "<<tar<<endl;
        }
    }
    cout<<((f2[n]-ans)%P+P)%P<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    // while(1)
    // {
    //     int x,y;
    //     cin>>x>>y;
    //     cout<<C(x,y)<<endl;
    // }
    cin>>c>>t;
    while(t--)solve();
    return 0;
}