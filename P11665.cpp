#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5e6+10,V=22;
int n,a[N];
signed nxt1[N][V],nxt2[N][V],f[1ll<<V];
int cal(int s,int x)
{
    if(s&(1ll<<(x-1)))return s;
    int p=x;
    while(p>=1&&!(s&(1ll<<(p-1))))p--;
    if(p)s^=(1ll<<(p-1));
    s|=(1ll<<(x-1));
    return s;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=n;i>=1;i--)
    {
        for(int x=1;x<=21;x++)
            nxt1[i][x]=nxt1[i+1][x];
        nxt1[i][a[i]]=i;
    }
    for(int i=n-1;i>=1;i--)
    {
        for(int x=1;x<=21;x++)
            nxt2[i][x]=nxt2[nxt1[i+1][a[i]]][x];
        nxt2[i][a[i+1]]=i;
    }
    int ans=n+1;
    memset(f,-1,sizeof(f));
    f[0]=0;
    for(int s=0;s<(1ll<<21);s++)
    {
        if(f[s]<0)continue;
        int c[V],cnt=0;
        signed tmp=n+1,now=f[s];
        for(int i=1;i<=21;i++)
            if(!(s&(1ll<<(i-1))))
                c[++cnt]=i;
        for(int i=1;i<=cnt;i++)
            for(int j=1;j<=cnt;j++)
                if(nxt2[nxt1[now+1][c[i]]][c[j]])tmp=min(tmp,nxt2[nxt1[now+1][c[i]]][c[j]]);
        f[s]=max(f[s],tmp-1);
        if(f[s]+1<=n)f[cal(s,a[f[s]+1])]=max(f[cal(s,a[f[s]+1])],f[s]+1);
        if(f[s]+2<=n)f[cal(s,a[f[s]+2])]=max(f[cal(s,a[f[s]+2])],f[s]+2);
        if(f[s]>=n-1)ans=min(ans,(int)__builtin_popcount(s));
    }
    cout<<ans<<endl;
    return 0;
}