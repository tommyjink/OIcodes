#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5e6+10,P=1e9+7;
int fac[N],inv[N],fac3[N],fac2[N],fac1[N];
int n,q;
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
    fac[0]=fac3[0]=fac2[0]=fac1[0]=1;
    for(int i=1;i<N;i++)
        fac[i]=fac[i-1]*i%P;
    inv[N-1]=qpow(fac[N-1],P-2);
    for(int i=N-2;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%P;
    for(int i=1;i<N/3;i++)
        fac3[i]=fac[3*i]*fac3[i-1]%P;
    for(int i=1;i<N/3;i++)
        fac2[i]=fac[3*i-1]*fac2[i-1]%P;
    for(int i=1;i<N/3;i++)
        fac1[i]=fac[3*i-2]*fac1[i-1]%P;
}
void solve(int x)
{
    for(int i=1;i<=n;i++)
    {
        
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q;
    while(q--)
    {
        int x;cin>>x;
        solve(x);
    }
    return 0;
}