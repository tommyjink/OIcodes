#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=4010,M=4100,mod=998244353;
int n,m,s,lim,ans;
int a[N];
signed f[N][M],g[N],h[M];

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>s;
    lim=1<<m;
    for(int i=1;i<=n;i++)cin>>a[i];
    ans=(n+n*(n-1)/2)%mod;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<lim;j++)f[i][j]=h[j];
        for(int j=1;j<i;j++)
        {
            int x=s^a[j]^a[i];
            int w=(j-1+g[j]-f[j][x])%mod;
            if(w<0)w+=mod;
            ans+=w;
            if(ans>=mod)ans-=mod;
            g[i]+=w;
            if(g[i]>=mod)g[i]-=mod;
            x=a[j]^a[i];
            h[x]=(h[x]+w+1)%mod;
        }
    }
    cout<<ans<<endl;
    return 0;
}
]
