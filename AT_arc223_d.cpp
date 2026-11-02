#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e7+10,P=998244353;
int a,b,k,fac[N],inv[N];
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
int C(int x,int y)
{
    if(x<y||y<0)return 0;
    return fac[x]*inv[y]%P*inv[x-y]%P;
}
int cal(int a,int b)
{
    return (C(a+b,a)-C(a+b,a+k)+P)%P;
}
void solve()
{
    cin>>a>>b>>k;
    int ans=0;
    for(int i=0;i<=a&&i+k<=b;i++)
        ans=(ans+cal(i,i+k-1)*C(a+b-i-(i+k),a-i)%P*(i+k)%P)%P;
    if(b-a<k)ans=(ans+cal(a,b)*b%P)%P;
    cout<<ans*qpow(C(a+b,a),P-2)%P<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    inv[0]=fac[0]=1;
    for(int i=1;i<N;i++)
        fac[i]=fac[i-1]*i%P;
    inv[N-1]=qpow(fac[N-1],P-2);
    for(int i=N-2;i>=1;i--)
        inv[i]=inv[i+1]*(i+1)%P;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}