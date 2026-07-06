#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl "\n"
using namespace std;
const int N=1e5+10,P=998244353,B=450;
int n,m,fac[N],ifac[N],ans[N],dp[N];
vector<pii> q[N];
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
int C(int n,int m)
{
    if(n<0||m<0||n<m)return 0;
    return fac[n]*ifac[m]%P*ifac[n-m]%P;
}
int calc(int len,int k)
{
    if(len<=0)return 1;
    int res=1;
    for(int i=1;i*k<=len+k-1;i++)
        res=(res+C(len-(k-1)*(i-1),i))%P;
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    fac[0]=1;
    for(int i=1;i<=n;i++)
        fac[i]=fac[i-1]*i%P;
    ifac[n]=qpow(fac[n],P-2);
    for(int i=n-1;i>=0;i--)
        ifac[i]=ifac[i+1]*(i+1)%P;
    for(int i=1;i<=m;i++)
    {
        int x,k;
        cin>>x>>k;
        q[k].push_back({x,i});
    }
    for(int k=1;k<=n;k++)
    {
        if(q[k].empty())continue;
        if(k<=B)
        {
            dp[0]=1;
            for(int i=1;i<=n;i++)
            {
                dp[i]=dp[i-1];
                if(i>=k)
                    dp[i]=(dp[i]+dp[i-k])%P;
                else dp[i]=(dp[i]+1)%P;
            }
            for(auto [x,id]:q[k])
            {
                int res=dp[n];
                int l=x-k,r=n-x-k+1;
                int cnt=(l<=0?1:dp[l])*(r<=0?1:dp[r])%P;
                ans[id]=(res-cnt+P)%P;
            }
        }
        else
        {
            int res=calc(n,k);
            for(auto [x,id]:q[k])
            {
                int l=x-k,r=n-x-k+1;
                int cnt=calc(l,k)*calc(r,k)%P;
                ans[id]=(res-cnt+P)%P;
            }
        }
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<endl;
    return 0;
}