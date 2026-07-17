#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,P=1e9+7;
int n,q,ans[N],fac[N],inv[N],fac2[N];
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
    if(x<y)return 0;
    if(x<0||y<0||x>N-1||y>N-1)return 0;
    return fac[x]*inv[y]%P*inv[x-y]%P;
}
int cal(int m)
{
    int res=0;
    for(int k=0;k<=n/(m+1);k++)
    {
        if(k&1)res=((res-C(n-k*m,k)*fac2[n-k*m-k])%P+P)%P;
        else res=((res+C(n-k*m,k)*fac2[n-k*m-k])%P+P)%P;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    inv[0]=fac[0]=fac2[0]=1;
    for(int i=1;i<N;i++)fac[i]=fac[i-1]*i%P;
    for(int i=1;i<N;i++)fac2[i]=fac2[i-1]*2%P;
    inv[N-1]=qpow(fac[N-1],P-2);
    for(int i=N-2;i>=0;i--)inv[i]=inv[i+1]*(i+1)%P;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        ans[i]=cal(i);
    for(int i=1;i<=q;i++)
    {
        int x;cin>>x;
        cout<<ans[x]<<endl;
    }
    return 0;
}