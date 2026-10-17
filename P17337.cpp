#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10,P=998244353;
int n,a[N],b[N],f[N],x[N],tot=0;
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
    int lim=tot?x[tot]-tot+1:0;
    for(int i=0;i<=lim;i++)
        f[i]=0;
    f[0]=1;
    for(int i=1;i<=tot;i++)
    {
        if(i==x[i])continue;
        int up=x[i]-i+1;
        for(int j=1;j<=up;j++)
        {
            f[j]+=f[j-1];
            if(f[j]>=P)f[j]-=P;
        }
    }
    int ans=0;
    for(int i=0;i<=lim;i++)
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
