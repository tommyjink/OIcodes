#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=10000,P=1e9+7;
int f[N],inv=0;
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
    f[0]=f[1]=f[2]=1;
    inv=qpow(2,P-2);
    for(int x=3;x<N;x++)
    {
        for(int i=0;i<=(x-1)/2;i++)
        {
            int j=x-1-i;
            if(i==j)f[x]=(f[x]+(f[i]*(f[i]+1))%P*inv%P)%P;
            else f[x]=(f[x]+f[i]*f[j]%P)%P;
        }
    }
    
    return 0;
}