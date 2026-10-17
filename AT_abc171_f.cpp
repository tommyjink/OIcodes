#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e7+10,P=1e9+7;
int n,m,ans=0,fac[N],inv[N];
string s;
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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fac[0]=inv[0]=1;
    for(int i=1;i<N;i++)
        fac[i]=fac[i-1]*i%P;
    inv[N-1]=qpow(fac[N-1],P-2);
    for(int i=N-2;i;i--)
        inv[i]=inv[i+1]*(i+1)%P;
    cin>>n>>s;
    m=s.length();
    n+=m;
    for(int i=m;i<=n;i++)
        ans=(ans+C(i-1,m-1)*qpow(25,i-m)%P*qpow(26,n-i)%P)%P;
    cout<<ans<<endl;
    return 0;
}