#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5005;
int n,s,t[N],f[N],dp[N];
int q[N],l=1,r=1,x[N],y[N];
double slope(int i,int j){return (1.0*y[i]-1.0*y[j])/(1.0*x[i]-1.0*x[j]);}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>s;
    for(int i=1;i<=n;i++)cin>>t[i]>>f[i],t[i]+=t[i-1],f[i]+=f[i-1];
    for(int i=1;i<=n;i++)
    {
        while(l<r&&slope(q[l],q[l+1])<1.0*(t[i]+s))l++;
        int j=q[l];dp[i]=dp[j]-(t[i]+s)*f[j]+s*f[n]+t[i]*f[i];
        x[i]=f[i],y[i]=dp[i];
        while(l<r&&slope(i,q[r-1])<slope(q[r],q[r-1]))r--;
        q[++r]=i;
    }
    cout<<dp[n]<<endl;
    return 0;
}