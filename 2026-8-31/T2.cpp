#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int P=998244353,N=2e6+10;
int n,p[N],E[N],E2[N];
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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    int inv100=qpow(100,P-2);
    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
        p[i]=p[i]*inv100%P;
    }
    int ans=0,sum=0,g=0;
    for(int i=1;i<=n;i++)
    {
        int x=p[i]*(g+sum)%P;
        E[i]=p[i]*(E[i-1]+1)%P;
        E2[i]=p[i]*((E2[i-1]+2*E[i-1]%P)%P+1)%P;
        ans=(ans+2*x%P+E2[i])%P;
        sum=(sum+E[i])%P;
        g=(x+E2[i])%P;
    }
    cout<<ans<<endl;
    return 0;
}
