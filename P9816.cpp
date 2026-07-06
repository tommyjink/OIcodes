#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5e5+10,M=30;
int m,p,q,a[N],b[N],f[N][M+10];
int qpow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)res=res*x%p;
        x=x*x%p;
        y>>=1;
    }
    return res;
}
int cal(int x)
{
    x%=p;
    int res=0;
    for(int i=1;i<=m;i++)
        res=(res+a[i]*qpow(x,b[i])%p)%p;
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>m>>q>>p;
    for(int i=1;i<=m;i++)
        cin>>a[i]>>b[i];
    for(int i=0;i<=p-1;i++)
        f[i][0]=cal(i);
    for(int i=1;i<=M;i++)
        for(int j=0;j<=p-1;j++)
            f[j][i]=f[f[j][i-1]][i-1];
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        int now=cal(x);
        y--;
        for(int i=M;i>=0;i--)
            if(y>=(1ll<<i))
                now=f[now][i],y-=(1ll<<i);
        cout<<now<<endl;
    }
    return 0;
}