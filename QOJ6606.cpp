#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=3e5+10,INF=1e18;
int n,m,r,d[N],k[N],c[N];
int a[N],cnt=0,f[N],l[N];

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>r;
    for(int i=1;i<=n;i++)
        cin>>d[i]>>k[i]>>c[i];
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        while(y--)a[++cnt]=x;
    }
    sort(a+1,a+1+cnt);
    for(int i=1;i<=n;i++)l[i]=1;
    for(int i=1;i<=cnt;i++)f[i]=INF;
    f[0]=0;
    for(int i=1;i<=cnt;i++)
    {
        for(int j=1;j<=n;j++)
        {
            while(i-l[j]+1>k[j]||a[i]-a[l[j]]+1>d[j])l[j]++;
            if(l[j]>i)continue;
            // cout<<i<<","<<l[j]<<endl;
            f[i]=min(f[i],f[l[j]-1]+c[j]);
        }
    }
    cout<<f[cnt]<<endl;
    return 0;
}