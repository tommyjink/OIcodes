#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=5e4+10,K=20;
int n,k,a[N],sum[N],f[K][N],g[N][K];
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
            b[i].push_back({l,p-1});
        }
    }
    f[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int t=1;t<=min(i,k);t++)
        {
            f[i][t]=g[]
        }
    }
    return 0;
}