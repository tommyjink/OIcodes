#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,P,f[N],g[N];
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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>P;
    g[1]=1;
    f[1]=0;
    f[2]=1;
    g[2]=1;
    for(int i=3;i<=n;i++)
    {
        f[i]=(i-1)*g[i-1]%P;
        g[i]=(f[i-1]+(i-1)*g[i-1])%P;
    }
    for(int i=1;i<=n;i++)
        cout<<f[i]<<" ";
    return 0;
}