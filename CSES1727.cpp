#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n;
double k,p,ans=0.0;
double qpow(double x,int y)
{
    double res=1.0;
    while(y)
    {
        if(y&1)res=res*x;
        x=x*x;
        y>>=1;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=k;i++)
        ans+=(qpow(i/k,n)-qpow((i-1)/k,n))*i;
    printf("%.6lf",ans);
    return 0;
}