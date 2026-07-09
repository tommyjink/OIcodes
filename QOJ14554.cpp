#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=16,M=52,K=1e4+10,INF=4e18;
int n,m,k,T,v[N][K],t[M],dp[M][1<<N];
int cnt[M],l[M][M],to[M][M],f[1<<N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>k>>T;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=k;j++)
            cin>>v[i][j];
    for(int i=1;i<=m;i++)
    {
        cin>>cnt[i]>>t[i];
        for(int j=1;j<=cnt[i];j++)
            cin>>l[i][j]>>to[i][j];
    }
    for(int tt=0;tt<=T;tt++)
        for(int j=0;j<(1<<n);j++)
            dp[tt][j]=-INF;
    dp[0][0]=0;
    for(int i=1;i<=m;i++)
    {
        for(int tt=T;tt>=t[i];tt--)
        {
            for(int s=0;s<(1<<n);s++)
                f[s]=dp[tt-t[i]][s];
            for(int j=1;j<=cnt[i];j++)
            {
                int c=l[i][j],val=v[c][to[i][j]]-v[c][0],bit=1<<(c-1);
                for(int s=0;s<(1<<n);s++)
                {
                    if(s&bit)continue;
                    if(f[s]!=-INF)f[s|bit]=max(f[s|bit],f[s]+val);
                }
            }
            for(int s=0;s<(1<<n);s++)
                dp[tt][s]=max(dp[tt][s],f[s]);
        }
    }
    int bas=0;
    for(int i=1;i<=n;i++)
        bas+=v[i][0];
    int ans=0;
    for(int tt=1;tt<=T;tt++)
    {
        for(int s=0;s<(1<<n);s++)
            ans=max(ans,dp[tt][s]);
        cout<<ans+bas<<endl;
    }
    return 0;
}