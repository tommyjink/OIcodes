#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int M=2e6+10,P=998244353;
int n,m,a,b,c,d;
int fac[M],inv[M];
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
int cal(int x,int y,int xx,int yy)
{
    if(x>xx||y>yy)return 0;
    return C(xx-x+yy-y,xx-x);
}
void solve()
{
    cin>>n>>m>>a>>b>>c>>d;
    if(b==d||a==c){cout<<"1"<<endl;return;}
    int ans=0;
    for(int i=0;i<a;i++)
        if(d!=m)add(ans,cal(0,0,i,d)*cal(i,d+1,n,m)%P);
    add(ans,cal(0,0,a,d)*cal(a,d,n,m)%P);
    // cout<<ans<<"!!!"<<endl;
    for(int i=c;i<n;i++)
        if(b!=m)add(ans,cal(0,0,i,b)*cal(i,b+1,n,m)%P);
    add(ans,cal(0,0,n,b));
    // cout<<ans<<endl;
    cout<<ans*qpow(cal(0,0,n,m),P-2)%P<<endl;
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