#include<bits/stdc++.h>
#define int long long
#define lowbit(x) (x&(-x))
#define endl "\n"
using namespace std;
const int N=4e6+10;
int n,a[N],b[N],f[N],t[N],c[N],d[N];
string s;
bool cmp(int x,int y)
{
    if(a[x]!=a[y])return a[x]<a[y];
    return x<y;
}
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
void CDQ(int l,int r)
{
    if(l==r)
    {
        if(l)f[l]=max(f[l],f[l-1]);
        return;
    }
    int mid=(l+r)>>1;
    int pl=l,pr=mid+1;
    for(int i=l;i<=r;i++)
    {
        if(c[i]<=mid)d[pl++]=c[i];
        else d[pr++]=c[i];
    }
    for(int i=l;i<=r;i++)c[i]=d[i];
    CDQ(l,mid);
    int p=l;
    for(int k=mid+1;k<=r;k++)
    {
        int i=c[k];
        while(p<=mid&&a[c[p]]<=a[i])
        {
            int j=c[p++];
            modify(b[j],f[j]-j);
        }
        int now=query(b[i]);
        if(now!=-N)f[i]=max(f[i],i+now);
    }
    for(int k=l;k<p;k++)clear(b[c[k]]);
    CDQ(mid+1,r);
    pl=l,pr=mid+1,p=l;
    while(pl<=mid&&pr<=r)
    {
        if(a[c[pl]]<a[c[pr]]||(a[c[pl]]==a[c[pr]]&&c[pl]<c[pr]))d[p++]=c[pl++];
        else d[p++]=c[pr++];
    }
    while(pl<=mid)d[p++]=c[pl++];
    while(pr<=r)d[p++]=c[pr++];
    for(int i=l;i<=r;i++)c[i]=d[i];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>s;
    fill(t,t+N,-N);
    for(int i=1;i<=n;i++)
    {
        int c=s[i-1]-'0';
        int x=(c&4)?1:0;
        int y=(c&2)?1:0;
        int z=(c&1)?1:0;
        a[i]=a[i-1]+x-y;
        b[i]=b[i-1]+x-z;
    }
    for(int i=0;i<=n;i++)c[i]=i;
    sort(c,c+n+1,cmp);
    CDQ(0,n);
    cout<<f[n]<<endl;
    return 0;
}