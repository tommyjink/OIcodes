#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int P=1e9+7;
int qpow(int x,int y)
{
    x%=P;
    y%=(P-1);
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
    int n;cin>>n;
    cout<<qpow(4,P-2)*(qpow(2,n*n)+(2*qpow(2,(n*n+3)/4)%P+qpow(2,(n*n+1)/2))%P)%P<<endl;
    return 0;
}