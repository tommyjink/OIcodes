#include<bits/stdc++.h>
#define int long long
#define lowbit(x) (x&(-x))
#define endl "\n"
using namespace std;
const int N=4e6+10;
int n,a[N],b[N],f[N],t[N],c[N],d[N];
string s;
void modify(int x,int val)
{
    x+=N/2;
    for(int i=x;i<=N/2+n+1;i+=lowbit(i))t[i]=max(t[i],val);
}
void clear(int x)
{
    x+=N/2;
    for(int i=x;i<=N/2+n+1;i+=lowbit(i))t[i]=-N;
}
int query(int x)
{
    int res=-N;
    x+=N/2;
    for(int i=x;i;i-=lowbit(i))res=max(res,t[i]);
    return res;
}
void CDQ(int l,int r,int tag)
{
    if(l==r){f[l]=f[l-1];return;}
    int mid=(l+r)>>1;
    CDQ(l,mid,1);
    CDQ(mid+1,r,0);
    if(tag)
    {
        int p=l,now=0;
        for(int i=mid+1;i<=r;i++)
        {
            while(p<=mid&&a[p]<=a[i])modify(b[p],f[p]-p),p++;
            f[i]=max({f[i],f[i-1],i+query(b[i])});
            modify(b[i],f[i]-i);
        }
        for(int i=l;i<=r;i++)clear(b[i]);
    }
    int pl=l,pr=mid+1;
    int p=l-1;
    while(pl<=mid&&pr<=r)
    {
        if(a[pl]<a[pr])c[++p]=a[pl],d[p]=b[pl],pl++;
        else c[++p]=a[pr],d[p]=b[pr],pr++;
    }
    while(pl<=mid)c[++p]=a[pl],d[p]=b[pl],pl++;
    while(pr<=r)c[++p]=a[pr],d[p]=b[pr],pr++;
    for(int i=l;i<=r;i++)
        a[i]=c[i],b[i]=d[i];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>s;
    for(int i=-n;i<=n;i++)clear(i);
    for(int i=1;i<=n;i++)
    {
        int c=s[i-1]-'0';
        int x=(c&4)?1:0;
        int y=(c&2)?1:0;
        int z=(c&1)?1:0;
        a[i]=a[i-1]+x-y;
        b[i]=b[i-1]+x-z;
    }
    CDQ(0,n,1);
    cout<<f[n]<<endl;
    return 0;
}