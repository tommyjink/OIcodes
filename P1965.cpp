#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,m,k,x;
int qpow(int x,int y,int P)
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
    cin>>n>>m>>k>>x;
    cout<<(x+m*qpow(10,k,n))%n;
    return 0;
}