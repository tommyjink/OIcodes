#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5005,P=1e9+7;
int n,m,k,s[N],c[N],e[30],f[N],g[N];
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
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        cin>>s[i]>>c[i];
    for(int i=1;i<=m;i++)
    {
        char c;cin>>c;
        e[c-'A'+1]++;
    }
    f[0]=1;
    for(int i=0;i<=k;i++)
    {   
        for(int j=1;j<=n;j++)
        {
            if(i>=s[j])f[i]=(f[i]+f[i-s[j]])%P;
        }
    }
    for(int i=1;i<=n;i++)
        g[c[i]]=(g[c[i]]+f[k-s[i]])%P;
    int ans=1;
    for(int i=1;i<=26;i++)
    {
        if(!e[i])continue;
        int res=0;
        for(int j=1;j<=n;j++)
        {
            res=(res+qpow(g[j],e[i]))%P;
        }
        ans=ans*res%P;
    }
    cout<<ans<<endl;
    return 0;
}