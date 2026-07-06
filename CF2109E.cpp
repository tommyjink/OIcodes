#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=600,P=998244353;
int n,K,f[N][N],a[N],b[N];
string s;
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
int F(int x)
{
    return qpow(x,P-2);
}
int C(int x,int y)
{
    if(x<y)return 0;
    return a[x]*b[x-y]%P*b[y]%P;
}
void solve()
{
    memset(f,0,sizeof(f));
    cin>>n>>K>>s;
    s=" "+s;
    f[n+1][0]=1;
    for(int i=n+1;i>=2;i--)
    {
        for(int j=0;j<=K;j++)
        {
            for(int k=0;k+j<=K;k++)
            {
                if(s[i-1]=='0')f[i-1][j+k]=(f[i-1][j+k]+f[i][j]*C((j+k+1)/2,k)%P)%P;
                if(s[i-1]=='1')f[i-1][j+k]=(f[i-1][j+k]+f[i][j]*C((j+k)/2,k)%P)%P;
            }
        }
    }
    cout<<f[1][K]<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    a[0]=b[0]=1;
    for(int i=1;i<N;i++)a[i]=a[i-1]*i%P;
    for(int i=1;i<N;i++)b[i]=b[i-1]*F(i)%P;
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}