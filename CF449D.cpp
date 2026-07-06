#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e6+100,M=20,P=1e9+7;
int n,a[N],f[N],g[N],ans=0;
int qpow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)
            res=res*x%P;
        y>>=1;
        x=x*x%P;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],f[a[i]]++;
    for(int i=0;i<M;i++)
        for(int j=(1ll<<M)-1;j>=0;j--)
            if(!(j&(1ll<<i)))
                f[j]+=f[j|(1ll<<i)];
    for(int i=0;i<(1ll<<M);i++)
        g[i]=((qpow(2,f[i])-1)%P+P)%P;
    for(int i=0;i<(1ll<<M);i++)
        if(__builtin_popcountll(i)&1)
            ans=((ans-g[i])%P+P)%P;
        else ans=((ans+g[i])%P+P)%P;
    cout<<ans<<endl;
    return 0;
}