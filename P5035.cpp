#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int P=123456789;
int qpow(int x,int k)
{
    int res=1;
    while(k)
    {
        if(k&1)
            res=res*x%P;
        k>>=1;
        x=x*x%P;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    cin>>k;
    cout<<qpow(2,k-1);
    return 0;
}