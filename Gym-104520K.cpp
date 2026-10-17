#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,P=998244353;
int n;
int fac[N],inv[N];
int C(int x,int y)
{
    if(x<y||y<0)return 0;
    return fac[x]*inv[y]%P*inv[x-y]%P;
}
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
void solve()
{
    int ans=0;
    cin>>n;
    cout<<"0 ";
    for(int i=2;i+1<=n;i+=2)
        cout<<fac[i]*fac[n-i+1]%P*C(n-i/2-2,i/2-1)%P<<" ";
    for(int i=(n+1)/2+1;i<=n;i++)cout<<"0 ";
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fac[0]=inv[0]=1;
    for(int i=1;i<N;i++)fac[i]=fac[i-1]*i%P;
    inv[N-1]=qpow(fac[N-1],P-2);
    for(int i=N-2;i;i--)inv[i]=inv[i+1]*(i+1)%P;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}