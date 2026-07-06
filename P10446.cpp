#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int a,b,p;
int qmult(int x,int y)
{
    int res=0;
    while(y)
    {
        if(y&1)res=(res+x)%p;
        y>>=1;
        x=(x+x)%p;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>a>>b>>p;
    cout<<qmult(a,b);
    return 0;
}