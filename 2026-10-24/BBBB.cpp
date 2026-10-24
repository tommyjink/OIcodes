#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5005;
int n,m,w,k,a[N],b[N],f[N],g[N],c[N],q[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>w>>k;
    for(int i=1;i<=n;i++)cin>>a[i],a[i]+=a[i-1];
    for(int i=1;i<=m;i++)cin>>b[i],b[i]+=b[i-1];
    for(int i=1;i<=n;i++)f[i]=-1;
    for(int ans=1;ans<=n+m;ans++)
    {
        int l=1,r=0,j=m;
        for(int i=0;i<=n;i++)
        {
            if(f[i]>=0)
            {
                c[i]=a[i]+b[f[i]];
                while(l<=r&&c[q[r]]<=c[i])r--;
                q[++r]=i;
            }
            while(l<=r&&a[i]-a[q[l]]>w)l++;
            if(l>r)
            {
                g[i]=-1;
                continue;
            }
            int x=c[q[l]]+w-a[i];
            while(j>0&&b[j]>x)j--;
            g[i]=j;
        }
        for(int i=0;i<=n;i++)f[i]=g[i];
        if(f[n]>=m)
        {
            cout<<ans*k<<endl;
            return 0;
        }
    }
    return 0;
}
