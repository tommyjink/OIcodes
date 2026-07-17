#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,INF=1e15;
int n,q,lazyb[N*8],lazyc[N*8];
struct node
{
    int l,r,maxb,minb,maxc,minc,maxa;
}t[N*8];
void pushup(int k)
{
    t[k].maxb=max(t[k*2].maxb,t[k*2+1].maxb);
    t[k].maxa=max(t[k*2].maxa,t[k*2+1].maxa);
    t[k].maxc=max(t[k*2].maxc,t[k*2+1].maxc);
    t[k].minb=min(t[k*2].minb,t[k*2+1].minb);
    t[k].minc=min(t[k*2].minc,t[k*2+1].minc);
}
void pushb(int k,int x)
{
    lazyc[k]=INF;
    lazyb[k]=x;
    t[k].maxb=t[k].minb=x;
    t[k].maxc=x-2*t[k].l;
    t[k].minc=x-2*t[k].r;
    t[k].maxa=x-t[k].l;
}
void pushc(int k,int x)
{
    lazyb[k]=INF;
    lazyc[k]=x;
    t[k].maxc=t[k].minc=x;
    t[k].maxb=x+2*t[k].r;
    t[k].minb=x+2*t[k].l;
    t[k].maxa=x+t[k].r;
}
void pushdown(int k)
{
    if(lazyb[k]!=INF)
    {
        pushb(k*2,lazyb[k]);
        pushb(k*2+1,lazyb[k]);
        lazyb[k]=INF;
    }
    if(lazyc[k]!=INF)
    {
        pushc(k*2,lazyc[k]);
        pushc(k*2+1,lazyc[k]);
        lazyc[k]=INF;
    }
}
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    t[k].maxb=t[k].maxc=t[k].maxa=INF;
    t[k].minb=t[k].minc=INF;
    lazyb[k]=lazyc[k]=INF;
    if(l==r)return;
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    pushup(k);
}
void modifyb(int k,int l,int r,int x)
{
    if(t[k].l>r||t[k].r<l)return;
    if(l<=t[k].l&&t[k].r<=r)
    {
        if(t[k].maxb<=x)return;
        if(t[k].minb>=x){pushb(k,x);return;}
    }
    pushdown(k);
    modifyb(k*2,l,r,x);
    modifyb(k*2+1,l,r,x);
    pushup(k);
}
void modifyc(int k,int l,int r,int x)
{
    if(t[k].l>r||t[k].r<l)return;
    if(l<=t[k].l&&t[k].r<=r)
    {
        if(t[k].maxc<=-x)return;
        if(t[k].minc>=-x){pushc(k,-x);return;}
    }
    pushdown(k);
    modifyc(k*2,l,r,x);
    modifyc(k*2+1,l,r,x);
    pushup(k);
}
int query(int k,int l,int r)
{
    if(t[k].l>r||t[k].r<l)return -INF;
    if(l<=t[k].l&&t[k].r<=r)return t[k].maxa;
    pushdown(k);
    return max(query(k*2,l,r),query(k*2+1,l,r));
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q;
    build(1,1,n);
    while(q--)
    {
        int op,x,y;
        cin>>op>>x>>y;
        if(op==1)
        {
            if(x==0)modifyb(1,1,y,y);
            else modifyc(1,y,n,y);
        }
        else
        {
            int res=query(1,x,y);
            cout<<(res>INF/2?-1:res)<<endl;
        }
    }
    return 0;
}