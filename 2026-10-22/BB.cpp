#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=155,P=1e9+7;
int n,a[N];
int f[N][N][N],g[N][N][N],w[N][N],L[N],R[N];
int fac[N],inv[N];
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
void init()
{
    fac[0]=inv[0]=1;
    for(int i=1;i<N;i++)
        fac[i]=fac[i-1]*i%P;
    inv[N-1]=qpow(fac[N-1],P-2);
    for(int i=N-2;i>=1;i--)
        inv[i]=inv[i+1]*(i+1)%P;
}
int C(int x,int y)
{
    if(x<y||y<0)return 0;
    return fac[x]*inv[y]%P*inv[x-y]%P;
}
void add(int &x,int y)
{
    x=(x+y+P)%P;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    init();
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n-1;i++)
    {
        f[i][i+1][0]=1;
        w[i][i+1]=1;
        for(int j=0;j<=n;j++)
            g[i][i+1][j]=1;
    }
    for(int len=3;len<=n;len++)
    {
        for(int i=1;i<=n-len+1;i++)
        {
            int j=i+len-1;
            for(int t=1;t<=j-i-1;t++)
            {
                for(int m=i+1;m<=j-1;m++)
                {
                    if(a[m]!=t&&a[m]!=-1)continue;
                    int x=0,y=0;
                    x=g[i][m][t-1]*g[m][j][t-1]%P;
                    if(t>=2)y=g[i][m][t-2]*g[m][j][t-2]%P;
                    add(f[i][j][t],C(j-i-2,m-i-1)*(x-y+P)%P);    
                }
            }
            for(int t=1;t<=n;t++)
                g[i][j][t]=(g[i][j][t-1]+f[i][j][t])%P;
            w[i][j]=g[i][j][j-i-1];
        }
    }
    if(a[1]==0||a[1]==-1)L[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i]!=-1&&a[i]!=0)continue;
        for(int j=1;j<i;j++)
        {
            add(L[i],C(i-2,j-1)*L[j]%P*w[j][i]%P);
        }
    }
    if(a[n]==0||a[n]==-1)R[n]=1;
    for(int i=n-1;i>=1;i--)
    {
        if(a[i]!=-1&&a[i]!=0)continue;
        for(int j=n;j>i;j--)
        {
            add(R[i],C(n-i-1,n-j)*R[j]%P*w[i][j]%P);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        add(ans,C(n-1,i-1)*L[i]%P*R[i]%P);
    }
    cout<<ans<<endl;
    return 0;
}