#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=4e6+10;
int n,P,fac[N],inv[N];
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
    inv[0]=fac[0]=1;
    for(int i=1;i<=n;i++)
        fac[i]=fac[i-1]*i%P;
    inv[n]=qpow(fac[n],P-2);
    for(int i=n-1;i>=1;i--)
        inv[i]=inv[i+1]*(i+1)%P;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>P;
    init();
    for(int i=1;i<=n;i++)
        cout<<inv[i]*fac[i-1]%P<<endl;
    return 0;
}