#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,P=1e9+7;
int n,m,k,f[N];
int qpow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)res=res*x%P;
        y>>=1,x=x*x%P;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>k;
    if(n<k)cout<<"0"<<endl,exit(0);
    if(k==1)cout<<qpow(m,n)<<endl,exit(0);
    for(int i=1;i<=k-1;i++)
        f[i]=(qpow(m,i)+f[i-1])%P;
    for(int i=k;i<=n;i++)
        f[i]=(f[i-1]+(f[i-1]-((i-k)<=0?0:f[i-k])+P)*(m-1)%P)%P;
    // for(int i=1;i<=n;i++)
    //     cout<<f[i]<<endl;
    int ans=m*qpow(m,n-k)%P;
    for(int i=1;i<=n-k;i++)
        ans=(ans+(f[i]-f[i-1]+P)*(m-1)%P*qpow(m,n-i-k)%P)%P;
    cout<<ans<<endl;
    return 0;
}