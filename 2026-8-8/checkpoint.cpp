#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10;
const double eps=1e-9;
int n,k;
long double p,q,ans,s,now;
long double f[N],g[N],pw[N],pre[N];

signed main()
{
    freopen("checkpoint.in","r",stdin);
    freopen("checkpoint.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k>>p;k=min(k,500ll);
    q=1-p;
    pw[1]=1;
    for(int i=2;i<=n;i++)pw[i]=pw[i-1]*q;
    for(int i=1;i<=n;i++)pre[i]=pre[i-1]+pw[i];
    s=pre[n];
    ans=s/(1-p*s);
    f[n+1]=0;
    for(int i=n;i>=1;i--)f[i]=1+q*f[i+1]+p*ans;
    for(int o=1;o<=k;o++)
    {
        now=0;
        for(int i=1;i<=n;i++)now+=pw[i]*f[i];
        long double sum=0,A=0;
        if(o>1&&f[0]>eps)break;
        for(int i=0;i<=n;i++)f[i]=0.0;
        for(int i=0;i<=n;i++)
        {
            A=(s+p*(now-sum))/(1-p*pre[i]);
            if((i==0||f[i]>A)&&(i==n||A>=f[i+1]))
                break;
            sum+=pw[i+1]*f[i+1];
        }
        ans=A;
        g[n+1]=0;
        for(int i=n;i>=1;i--)
            g[i]=1+q*g[i+1]+p*min(f[i],ans);
        for(int i=1;i<=n;i++)f[i]=g[i];
    }
    cout<<fixed<<setprecision(12)<<(double)ans<<endl;
    return 0;
}
