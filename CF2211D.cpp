#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10,P=1e9+7;
int n,b[N],c[N],fac[N],inv[N];
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
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>b[i],c[i]=0;
    for(int k=n;k>=1;k--)
    {
        int now=b[k];
        for(int j=28;j>=0;j--)
            if(c[j])now=(now-(1ll<<j)*C(c[j],k)%P+P+P)%P;
        // for(int j=0;j<=5;j++)cout<<c[j]<<" ";
        // cout<<"!!!!"<<endl;
        // cout<<k<<","<<now<<endl;
        if(!now)continue;
        for(int j=28;j>=0;j--)
            if((1ll<<j)&now)c[j]=k;
    }
    // for(int i=0;i<=28;i++)
    //     cout<<c[i]<<" ";
    // cout<<endl;
    for(int i=1;i<=n;i++)
    {
        int res=0;
        for(int j=0;j<=28;j++)
            if(c[j])res+=(1ll<<j),c[j]--;
        cout<<res<<" ";
    }
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