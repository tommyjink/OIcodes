#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl "\n"
using namespace std;
const int N=5005,INF=1e15;
int n,m,k,a[N],b[N],c[N],d[N],e[N];
int dp[N][N];
vector<int> v[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>k;
    int now=k;
    for(int i=1;i<=n;i++)
    {
        d[i]=i;
        cin>>a[i]>>b[i]>>c[i];
        if(now<a[i])
        {
            cout<<"-1"<<endl;
            return 0;
        }
        e[i-1]=now-a[i];
        now+=b[i];
    }
    e[n]=now;
    for(int i=n-1;i>=0;i--)
        e[i]=min(e[i],e[i+1]);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        d[y]=max(d[y],x);
    }
    for(int i=1;i<=n;i++)
        v[d[i]].emplace_back(c[i]);
    for(int i=1;i<=n;i++)
        sort(v[i].begin(),v[i].end(),greater<int>());
    for(int i=1;i<=n;i++)
        for(int j=1;j<v[i].size();j++)
            v[i][j]+=v[i][j-1];
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            dp[i][j]=-INF;
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=e[i];j++)
        {
            dp[i][j]=max(dp[i][j],dp[i-1][j]);
            for(int ii=1;ii<=min(j,(int)v[i].size());ii++)
            {
                dp[i][j]=max(dp[i][j],dp[i-1][j-ii]+v[i][ii-1]);
            }
        }
    }
    int ans=-1;
    for(int i=0;i<=e[n];i++)
        ans=max(ans,dp[n][i]);
    cout<<ans<<endl;
    return 0;
}