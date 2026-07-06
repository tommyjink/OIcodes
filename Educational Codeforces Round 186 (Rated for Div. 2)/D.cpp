#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,P=998244353;
int n,a[N],fac[N],invfac[N];
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
    fac[0]=invfac[0]=1;
    for(int i=1;i<N;i++)
        fac[i]=fac[i-1]*i%P;
    invfac[N-1]=qpow(fac[N-1],P-2);
    for(int i=N-2;i>=0;i--)
        invfac[i]=invfac[i+1]*(i+1)%P;
}
inline int C(int x,int y)
{
    return fac[x]*invfac[y]%P*invfac[x-y]%P;
}
void solve()
{
    cin>>n;
    for(int i=0;i<=n;i++)
        cin>>a[i];
    int mx=0;
    for(int i=1;i<=n;i++)
        mx=max(mx,a[i]);
    for(int i=1;i<=n;i++)
    {
        if(a[i]==mx)continue;
        a[0]-=(mx-1-a[i]);
        a[i]+=(mx-1-a[i]);
    }
    if(a[0]<0)
    {
        cout<<"0"<<endl;
        return;
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
        if(a[i]==mx)cnt++;
    if(a[0]>n-cnt)
        a[0]-=n-cnt,a[0]%=n,cnt=0;
    cout<<C(n-cnt,a[0])*fac[a[0]+cnt]%P*fac[n-a[0]-cnt]%P<<endl;
    // for(int i=0;i<=n;i++)
    //     cout<<a[i]<<",";
    // cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}