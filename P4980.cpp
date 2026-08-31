#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int P=1e9+7;
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
int mod(int x)
{
    return (x%P+P)%P;
}
void solve()
{
    int n;
    cin>>n;
    if(n&1)
        cout<<(n-1+qpow(n,n-1))%P<<endl;
    else
    {
        // cout<<qpow(n,n-1)<<"!"<<qpow(n,n/2)-1<<"!!"<<qpow(n-1,P-2)<<"!"<<mod(mod(qpow(n,n/2-1)-1)*qpow(n-1,P-2))<<endl;
        cout<<(qpow(n,n-1)+mod(mod(qpow(n,n/2)-1)*qpow(n-1,P-2))+mod(mod(qpow(n,n/2-1)-1)*qpow(n-1,P-2)))%P<<endl;;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}