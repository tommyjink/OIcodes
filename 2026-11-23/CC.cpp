#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=5e4+10,K=20,P=998244353;
int n,k,a[N],sum[N],f[N][K],g[N][K];
vector<pii> b[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i],sum[i]=sum[i-1]+a[i];
    vector<int> s;
    for(int i=1;i<=n;i++)
    {
        s.push_back(i);
        vector<int> now;
        for(int p:s)
            if(a[p]>sum[i]-sum[p])
                now.push_back(p);
        s=now;
        for(int p:s)
        {
            int l=0,r=p-1;
            while(l<r)
            {
                int mid=(l+r)>>1;
                if(2*a[p]<=sum[i]-sum[mid])l=mid+1;
                else r=mid;
            }
            b[i].push_back({l,p});
        }
    }
    f[0][0]=1;
    for(int i=0;i<=n;i++)
        g[i][0]=1;
    for(int t=1;t<=k;t++)
    {
        for(int i=t;i<=n;i++)
        {
            f[i][t]=g[i-1][t-1];
            for(auto [L,p]:b[i])
                f[i][t]=(f[i][t]-(g[p-1][t-1]-(L?g[L-1][t-1]:0)+P)%P+P)%P;
        }
        for(int i=1;i<=n;i++)
            g[i][t]=(g[i-1][t]+f[i][t])%P;
    }
    cout<<f[n][k]<<endl;
    return 0;
}