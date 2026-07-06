#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,INF=1e15;
int n,m,a[N],tag[N*4];
struct Matrix 
{
    int m[5][5];
    void init(int x)
    {
        for(int i=1;i<=4;i++)
            for(int j=1;j<=4;j++)
                m[i][j]=-INF;
        for(int i=1;i<=4;i++)
            m[i][i]=x;
    }
}v[N*4],lazy[N*4];
Matrix operator *(Matrix a,Matrix b)
{
    Matrix res;res.init(-INF);
    for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++)
            for(int k=1;k<=4;k++)
                res.m[i][j]=max(res.m[i][j],a.m[i][k]+b.m[k][j]);
    return res; 
}
Matrix operator +(Matrix a,Matrix b)
{
    Matrix res;res.init(-INF);
    for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++)
            res.m[i][j]=max(res.m[i][j],a.m[i][j]+b.m[i][j]);
    return res; 
}
struct node
{
    int l,r;
    int mx,cmx,cnt,val;
}t[N*4];
void pushup(int k)
{
    if(t[k*2].mx>t[k*2+1].mx) 
    {
        t[k].mx=t[k*2].mx;
        t[k].cmx=max(t[k*2].cmx,t[k*2+1].mx);
        t[k].cnt=t[k*2].cnt;
    }
    else if(t[k*2].mx<t[k*2+1].mx)
    {
        t[k].mx=t[k*2+1].mx;
        t[k].cmx=max(t[k*2+1].cmx,t[k*2].mx);
        t[k].cnt=t[k*2+1].cnt;
    }
    else
    {
        t[k].mx=t[k*2].mx;
        t[k].cmx=max(t[k*2].cmx,t[k*2+1].cmx);
        t[k].cnt=t[k*2].cnt+t[k*2+1].cnt; 
    }
    v[k]=v[k*2]+v[k*2+1];
    t[k].val=t[k*2].val+t[k*2+1].val;
}
void pushdown(int k)
{
    lazy[k*2]=lazy[k]*lazy[k*2];
    lazy[k*2+1]=lazy[k]*lazy[k*2+1];
    v[k*2]=v[k*2]*lazy[k];
    v[k*2+1]=v[k*2+1]*lazy[k];
    lazy[k].init(1);
    t[k*2].val+=tag[k]*(t[k*2].r-t[k*2].l+1);
    t[k*2+1].val+=tag[k]*(t[k*2+1].r-t[k*2+1].l+1);
    t[k*2].cmx+=tag[k];
    t[k*2+1].cmx+=tag[k];
    t[k*2].mx+=tag[k];
    t[k*2+1].mx+=tag[k];
    tag[k*2]+=tag[k];
    tag[k*2+1]+=tag[k];
    tag[k]=0;
}
void upd(int k,int x)
{
    if(x>t[k].mx)return;
    t[k].val-=t[k].cnt*(t[k].mx-x);
    t[k].mx=x;
}
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    if(l==r)
    {
        t[k].cmx=-INF;
        t[k].mx=a[l];
        t[k].cnt=1;
        v[k].init(0);
        v[k].m[1][1]=v[k].m[2][1]=a[l];
        t[k].val=a[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    pushup(k);
}
void add(int k,int l,int r,Matrix d,int x)
{
    if(t[k].r<l||t[k].l>r)return;
    if(t[k].l>=l&&t[k].r<=r)
    {
        lazy[k]=d*lazy[k];
        v[k]=d*v[k];
        tag[k]+=x;
        t[k].val+=x*(t[k].r-t[k].l+1);
        return ;
    }
    pushdown(k);
    add(k*2,l,r,d,x);
    add(k*2+1,l,r,d,x);
    pushup(k);
}
void modify(int k,int l,int r,Matrix d,int x)
{
    if(t[k].r<l||t[k].l>r||x>=t[k].mx)return;
    if(t[k].l>=l&&t[k].r<=r&&x>t[k].cmx)
    { 
        upd(k,x);
        v[k]=d*v[k];
        return ;
    }
    pushdown(k);
    modify(k*2,l,r,d,x);
    modify(k*2+1,l,r,d,x);
    pushup(k);
}
int query_sum(int k,int l,int r)
{
    if(t[k].r<l||t[k].l>r)return 0;
    if(t[k].l>=l&&t[k].r<=r)return t[k].val;
    pushdown(k);
    return query_sum(k*2,l,r)+query_sum(k*2+1,l,r);
}
Matrix query(int k,int l,int r)
{
    Matrix res;res.init(-INF);
    if(t[k].r<l||t[k].l>r)return res;
    if(t[k].l>=l&&t[k].r<=r)return v[k];
    pushdown(k);
    res=query(k*2,l,r)+query(k*2+1,l,r);
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    build(1,1,n);
    while(m--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int l,r,x;
            cin>>l>>r>>x;
            Matrix d;d.init(-INF);
            d.m[1][1]=d.m[2][1]=x;
            d.m[2][2]=d.m[3][3]=0;
            add(1,l,r,d,x);
        } 
        else if(op==2)
        {
            int l,r,x;
            cin>>l>>r>>x;
            Matrix d;d.init(-INF);
            d.m[1][3]=d.m[2][3]=x;
            d.m[2][2]=d.m[3][3]=0;
            modify(1,l,r,d,x);
        }
        else if(op==3)
        {
            int l,r;
            cin>>l>>r;
            cout<<query_sum(1,l,r)<<endl;
        }
        else if(op==4)
        {
            int l,r;
            cin>>l>>r;  
            cout<<query(1,l,r).m[1][1]<<endl;
        }
        else
        {
            int l,r;
            cin>>l>>r;
            cout<<query(1,l,r).m[2][1]<<endl;
        }
    }
    return 0;
}