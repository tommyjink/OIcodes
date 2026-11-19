#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int P=998244353;
int inv2=0,inv3=0;
int n,m;
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
int C2(int x)
{
    return x*(x-1+P)%P*inv2%P;
}
int C3(int x)
{
    return (x*(x-1+P)%P*(x-2+P)%P)*inv2%P*inv3%P;
}
void solve()
{
    cin>>n>>m;
    int d=m+1;
    int T=(qpow(4,n-1)-qpow(3,n)+P+3*qpow(2,n-1)%P-1+P)%P;
    int ans=(qpow(d,n)-d+1+P-C2(d)*(qpow(2,n-1)-1+P)%P+P+C3(d)*T%P)%P;
    cout<<ans*qpow(2,m)%P<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    inv2=qpow(2,P-2);
    inv3=qpow(3,P-2);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}