#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5010,inf=4e18;
int n,k,tot,cnt,ans;
int f[N],g[N],val[N],q[N],vis[N],len[N],len1[N],sum[N];

struct node
{
    int l,r;
}a[N],b[N];

bool cmp(node x,node y)
{
    if(x.l!=y.l)return x.l<y.l;
    return x.r<y.r;
}

bool cmp1(int x,int y)
{
    return x>y;
}

signed main()
{
    freopen("se.in","r",stdin);
    freopen("se.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].l>>a[i].r;
        len1[i]=a[i].r-a[i].l;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j&&a[i].l<=a[j].l&&a[j].r<=a[i].r&&(a[i].l<a[j].l||a[j].r<a[i].r))
                vis[i]=1;
    for(int i=1;i<=n;i++)
        if(!vis[i])b[++tot]=a[i];
        else len[++cnt]=a[i].r-a[i].l;
    sort(b+1,b+1+tot,cmp);
    sort(len+1,len+1+cnt,cmp1);
    sort(len1+1,len1+1+n,cmp1);
    for(int i=1;i<=cnt;i++)sum[i]=sum[i-1]+len[i];
    for(int i=1;i<=min(n,k-1);i++)ans+=len1[i];
    for(int i=1;i<=tot;i++)f[i]=-inf;
    f[0]=0;
    for(int o=1;o<=min(k,tot);o++)
    {
        for(int i=0;i<=tot;i++)g[i]=-inf;
        int l=1,r=0,p=0,mx=-inf;
        for(int i=1;i<=tot;i++)
        {
            val[i]=f[i-1]+b[i].r;
            while(l<=r&&val[q[r]]<=val[i])r--;
            q[++r]=i;
            while(p<i&&b[p+1].r<=b[i].l)
            {
                p++;
                mx=max(mx,f[p-1]);
            }
            while(l<=r&&q[l]<=p)l++;
            if(mx>-inf/2)g[i]=max(g[i],mx);
            if(l<=r&&val[q[l]]>-inf/2)g[i]=max(g[i],val[q[l]]-b[i].l);
        }
        for(int i=0;i<=tot;i++)f[i]=g[i];
        if(f[tot]>-inf/2)
        {
            int x=min(cnt,k-o);
            ans=max(ans,f[tot]+sum[x]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
