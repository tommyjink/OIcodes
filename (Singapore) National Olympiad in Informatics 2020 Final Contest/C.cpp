#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,q;
const int N=3e5+10,INF=1e16;
int lazyadd[N*4],lazymod[N*4],a[N];
struct node
{
    int l,r,sum;
    int lnum,lmx,rnum,rmx,mx;
}t[N*4];
node merge(node x,node y)
{
    node res;
    res.l=x.l,res.r=y.r;
    res.sum=x.sum+y.sum;
    res.mx=max(x.mx,y.mx);
    if(x.rnum==y.lnum)
        res.mx=max(res.mx,x.rmx+y.lmx);
    res.lnum=x.lnum;
    res.rnum=y.rnum;
    if(x.lmx==(x.r-x.l+1)&&y.lnum==x.lnum)
        res.lmx=x.lmx+y.lmx;
    else res.lmx=x.lmx;
    if(y.rmx==(y.r-y.l+1)&&y.rnum==x.rnum)
        res.rmx=y.rmx+x.rmx;
    else res.rmx=y.rmx;
    return res;
}
void pushup(int k)
{
    t[k]=merge(t[k*2],t[k*2+1]);
}
void pushdown(int k)
{
    if(lazyadd[k])
    {
        if(lazymod[k*2]==INF)lazyadd[k*2]+=lazyadd[k];
        else lazymod[k*2]+=lazyadd[k];
        t[k*2].lnum+=lazyadd[k];
        t[k*2].rnum+=lazyadd[k];
        t[k*2].sum+=lazyadd[k]*(t[k*2].r-t[k*2].l+1);
        if(lazymod[k*2+1]==INF)lazyadd[k*2+1]+=lazyadd[k];
        else lazymod[k*2+1]+=lazyadd[k];
        t[k*2+1].lnum+=lazyadd[k];
        t[k*2+1].rnum+=lazyadd[k];
        t[k*2+1].sum+=lazyadd[k]*(t[k*2+1].r-t[k*2+1].l+1);
        lazyadd[k]=0;
    }
    if(lazymod[k]!=INF)
    {
        lazymod[k*2]=lazymod[k*2+1]=lazymod[k];
        lazyadd[k*2]=lazyadd[k*2+1]=0;
        t[k*2].lnum=t[k*2].rnum=lazymod[k];
        t[k*2].lmx=t[k*2].rmx=t[k*2].mx=t[k*2].r-t[k*2].l+1;
        t[k*2].sum=lazymod[k]*(t[k*2].r-t[k*2].l+1);
        t[k*2+1].lnum=t[k*2+1].rnum=lazymod[k];
        t[k*2+1].lmx=t[k*2+1].rmx=t[k*2+1].mx=t[k*2+1].r-t[k*2+1].l+1;
        t[k*2+1].sum=lazymod[k]*(t[k*2+1].r-t[k*2+1].l+1);
        lazymod[k]=INF;
    }
}
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    lazyadd[k]=0;
    lazymod[k]=INF;
    if(l==r)
    {
        t[k].lnum=t[k].rnum=a[l];
        t[k].lmx=t[k].rmx=t[k].mx=1;
        t[k].sum=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    pushup(k);
}
node query(int k,int l,int r)
{
    // cout<<k<<","<<l<<","<<r<<","<<t[k].l<<","<<t[k].r<<endl;
    if(l<=t[k].l&&t[k].r<=r)return t[k];
    pushdown(k);
    int mid=(t[k].l+t[k].r)>>1;
    if(r<=mid)return query(k*2,l,r);
    if(l>=mid+1)return query(k*2+1,l,r);
    return merge(query(k*2,l,r),query(k*2+1,l,r));
}
void modify(int k,int l,int r,int d)
{
    if(t[k].l>r||t[k].r<l)return ;
    if(l<=t[k].l&&t[k].r<=r)
    {
        t[k].lnum=t[k].rnum=d;
        lazyadd[k]=0,lazymod[k]=d;
        t[k].mx=t[k].lmx=t[k].rmx=t[k].r-t[k].l+1;
        t[k].sum=d*(t[k].r-t[k].l+1);
        return;
    }
    pushdown(k);
    modify(k*2,l,r,d);
    modify(k*2+1,l,r,d);
    pushup(k);
}
void add(int k,int l,int r,int d)
{
    if(t[k].l>r||t[k].r<l)return ;
    if(l<=t[k].l&&t[k].r<=r)
    {
        if(lazymod[k]!=INF)lazymod[k]+=d;
        else lazyadd[k]+=d;
        t[k].lnum+=d;
        t[k].rnum+=d;
        t[k].sum+=d*(t[k].r-t[k].l+1);
        return;
    }
    pushdown(k);
    add(k*2,l,r,d);
    add(k*2+1,l,r,d);
    pushup(k);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cin>>n;
    // for(int i=1;i<=n;i++)cin>>a[i];
    // build(1,1,n);
    // while(1)
    // {
    //     for(int i=1;i<=n;i++)
    //         cout<<query(1,i,i).sum<<" ";
    //     cout<<endl;
    //     int op;cin>>op;
    //     if(op==1)
    //     {
    //         int l,r;
    //         cin>>l>>r;
    //         node res=query(1,l,r);
    //         printf("lmx:%lld,lnum:%lld,rmx:%lld,rnum:%lld,mx:%lld,sum:%lld\n",res.lmx,res.lnum,res.rmx,res.rnum,res.mx,res.sum);
    //     }
    //     else if(op==2)
    //     {
    //         int l,r,d;
    //         cin>>l>>r>>d;
    //         modify(1,l,r,d);
    //     }
    //     else
    //     {
    //         int l,r,d;
    //         cin>>l>>r>>d;
    //         add(1,l,r,d);
    //     }
    // }
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=n-1;i>=1;i--)a[i+1]=a[i+1]-a[i];
    build(1,1,n);
    while(q--)
    {
            // for(int i=1;i<=n;i++)
            //     cout<<query(1,i,i).sum<<" ";
            // cout<<endl;
        int op;
        cin>>op;
        if(op==1)
        {
            int l,r,s,c;
            cin>>l>>r>>s>>c;
            add(1,l,l,s);
            if(r+1<=n)add(1,r+1,r+1,-s-(r-l)*c);
            l++;
            if(l<=r)add(1,l,r,c);
        }
        else if(op==2)
        {
            int l,r,s,c;
            cin>>l>>r>>s>>c;
            int tmp1=query(1,l,r).sum;
            modify(1,l,r,0);
            modify(1,l,l,-query(1,1,l).sum+s);
            if(l+1<=r)modify(1,l+1,r,c);
            int tmp2=query(1,l,r).sum;
            if(r+1<=n)add(1,r+1,r+1,tmp1-tmp2);
        }
        else
        {
            int l,r;
            cin>>l>>r;
            if(l==r)cout<<1<<endl;
            else cout<<query(1,l+1,r).mx+1<<endl;
        }
    }
    return 0;
}