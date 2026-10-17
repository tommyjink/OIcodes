#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define lowbit(x) (x&(-x))
using namespace std;
const int N=1e4+10,M=65,P=998244353;
int n,K,L,R,a[N],f[N][M],t[N][M];
int c[N],tot=0,b[N];
struct node
{
    int t[N];
    void init()
    {
        for(int i=0;i<=n+2;i++)
            t[i]=0;
    }
    void add(int x,int d)
    {
        x++;
        for(int i=x;i<=n+2;i+=lowbit(i))
            t[i]=(t[i]+d)%P;
    }
    int sum(int x)
    {
        x++;
        int res=0;
        for(int i=x;i;i-=lowbit(i))
            res=(res+t[i])%P;
        return res;
    }
}g[M];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("turn.in","r",stdin);
    freopen("turn.out","w",stdout);
    cin>>n>>K>>L>>R;
    for(int i=1;i<=n;i++)
        cin>>a[i],c[i]=a[i],b[i]=a[i];
    sort(c+1,c+1+n);
    tot=unique(c+1,c+1+n)-c-1;
    for(int i=1;i<=n;i++)
        b[i]=lower_bound(c+1,c+1+tot,b[i])-c;
    f[0][0]=1;
    g[0].add(0,1);
    // for(int i=1;i<=tot;i++)cout<<c[i]<<" ";
    // cout<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=K;j++)
        {
            f[i][j]=g[j-1].sum(b[i]-1);
            // printf("f[%lld][%lld]=%lld\n",i,j,f[i][j]);
            g[j].add(b[i],f[i][j]);
        }
    }
    for(int i=0;i<=K;i++)g[i].init();
    t[n+1][0]=1;
    g[0].add(n+1,1);
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=K;j++)
        {
            t[i][j]=(g[j-1].sum(n+1)-g[j-1].sum(b[i])+P)%P;
            g[j].add(b[i],t[i][j]);
        }
    }
    // for(int i=1;i<=n;i++)
    //     for(int j=1;j<=K;j++)
    //         printf("t[%lld][%lld]=%lld\n",i,j,t[i][j]);
    for(int i=0;i<=K;i++)g[i].init();
    int ans=0;
    for(int i=n;i>=2;i--)
    {
        for(int j=1;j<=K;j++)
            g[j].add(b[i],t[i][j]);
        int l=lower_bound(c+1,c+1+tot,a[i-1]-R)-c;
        int r=upper_bound(c+1,c+1+tot,a[i-1]-L)-c-1;
        // cout<<i<<":"<<l<<","<<r<<endl;
        if(l>r)continue;
        for(int j=1;j<=K-1;j++)
        {
            ans=(ans+f[i-1][j]*(g[K-j].sum(r)-g[K-j].sum(l-1)+P)%P)%P;
            // printf("ans+=f[%lld][%lld](%lld)*(g[%lld].sum(%lld)(%lld)-g[%lld].sum[%lld](%lld))\n",i-1,j,f[i-1][j],K-j,r,g[K-j].sum(r),K-j,l-1,g[K-j].sum(l-1));
        }
    }
    cout<<ans<<endl;
    return 0;
}