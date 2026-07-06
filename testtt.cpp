#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,x,y,z,a[N],b[N],p[N];
int f[2][N],l=1;
struct node
{
    int l,r,val;
}t[N*8];
void pushup(int k)
{
    t[k].val=t[k*2].val+t[k*2+1].val;
}
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    if(l==r)
    {
        t[k].val=1;
        return;
    }
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    pushup(k);
}
void add(int k,int l,int r,int d)
{
    if(t[k].l>r||t[k].r<l)return;
    if(l<=t[k].l&&t[k].r<=r)
    {
        t[k].val+=d*(t[k].r-t[k].l+1);
        return;
    }
    add(k*2,l,r,d);
    add(k*2+1,l,r,d);
    pushup(k);
}
int query(int k,int l,int r)
{
    if(t[k].l>r||t[k].r<l)return 0;
    if(l<=t[k].l&&t[k].r<=r)return t[k].val;
    return query(k*2,l,r)+query(k*2+1,l,r);
}
int sum(int l,int r)
{
    if(l>r)r+=n;
    if(r-l>=n)r-=n;
    return query(1,l,r);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>x>>y>>z;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    for(int i=1;i<=n;i++)
        p[a[i]]=i;
    build(1,1,2*n);
    f[1][0]=z;
    for(int i=1;i<=n;i++)
    {
        int sum1=sum(l,p[b[i]])-sum(p[b[i]],p[b[i]]);
        int sum2=sum(p[b[i]]+1,l+n);
        // printf("%lld %lld %lld\n",i,sum1,sum2);
        cout<<x<<" "<<y<<" "<<z<<endl;
        f[0][i]= min(min(f[0][i-1] + sum1 * x, f[0][i-1] + sum2 * y), min(f[1][i-1] + sum1 * x + z, f[1][i-1] + sum2 * y + z));
        f[1][i] = min(min(f[0][i-1] + sum1 * y + z, f[0][i-1] + sum2 * x + z), min(f[1][i-1] + sum1 * y, f[1][i-1] + sum2 * x));
        add(1,p[b[i]],p[b[i]], -1);
        add(1,p[b[i]] + n,p[b[i]] + n, -1);
        l = p[b[i]];
    }
    cout<<min(f[0][n],f[1][n]);
    return 0;
}