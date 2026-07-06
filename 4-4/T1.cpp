#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int mod=998244353;
const int N=300010;
int n,m,k,x[N],y[N],visx[N],visy[N];
int qpow(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1)res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
int chk(int s)
{
    static int a[5][5],sum[5][5];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            a[i][j]=(s>>((i-1)*m+j-1))&1;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            sum[i][j]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
    for(int i=1;i<=k;i++)
    {
        int s1=sum[x[i]][y[i]];
        int s2=sum[n][m]-sum[x[i]][m]-sum[n][y[i]]+sum[x[i]][y[i]];
        if(!(s1&1)||!(s2&1))return 0;
    }
    return 1;
}
signed main()
{
    cin>>n>>m;
    cin>>k;
    int fl=1;
    for(int i=1;i<=k;i++)
    {
        cin>>x[i]>>y[i];
        if(visx[x[i]]||visy[y[i]])fl=0;
        visx[x[i]]=1;
        visy[y[i]]=1;
    }
    if(n<=4&&m<=4)
    {
        int ans=0;
        for(int s=0;s<(1ll<<(n*m));s++)
            ans+=chk(s);
        cout<<ans%mod<<endl;
        return 0;
    }
    if(fl)
    {
        cout<<qpow(2,n*m-2*k)<<endl;
        return 0;
    }
    cout<<0<<endl;
    return 0;
}
