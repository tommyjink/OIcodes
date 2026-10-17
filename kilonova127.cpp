#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int P=1e9+7,N=3e6+10;
int a,b,tot=0,p[N],k[N];
int qpow(int x,int y)
{
    x%=P;
    y%=(P-1);
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
    freopen("sumdiv.in","r",stdin);
    freopen("sumdiv.out","w",stdout);
    cin>>a>>b;
    for(int i=2;i*i<=a;i++)
    {
        int cnt=0;
        while(a%i==0)cnt++,a/=i;
        if(cnt)p[++tot]=i,k[tot]=cnt;
    }
    if(a>1)p[++tot]=a,k[tot]=1;
    int ans=1;
    for(int i=1;i<=tot;i++)
    {
        int x=(qpow(p[i],(b%(P-1)*k[i]%(P-1)+1)%(P-1))-1+P)%P;
        int y=qpow(p[i]-1,P-2);
        if(p[i]%P==1)ans=(ans*(b%P*k[i]%P+1)%P);
        else ans=(ans*x%P*y%P);
    }
    cout<<ans<<endl;
    return 0;
}