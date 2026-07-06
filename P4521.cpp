#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl "\n"
using namespace std;
const int N=1e6+10,P=1e9+7;
int n,m,k,r[N],s[N],ans=0;
vector<int> vs,vr;
int qpow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)res=res*x%P;
        x=x*x%P,y>>=1;
    }
    return res;
}
int cal_r(int x)
{
    int l=(x-1)*m%P+1,r=x*m%P;
    return (l+r)%P*m%P*qpow(2,P-2)%P;
}
int cal_s(int x)
{
    int l=x,r=((n-1)*m%P+x)%P;
    return (l+r)%P*n%P*qpow(2,P-2)%P;
}
int cal(int x,int y)
{
    return ((x-1)*m%P+y)%P;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>k;
    ans=(1+(n*m%P))*(n*m%P)%P*qpow(2,P-2)%P;
    for(int i=1;i<=n;i++)r[i]=1;
    for(int i=1;i<=m;i++)s[i]=1;
    for(int i=1;i<=k;i++)
    {
        char op;
        int x,y;
        cin>>op>>x>>y;
        if(op=='R')r[x]=r[x]*y%P;
        if(op=='S')s[x]=s[x]*y%P;
    }

    for(int i=1;i<=n;i++)if(r[i]!=1)
    {
        vr.push_back(i);
        ans=(ans+cal_r(i)*(r[i]-1)%P)%P;
        // printf("i=%lld,ans+=%lld\n",i,cal_r(i)*(r[i]-1));
    }
    for(int i=1;i<=m;i++)if(s[i]!=1)
    {
        vs.push_back(i);
        ans=(ans+cal_s(i)*(s[i]-1)%P)%P;
        // printf("!i=%lld,ans+=%lld\n",i,cal_s(i)*(s[i]-1));
    }
    for(auto i:vr)
    {
        for(auto j:vs)
        {
            ans=((ans-cal(i,j)*(r[i]-1)%P-cal(i,j)*(s[j]-1)%P)%P+P)%P;
            // printf("i=%lld,j=%lld,ans+=%lld\n",i,j,-cal(i,j)*(r[i]-1)-cal(i,j)*(s[j]-1));
            ans=(ans+cal(i,j)*((s[j]*r[i]%P-1)%P+P)%P)%P;
            // printf("!i=%lld,j=%lld,ans+=%lld,s[i]=%lld,r[i]=%lld\n",i,j,cal(i,j)*(s[j]*r[i]-1),s[j],r[i]);
        }
    }
    cout<<ans<<endl;

    return 0;
}