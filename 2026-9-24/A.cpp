#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10,INF=4e18;
int n,k,a[N],c[N],b[N];
int gcd(int x,int y)
{
    return y?gcd(y,x%y):x;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>c[i];
    int g=gcd(n,k),ans=0,mnc=INF;
    for(int s=0;s<g;s++)
    {
        int u=s,mn=0,sum=0;
        b[u]=0;
        do
        {
            sum+=c[u];
            int v=(u+k)%n;
            if(v!=s)
            {
                b[v]=b[u]+a[v]-a[(v+n-1)%n];
                mn=min(mn,b[v]);
            }
            u=v;
        }while(u!=s);
        u=s;
        do
        {
            b[u]-=mn;
            ans+=b[u]*c[u];
            u=(u+k)%n;
        }while(u!=s);
        mnc=min(mnc,sum);
    }
    int sum=0;
    for(int i=0;i<k;i++)sum+=b[(n-i)%n];
    int t=(a[0]-sum)/(k/g);
    cout<<ans+t*mnc<<endl;
    return 0;
}
