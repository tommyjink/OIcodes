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
void solve()
{
    cin>>n>>m;
    
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