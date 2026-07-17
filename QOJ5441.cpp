#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10;
int n,m,a[N],b[N],c[N],now=0;
struct node
{
    int l,r,cnt,s[4];
}t[N*8];
inline int f(int x){return (x%4+4)%4;}
node merge(node x,node y)
{
    node res;
    res.l=x.l,res.r=y.r;
    res.cnt=x.cnt+y.cnt;
    for(int i=0;i<4;i++)
        res.s[i]=x.s[i]+y.s[f(i-x.cnt)];
    return res;
}
void pushup(int k)
{
    t[k]=merge(t[k*2],t[k*2+1]);
}
void build(int k,int l,int r)
{
    int mid=l+(r-l)/2;
    t[k].l=l,t[k].r=r;
    if(l==r)return;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    pushup(k);
}
void ins(int k,int x)
{
    if(t[k].l>x||t[k].r<x)return;
    if(t[k].l==t[k].r)
    {
        t[k].s[f(t[k].cnt)]+=t[k].l;
        t[k].cnt++;
        return;
    }
    ins(k*2,x);
    ins(k*2+1,x);
    pushup(k);
}
void del(int k,int x)
{
    if(t[k].l>x||t[k].r<x)return;
    if(t[k].l==t[k].r)
    {
        t[k].cnt--;
        t[k].s[f(t[k].cnt)]-=t[k].l;
        return;
    }
    del(k*2,x);
    del(k*2+1,x);
    pushup(k);
}
node query(int k,int l,int r)
{
    if(t[k].l>r||t[k].r<l)return {0,0,0,{0,0,0,0}};
    if(l<=t[k].l&&t[k].r<=r)return t[k];
    return merge(query(k*2,l,r),query(k*2+1,l,r));
}
void ans()
{
    node res1=query(1,-1e5,0);
    node res2=query(1,1,1e5);
    int p=res1.cnt%2;
    cout<<now+res1.s[0]+res1.s[3]+res2.s[p]+res2.s[p+2]<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    build(1,-1e5,1e5);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        c[i]=a[i]-b[i];
        ins(1,c[i]);
        now+=b[i];
    }
    ans();
    while(m--)
    {
        int x,y,z;
        cin>>x>>y>>z;
        now-=b[x];
        del(1,c[x]);
        a[x]=y,b[x]=z,c[x]=a[x]-b[x];
        now+=b[x];
        ins(1,c[x]);
        ans();
    }
    return 0;
}