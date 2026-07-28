#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e3+10,P=1e5+3;
int a,b,c,d,K,fac[N],inv[N];
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
    fac[0]=inv[0]=1;
    for(int i=1;i<N;i++)
        fac[i]=fac[i-1]*i%P;
    inv[N-1]=qpow(fac[N-1],P-2);
    for(int i=N-2;i>=1;i--)
        inv[i]=inv[i+1]*(i+1)%P;
}
int C(int x,int y)
{
    if(y>x||y<0)return 0;
    return fac[x]*inv[x-y]%P*inv[y]%P;
}
int g(int a,int b,int k)
{
    if(k<0)return 0;
    return fac[k]*C(a,k)%P*C(b,k)%P;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    cin>>a>>b>>c>>d>>K;
    int ans=0;
    for(int n=0;n<=K;n++)
        for(int k=0;k<=n;k++)
            ans=(ans+g(a,b,k)*g(c,d,n-k)%P*g(a-k,d-n+k,K-n)%P)%P;
    cout<<ans<<endl;
    return 0;
}