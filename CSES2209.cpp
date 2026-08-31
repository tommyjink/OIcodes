#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int P=1e9+7;
int n,m,ans=0;
int gcd(int x,int y)
{
    return y==0?x:gcd(y,x%y);
}
int qpow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)res=res*x%P;
        y>>=1;
        x=x*x%P;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int k=0;k<n;k++)
    {
        ans=(ans+qpow(m,gcd(n,k)))%P;
    }
    ans=ans*qpow(n,P-2)%P;
    cout<<ans<<endl;
    return 0;
}