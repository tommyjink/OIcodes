#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,P=1e9+7;
int fac[N],inv[N],f[N],g[N];
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
void init()
{
    fac[0]=inv[0]=1;
    for(int i=1;i<N;i++)
        fac[i]=fac[i-1]*i%P;
    inv[N-1]=qpow(fac[N-1],P-2);
    for(int i=N-2;i;i--)
        inv[i]=inv[i+1]*(i+1)%P;
    f[0]=1;
    f[2]=1;
    g[2]=1;
    for(int i=3;i<N;i++)
    {
        f[i]=g[i-1]*(i-1)%P;
        g[i]=(f[i-1]+(i-1)*g[i-1]%P)%P;
    }
    // for(int i=1;i<=10;i++)
    //     cout<<f[i]<<" ";
}
int C(int x,int y)
{
    if(x<y||y<0)return 0;
    return fac[x]*inv[y]%P*inv[x-y]%P;
}
void solve()
{
    int n,m;
    cin>>n>>m;
    cout<<f[n-m]*C(n,m)%P<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int T;
    cin>>T;
    while(T--)solve();
    return 0;
}