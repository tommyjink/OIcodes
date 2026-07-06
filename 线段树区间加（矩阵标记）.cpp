#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,a[N];
struct Matrix
{
    int m[3][3];
    void init(int x)
    {
        memset(m,0,sizeof(m));
        m[1][1]=m[2][2]=x;
    }
}lazy[N*4];
struct node
{
    int l,r;
    Matrix a;
}t[N*4];
Matrix operator *(Matrix &x,Matrix &y)
{
    Matrix res;res.init(0);
    for(int i=1;i<=2;i++)
        for(int j=1;j<=2;j++)
            for(int k=1;k<=2;k++)
                res.m[i][j]+=x.m[i][k]*y.m[k][j];
    return res;
}
Matrix operator +(Matrix &x,Matrix &y)
{
    Matrix res;res.init(0);
    for(int i=1;i<=2;i++)
        for(int j=1;j<=2;j++)
            res.m[i][j]=x.m[i][j]+y.m[i][j];
    return res;      
}
void pushup(int k)
{
    t[k].a=t[k*2].a+t[k*2+1].a;
}
void pushdown(int k)
{
    t[k*2].a=lazy[k]*t[k*2].a;
    t[k*2+1].a=lazy[k]*t[k*2+1].a;
    lazy[k*2]=lazy[k]*lazy[k*2];
    lazy[k*2+1]=lazy[k]*lazy[k*2+1];
    lazy[k].init(1);
}
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    t[k].a.init(0);
    lazy[k].init(1);
    t[k].a.m[2][1]=t[k].r-t[k].l+1;
    if(l==r)
    {
        t[k].a.m[1][1]=a[l];   
        return;
    }
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    pushup(k);
}
void modify(int k,int l,int r,Matrix d)
{
    if(t[k].l>r||t[k].r<l)return ;
    if(l<=t[k].l&&t[k].r<=r)
    {
        t[k].a=d*t[k].a;
        lazy[k]=d*lazy[k];
        return;
    }
    pushdown(k);
    modify(k*2,l,r,d);
    modify(k*2+1,l,r,d);
    pushup(k);
}
int query(int k,int l,int r)
{
    if(t[k].l>r||t[k].r<l)return 0;
    if(l<=t[k].l&&t[k].r<=r)return t[k].a.m[1][1];
    pushdown(k);
    return query(k*2,l,r)+query(k*2+1,l,r);
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
        // for(int i=1;i<=n;i++)
        //     cout<<query(1,i,i)<<" ";
        // cout<<endl;
        int op;
        cin>>op;
        if(op==1)
        {
            int l,r;
            Matrix dd;dd.init(1);
            cin>>l>>r>>dd.m[1][2];
            modify(1,l,r,dd);
        }
        else if(op==2)
        {
            int l,r;
            cin>>l>>r;
            cout<<query(1,l,r)<<endl;
        }
        
    }
    return 0;
}