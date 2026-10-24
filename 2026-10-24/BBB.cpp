#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define lowbit(x) (x&(-x))
using namespace std;
const int N=5005,M=N*N+10,INF=1e18;
int n,m,w,k,cnt;
int a[N],b[N],f[N][N];
int d[M*2],now=0,t[M*2];
struct node
{
    int i,j,x,y,val;
}c[M];
bool cmpi(node x,node y)
{
    return x.i==y.i?x.j>y.j:x.i>y.i;
}
bool cmpj(node x,node y)
{
    return x.j==y.j?x.i>y.i:x.j>y.j;
}
int get(int x)
{
    return lower_bound(d+1,d+1+now,x)-d;
}
void upd(int x,int d)
{
    for(int i=x;i<=now;i+=lowbit(i))
    {
        if(d==-1)t[i]=INF;
        else t[i]=min(t[i],d);
    }
}
int query(int x)
{
    int res=INF;
    for(int i=x;i;i-=lowbit(i))
        res=min(res,t[i]);
    return res;
}
void cal(int l,int r)
{
    if(l==r)return;
    int mid=(l+r)>>1;
    cal(l,mid);
    sort(c+mid+1,c+1+r,cmpj);
    sort(c+l,c+1+mid,cmpj);
    int p=l;
    for(int i=mid+1;i<=r;i++)
    {
        while(p<=mid&&c[p].j>=c[i].j)
        {
            upd(c[p].y,c[p].val);
            p++;
        }
        c[i].val=min(c[i].val,query(c[i].x)+1);
    }
    for(int i=l;i<=mid;i++)
        upd(c[p].y,-1);
    sort(c+mid+1,c+1+r,cmpi);
    cal(mid+1,r);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>w>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i],a[i]+=a[i-1];
    for(int i=1;i<=m;i++)
        cin>>b[i],b[i]+=b[i-1];
    // for(int i=1;i<=n;i++)
    //     cout<<a[i]<<" ";cout<<endl;
    // for(int i=1;i<=m;i++)
    //     cout<<b[i]<<" ";cout<<endl;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            d[++now]=a[i]+b[j];
            d[++now]=a[i]+b[j]+w;
        }
    }
    sort(d+1,d+1+now);
    now=unique(d+1,d+1+now)-d-1;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            c[++cnt]={i,j,get(a[i]+b[j]+w),get(a[i]+b[j]),INF};
            if(i==n&&j==m)c[cnt].val=0;
        }
    }
    sort(c+1,c+1+cnt,cmpi);
    cal(1,cnt);
    int ans=0;
    for(int i=1;i<=cnt;i++)
        ans=max(ans,c[i].val);
    cout<<ans<<endl;
    return 0;
}