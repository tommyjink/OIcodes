#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e6+10,INF=1e16;
int n,x[N],p[N],c[N],b[N],d[N],y[N];
int X[N],Y[N],q[N],l=1,r=1,dp[N];
double slope(int i,int j)
{
    if(X[i]==X[j]&&Y[i]<=Y[j])return INF;
    if(X[i]==X[j]&&Y[i]>Y[j])return -INF;
    return (Y[i]*1.0-Y[j]*1.0)/(X[i]*1.0-X[j]*1.0);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>x[i]>>p[i]>>c[i];
    for(int i=1;i<=n;i++)
    {
        d[i]=d[i-1]+p[i];
        y[i]=x[n]-x[i];
        b[i]=b[i-1]+p[i]*y[i];
    }
    for(int i=1;i<=n;i++)
    {
        while(l<r&&slope(q[l],q[l+1])<-1.0*y[i])l++;
        int j=q[l];dp[i]=dp[j]+(b[i]-b[j])-(d[i]-d[j])*y[i]+c[i];
        X[i]=d[i],Y[i]=dp[i]-b[i];
        // printf("i=%lld,j=%lld,dp=%lld,X=%lld,Y=%lld\n",i,j,dp[i],X[i],Y[i]);
        while(l<r&&slope(q[r-1],i)<slope(q[r-1],q[r]))r--;
        q[++r]=i;
    }
    int ans=dp[n],i=n;
    while(i>=1&&!p[i])ans=min(ans,dp[--i]);
    cout<<ans<<endl;
    return 0;
}