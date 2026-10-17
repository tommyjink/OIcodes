#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,P=1e9+7;
int n,a[N],ans=1;
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
void init()
{
    fac[0]=inv[0]=1;
    for(int i=1;i<N;i++)fac[i]=fac[i-1]*i%P;
    inv[N-1]=qpow(fac[N-1],P-2);
    for(int i=N-2;i;i--)inv[i]=inv[i+1]*(i+1)%P;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];a[i]/=2;
        if(i==1)continue;
        if(a[i]>a[i-1])ans=ans*C(a[i]-1,a[i-1]-1)%P;
        else ans=ans*C(a[i-1],a[i])%P;
    }
    cout<<ans<<endl;
    return 0;
}