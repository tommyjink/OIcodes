#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=(1<<21)+10;
const int M=(1<<20)+10;
int n,m,len,tot,top;
int a[M],b[M],c[M];
int f[N],g[N],id[N],val[N],sum[N];
int ls[N],rs[N],dep[N],rev[N],tag[N];
void turn(int k)
{
    if(dep[k]>=n)return;
    for(int i=dep[k];i<n;i++)
    {
        int p=id[k]+i-dep[k];
        f[p]=g[p]-f[p];
    }
    val[k]=sum[k]-val[k];
    swap(ls[k],rs[k]);
    rev[k]^=1;
}
void cover(int k,int d)
{
    if(dep[k]>=n)return;
    for(int i=d;i<n;i++)
    {
        int p=id[k]+i-dep[k];
        val[k]+=g[p]-2*f[p];
        f[p]=g[p]-f[p];
    }
    tag[k]^=(1u<<d);
}
void pushup(int k)
{
    if(dep[k]>=n)return;
    int l=ls[k],r=rs[k];
    for(int i=dep[k]+1;i<n;i++)
    {
        f[id[k]+i-dep[k]]=f[id[l]+i-dep[l]]+f[id[r]+i-dep[r]];
        g[id[k]+i-dep[k]]=g[id[l]+i-dep[l]]+g[id[r]+i-dep[r]];
    }
    val[k]=val[l]+val[r]+f[id[k]];
    sum[k]=sum[l]+sum[r]+g[id[k]];
}
void pushdown(int k)
{
    if(dep[k]>=n)return;
    if(rev[k])
    {
        turn(ls[k]);
        turn(rs[k]);
        rev[k]=0;
    }
    if(tag[k])
    {
        for(int i=dep[k]+1;i<n;i++)
        {
            if(!((tag[k]>>i)&1))continue;
            if(dep[ls[k]]==i)turn(ls[k]);
            else cover(ls[k],i);
            if(dep[rs[k]]==i)turn(rs[k]);
            else cover(rs[k],i);
        }
        tag[k]=0;
    }
}
void build(int k,int l,int r,int d)
{
    dep[k]=d;
    if(l==r)return;
    id[k]=top+1;
    top+=n-d;
    int mid=(l+r)>>1;
    ls[k]=++tot;
    rs[k]=++tot;
    build(ls[k],l,mid,d+1);
    build(rs[k],mid+1,r,d+1);
    int p1=l,p2=mid+1,res=0,same=0;
    while(p1<=mid&&p2<=r)
    {
        if(b[p1]<b[p2])p1++;
        else if(b[p1]>b[p2])p2++;
        else
        {
            int x=b[p1],c1=0,c2=0;
            while(p1<=mid&&b[p1]==x)p1++,c1++;
            while(p2<=r&&b[p2]==x)p2++,c2++;
            same+=c1*c2;
        }
    }
    p1=l,p2=mid+1;
    int p=l;
    while(p1<=mid&&p2<=r)
    {
        if(b[p1]<=b[p2])c[p++]=b[p1++];
        else
        {
            res+=mid-p1+1;
            c[p++]=b[p2++];
        }
    }
    while(p1<=mid)c[p++]=b[p1++];
    while(p2<=r)c[p++]=b[p2++];
    for(int i=l;i<=r;i++)
        b[i]=c[i];
    f[id[k]]=res;
    g[id[k]]=(mid-l+1)*(r-mid)-same;
    pushup(k);
}
void add(int k,int l,int r,int L,int R,int d)
{
    if(l>R||r<L)return;
    if(L<=l&&r<=R)
    {
        if(dep[k]==d)turn(k);
        else cover(k,d);
        return;
    }
    pushdown(k);
    int mid=(l+r)>>1;
    add(ls[k],l,mid,L,R,d);
    add(rs[k],mid+1,r,L,R,d);
    pushup(k);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("dr.in","r",stdin);
    freopen("dr.out","w",stdout);
    cin>>n>>m;
    len=(1ll<<n);
    for(int i=1;i<=len;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    tot=1;
    build(1,1,len,0);
    while(m--)
    {
        int q,l,r;
        cin>>q>>l>>r;
        int len1=(1ll<<(n-q));
        l=(l-1)*len1+1;
        r=r*len1;
        add(1,1,len,l,r,q);
        cout<<val[1]<<endl;
    }
    return 0;
}
