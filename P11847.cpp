#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define ls(x) t[x].l
#define rs(x) t[x].r
using namespace std;
const int N=1e6+10;
int n,q,c[N],d[N],tot=0;
int rt[N],sum[N],ans[N];
struct node
{
    int a,b;
}a[N];
struct node1
{
    int l=0,r=0,cnt=0,sum=0;
}t[N*4];
bool cmp(node x,node y)
{
    return x.a+x.b>y.a+y.b;
}
int newnode(int x)
{
    t[++tot]=t[x];
    return tot;
}
void pushup(int k)
{
    t[k].cnt=t[ls(k)].cnt+t[rs(k)].cnt;
    t[k].sum=t[ls(k)].sum+t[rs(k)].sum;
}
void add(int k,int L,int R,int x,int d)
{
    if(L>x||R<x)return;
    if(L==R)
    {
        t[k].cnt++;
        t[k].sum+=d;
        return;
    }
    int mid=(L+R)>>1;
    if(x<=mid)
    {
        ls(k)=newnode(ls(k));
        add(ls(k),L,mid,x,d);
    }
    else 
    {
        rs(k)=newnode(rs(k));
        add(rs(k),mid+1,R,x,d);
    }
    pushup(k);
}
int query(int k,int L,int R,int d)
{
    if(d==0)return 0;
    if(t[k].cnt<=d)return t[k].sum;
    if(L==R)return d*c[L];
    int mid=(L+R)>>1;
    if(t[ls(k)].cnt>=d)return query(ls(k),L,mid,d);
    else return t[ls(k)].sum+query(rs(k),mid+1,R,d-t[ls(k)].cnt);
}
int cal(int p,int k)
{
    return query(rt[p],1,n,k);
}
void solve(int l,int r,int optl,int optr)
{
    if(l>r)return;
    int mid=(l+r)>>1;
    int p=max(mid,optl),val=-1e16;
    for(int i=max(mid,optl);i<=optr;i++)
    {
        int tmp=-cal(i,mid)+sum[i+1];
        if(tmp>val)val=tmp,p=i;
    }
    ans[mid]=val;
    solve(l,mid-1,optl,p);
    solve(mid+1,r,p,optr);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i].a>>a[i].b;
    sort(a+1,a+1+n,cmp);
    for(int i=n;i>=1;i--)
        sum[i]=sum[i+1]+a[i].a;
    for(int i=1;i<=n;i++)
        c[i]=a[i].b;
    sort(c+1,c+1+n);
    for(int i=1;i<=n;i++)
        d[i]=lower_bound(c+1,c+1+n,a[i].b)-c;
    rt[0]=++tot;
    for(int i=1;i<=n;i++)
    {
        rt[i]=newnode(rt[i-1]);
        add(rt[i],1,n,d[i],a[i].b);
    }
    solve(0,n,0,n);
    while(q--)
    {
        int k;cin>>k;
        cout<<ans[k]<<endl;
    }
    return 0;
}