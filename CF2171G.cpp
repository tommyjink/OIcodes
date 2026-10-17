#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+3,P=1e6+3;
int n,lg[N],a[N],b[N],c[22],fac[N],inv[N];
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
int f(int x){return x>=P?0:fac[x];}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    int m=20,ans=1,tot=0;
    for(int i=0;i<=20;i++)c[i]=0;
    for(int i=1;i<=n;i++)
        m=min(m,lg[b[i]/a[i]]);
    // cout<<m<<endl;
    for(int i=1;i<=n;i++)
    {
        int d=b[i]-(1ll<<m)*a[i];
        // cout<<d<<"!";
        for(int j=m;j>=0;j--)
        {
            int x=d/(1<<j);
            ans=ans*inv[x]%P;
            // cout<<inv[x]<<"!"<<x<<endl;
            c[j]+=x;
            tot+=x;
            d%=(1ll<<j);
        }
    }
    for(int i=0;i<=m;i++)ans=ans*f(c[i])%P;
    // for(int i=0;i<=10;i++)cout<<c[i]<<" ";
    // cout<<endl;
    cout<<tot+m<<" "<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fac[0]=inv[0]=1;
    for(int i=1;i<N;i++)fac[i]=fac[i-1]*i%P;
    inv[N-1]=qpow(fac[N-1],P-2);
    for(int i=N-2;i;i--)inv[i]=inv[i+1]*(i+1)%P;
    lg[2]=1;
    for(int i=3;i<N;i++)
        lg[i]=lg[i/2]+1;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}