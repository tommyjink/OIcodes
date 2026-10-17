#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,INF=1e16;
int n,v[N],cnt=0,f[N];
void solve()
{
    cin>>n;
    n++;
    cnt=0;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i)continue;
        v[++cnt]=i;
        // if(i*i!=n)v[++cnt]=n/i;
    }
    for(int i=cnt;i>=1;i--)
        if(v[i]*v[i]!=n)v[++cnt]=n/v[i];
    for(int i=1;i<=cnt;i++)
        f[i]=INF;
    f[1]=0;
    for(int i=1;i<=cnt;i++)
    {
        for(int j=i;j<=cnt;j++)
            f[j]=min(f[j],f[i]+(v[j]-1)/v[i]);
    }
    cout<<f[cnt]<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}