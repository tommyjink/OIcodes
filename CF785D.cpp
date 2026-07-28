#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,P=1e9+7;
string s;
int n,a[N],b[N];
int fac[N],inv[N];
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
    for(int i=N-2;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%P;
}
int C(int x,int y)
{
    if(x<0||y<0||x<y)return 0;
    return fac[x]*inv[y]%P*inv[x-y]%P;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    cin>>s;n=s.length();
    s=" "+s;
    for(int i=1;i<=n;i++)
        if(s[i]=='(')a[i]=1;
        else b[i]=1;
    for(int i=1;i<=n;i++)a[i]+=a[i-1];
    for(int i=n;i>=1;i--)b[i]+=b[i+1];
    int ans=0;
    for(int i=1;i<=n;i++)
        if(s[i]=='(')ans=(ans+C(a[i]+b[i]-1,b[i]-1))%P;
    cout<<ans<<endl;
    return 0;
}