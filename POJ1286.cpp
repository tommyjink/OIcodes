#include<iostream>
#define int long long
#define endl "\n"
using namespace std;
const int P=1e18+7;
int n,ans;
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
    while(cin>>n&&~n)
    {
        if(n==0){cout<<0<<endl;continue;}
        ans=0;
        for(int k=0;k<n;k++)
            ans+=qpow(3,gcd(n,k));
        if(n&1)
        {
            ans+=n*qpow(3,(n+1)/2);
            ans/=2*n;
        }
        else
        {
            ans+=(n/2)*qpow(3,n/2);
            ans+=(n/2)*qpow(3,n/2+1);
            ans/=2*n;
        }
        cout<<ans<<endl;
    }
    return 0;
}