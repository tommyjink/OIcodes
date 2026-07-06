#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=210,mod=998244353;
int n,m,k,a[N][N],d[N],f[N],g[N],s[N];
struct node
{
    int a[N][N];
    node()
    {
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                a[i][j]=0;
    }
}res;
node mul(node x,node y)
{
    node z;
    int lim=n*2;
    for(int i=1;i<=lim;i++)
        for(int k=1;k<=lim;k++)
        {
            if(!x.a[i][k])continue;
            for(int j=1;j<=lim;j++)
            {
                if(!y.a[k][j])continue;
                z.a[i][j]=(z.a[i][j]+x.a[i][k]*y.a[k][j])%mod;
            }
        }
    return z;
}
void mul1(node x,int b[])
{
    static int c[N];
    int lim=n*2;
    for(int i=1;i<=lim;i++)c[i]=0;
    for(int i=1;i<=lim;i++)
        for(int j=1;j<=lim;j++)
            c[i]=(c[i]+x.a[i][j]*b[j])%mod;
    for(int i=1;i<=lim;i++)b[i]=c[i];
}
void solve()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        d[i]=f[i]=g[i]=0;
        for(int j=1;j<=n;j++)a[i][j]=0;
    }
    for(int i=1;i<=m;i++)
    {
        int x,y;cin>>x>>y;
        a[x][y]=a[y][x]=1;
        d[x]++,d[y]++;
    }
    if(k==0)
    {
        if(n==1)cout<<1<<endl;
        else cout<<0<<endl;
        return;
    }
    for(int i=1;i<=n;i++)f[i]=a[i][1];
    if(k==1)
    {
        cout<<f[n]<<endl;
        return;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            g[i]=(g[i]+a[i][j]*f[j])%mod;
    g[1]=(g[1]-d[1])%mod;
    if(g[1]<0)g[1]+=mod;
    if(k==2)
    {
        cout<<g[n]<<endl;
        return;
    }
    for(int i=1;i<=n*2;i++)s[i]=0;
    for(int i=1;i<=n;i++)s[i]=f[i],s[n+i]=g[i];
    res=node();
    for(int i=1;i<=n;i++)
    {
        res.a[i][i]=(mod-(d[i]-1)%mod)%mod;
        for(int j=1;j<=n;j++)res.a[i][n+j]=a[i][j];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            if(a[i][j])res.a[n+i][j]=(mod-(d[j]-1)%mod)%mod;
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                res.a[n+i][n+j]=(res.a[n+i][n+j]+a[i][k]*a[k][j])%mod;
        res.a[n+i][n+i]=(res.a[n+i][n+i]-(d[i]-1))%mod;
        if(res.a[n+i][n+i]<0)res.a[n+i][n+i]+=mod;
    }
    int t=(k-1)/2;
    while(t)
    {
        if(t&1)mul1(res,s);
        res=mul(res,res);
        t>>=1;
    }
    if(k&1)cout<<s[n]<<endl;
    else cout<<s[n+n]<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
