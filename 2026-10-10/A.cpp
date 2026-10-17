#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e3+10,M=2e6+10,P=998244353;
int n,m,a,b,c,d;
int fac[M],inv[M];
int f[N][3];
int qpow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)res=res*x%P;
        x=x*x%P;
        y>>=1;
    }
    return res;
}
int C(int x,int y)
{
    if(x<y||y<0)return 0;
    return fac[x]*inv[y]%P*inv[x-y]%P;
}
void add(int &x,int y)
{
    x=(x+y)%P;
}
void mul(int &x,int y)
{
    x=x*y%P;
}
void solve()
{
    cin>>n>>m>>a>>b>>c>>d;
    if(b==d||a==c){cout<<"1"<<endl;return;}
    for(int i=0;i<=n;i++)
        f[i][0]=f[i][1]=f[i][2]=0;
    f[0][0]=1;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=i;j++)
            add(f[i][1],C(b+i-j,b)*f[j][0]%P);
    for(int i=0;i<=a;i++)
        for(int j=0;j<=i;j++)
            add(f[i][2],C(d+i-j-b-1,d-b-1)*f[j][1]%P);
    for(int i=a+1;i<=n;i++)
        add(f[i][2],f[i-1][2]);
    for(int i=c;i<=n;i++)
        for(int j=c;j<=i;j++)
            add(f[i][2],C(d+i-j-b-1,d-b-1)*f[j][1]%P);
    int ans=0;
    if(m==d)ans=f[n][2];
    else for(int i=0;i<=n;i++)
        add(ans,f[i][2]*C(n+m-i-d-1,m-d-1)%P);
    // for(int j=0;j<=2;j++)
    //     for(int i=0;i<=n;i++)
    //         printf("f[%lld][%lld]=%lld\n",i,j,f[i][j]);
    cout<<ans*qpow(C(n+m,n),P-2)%P<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fac[0]=inv[0]=1;
    for(int i=1;i<M;i++)
        fac[i]=fac[i-1]*i%P;
    inv[M-1]=qpow(fac[M-1],P-2);
    for(int i=M-2;i>=1;i--)
        inv[i]=inv[i+1]*(i+1)%P;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}