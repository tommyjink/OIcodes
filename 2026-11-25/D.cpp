#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10,M=11,P=1e9+7;
int n,m,a[N],b[N],f[M];
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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    f[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=0;j--)
            f[j]=(f[j]*b[i]%P+(j?f[j-1]:0)*a[i]%P+(j==m?f[j]:0)*a[i]%P)%P;
        // cout<<"i="<<i<<endl;
        // for(int j=0;j<=m;j++)
        //     cout<<f[j]<<" ";
        // cout<<endl;
    }
    int t;cin>>t;
    while(t--)
    {
        int op,x,y;
        cin>>op>>x>>y;
        for(int j=0;j<=m;j++)
        {
            f[j]=(f[j]+(P-(j?f[j-1]:0)*a[op]%P)%P)%P;
            if(j!=m)f[j]=f[j]*qpow(b[op],P-2)%P;
            else f[j]=f[j]*qpow(a[op]+b[op],P-2)%P;
        }
        a[op]=x;
        b[op]=y;
        for(int j=m;j>=0;j--)
            f[j]=(f[j]*b[op]%P+(j?f[j-1]:0)*a[op]%P+(j==m?f[j]:0)*a[op]%P)%P;
        cout<<f[m]<<endl;
    }
    return 0;
}