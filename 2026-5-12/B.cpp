#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=6010,INF=4e18;
int n,k,a[N],b[N],f[N],g[N],bit[N],cost[N][N];
void add(int x)
{
    while(x<=n)bit[x]++,x+=x&-x;
}
int ask(int x)
{
    int s=0;
    while(x)s+=bit[x],x-=x&-x;
    return s;
}
void solve(int l,int r,int L,int R)
{
    if(l>r)return;
    int mid=l+r>>1,res=L;
    g[mid]=INF;
    for(int i=L;i<=min(R,mid-1);i++)
        if(f[i]+cost[i+1][mid]<g[mid])
            g[mid]=f[i]+cost[i+1][mid],res=i;
    solve(l,mid-1,L,res);
    solve(mid+1,r,res,R);
}
void work()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i],b[i]=a[i];
    sort(b+1,b+n+1);
    int m=unique(b+1,b+n+1)-b-1;
    for(int i=1;i<=n;i++)a[i]=lower_bound(b+1,b+m+1,a[i])-b;
    for(int l=1;l<=n;l++)
    {
        for(int i=1;i<=m;i++)bit[i]=0;
        int now=0;
        for(int r=l;r<=n;r++)
        {
            now+=r-l-ask(a[r]);
            add(a[r]);
            cost[l][r]=now;
        }
    }
    for(int i=0;i<=n;i++)f[i]=INF;
    f[0]=0;
    for(int t=1;t<=k+1;t++)
    {
        g[0]=0;
        solve(1,n,0,n-1);
        for(int i=1;i<=n;i++)g[i]=min(g[i],f[i]);
        for(int i=0;i<=n;i++)f[i]=g[i];
    }
    cout<<f[n]<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--)work();
    return 0;
}
