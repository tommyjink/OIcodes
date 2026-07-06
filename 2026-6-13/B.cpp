#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=2e5+10,P=1e9+7;
int n,k,fac[N],inv[N];
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
    cin>>n>>k;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        sum=(sum+x)%P;
    }
    fac[0]=1;
    for(int i=1;i<=k;i++)
        fac[i]=fac[i-1]*i%P;
    inv[k]=qpow(fac[k],P-2);
    for(int i=k;i>=1;i--)
        inv[i-1]=inv[i]*i%P;
    int s1=0,s2=0;
    for(int i=0;i<=k;i++)
    {
        int x=qpow(i,n-1);
        int v=inv[i]*inv[k-i]%P;
        if((k-i)&1)
        {
            s1=(s1-x*i%P*v%P+P)%P;
            s2=(s2-x*v%P+P)%P;
        }
        else
        {
            s1=(s1+x*i%P*v)%P;
            s2=(s2+x*v)%P;
        }
    }
    int ans=(s1+(n-1)*s2)%P*sum%P;
    cout<<ans<<endl;
    return 0;
}
