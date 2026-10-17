#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,P=998244353;
int n,a[N],ans=0;
int tag[N],fac[N],inv[N];
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
    fac[0]=1;
    for(int i=1;i<N;i++)fac[i]=fac[i-1]*i%P;
    inv[N-1]=qpow(fac[N-1],P-2);
    for(int i=N-2;i;i--)inv[i]=inv[i+1]*(i+1)%P;
}
int qinv(int x)
{
    return inv[x]*fac[x-1]%P;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
            tag[j]=0;
        for(int j=i;j<=n;j++)
            if(a[j]<n)tag[a[j]]++;
        int res=n;
        for(int j=0;j<=n;j++)
            if(!tag[j])res=min(res,j);
        for(int j=n;j>=i;j--)
        {
            // cout<<i<<","<<j<<":"<<res<<endl;
            ans=(ans+res*qinv(j-i+1)%P)%P;
            if(a[j]<n&&!--tag[a[j]])
                res=min(res,a[j]);
        }
    }
    cout<<ans<<endl;
    return 0;
}