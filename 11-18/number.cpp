#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int P=1e9+7,N=1e6+100;
int n,dp[2][N];
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
void solve()
{
    cin>>n;
    cout<<qpow(10,n/2)<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}