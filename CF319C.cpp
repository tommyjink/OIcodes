#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10;
int n,f[N],a[N],b[N],q[N],l,r;
double x[N],y[N];
double slope(int i,int j)
{
    if(x[i]==x[j]&&y[i]>y[j])return -1e18;
    else if(x[i]==x[j]&&y[i]<y[j])return 1e18;
    return (y[i]-y[j])/(x[i]-x[j]);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    l=r=1;
    q[1]=0;
    for(int i=1;i<=n;i++)
    {
        while(l<r&&slope(q[l],q[l+1])<1.0*a[i])l++;
        int j=q[l];f[i]=f[j]+a[i]*b[j];
        x[i]=-b[i],y[i]=f[i];
        while(l<r&&slope(q[r-1],q[r])>slope(q[r-1],i))r--;
        q[++r]=i;
    }
    cout<<f[n]<<endl;
    return 0;
}