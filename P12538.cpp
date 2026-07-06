#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,P=998244353;
int n,a[N],fa[N],col[N],cc[N],dp[N];
bool g(int x,int y)
{
    return abs(x-y)==1;
}
int getfa(int x)
{
    if(x==fa[x])return fa[x];
    return (fa[x]=getfa(fa[x]));
}
void merge(int x,int y)
{
    int fx=getfa(x),fy=getfa(y);
    if(fx==fy)return;
    fa[fy]=fx;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],fa[i]=i;
    for(int i=2;i<=n;i++)
        if(g(a[i-1],a[i]))merge(i-1,i);
    for(int i=3;i<=n;i++)
        if(g(a[i-1],a[i-2])&&g(a[i-2],a[i]))
            merge(i-1,i);
    for(int i=1;i<=n-2;i++)
        if(g(a[i+1],a[i+2])&&g(a[i+2],a[i]))
            merge(i+1,i);
    for(int i=1;i<=n-3;i++)
        if(g(a[i],a[i+1])&&g(a[i+2],a[i+3])&&g(a[i],a[i+3]))
            merge(i,i+3);
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(getfa(i)!=getfa(i-1))col[i]=++cnt;
        else col[i]=cnt;
        cc[cnt]++;
        // cout<<col[i]<<" ";
    }
    dp[0]=dp[1]=1;
    for(int i=2;i<=n;i++)
        dp[i]=(dp[i-1]+dp[i-2])%P;
    int ans=1;
    for(int i=1;i<=cnt;i++)
        ans=ans*dp[cc[i]]%P;
    cout<<ans<<endl;
    return 0;
}