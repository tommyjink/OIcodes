#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10,P=998244353;
int n,a[N],b[N],f[N],g[N],x[N],tot=0;
string s;
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
void solve()
{
    cin>>n>>s;
    s=" "+s;
    tot=0;
    for(int i=1;i<=n;i++)
    {
        a[i]=s[i]-'0';
        b[i]=b[i-1]+a[i];
        if(a[i])x[++tot]=i;
    }
    for(int i=0;i<=x[tot];i++)
        f[i]=g[i]=0;
    f[0]=1;
    int cnt=0;
    for(int i=1;i<=tot;i++)
    {
        if(i==x[i]){cnt++;continue;}
        g[0]=f[0];
        for(int j=1;j<=x[i]-cnt;j++)
            g[j]=(g[j-1]+f[j])%P;
        for(int j=0;j<=x[tot]-cnt;j++)
            f[j]=g[j];
        // for(int j=0;j<=x[tot]-cnt;j++)
        //     cout<<f[j]<<" ";
        // cout<<endl;
    }
    int ans=0;
    for(int i=0;i<=x[tot]-cnt;i++)
        ans=(ans+f[i])%P;
    
    cout<<ans<<endl;

}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}