#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10,INF=1e14;
int n,q,a[N];
struct Matrix
{
    int m[4][4];
    void init(int x)
    {
        for(int i=1;i<=3;i++)
            for(int j=1;j<=3;j++)
                m[i][j]=-INF;
        for(int i=1;i<=3;i++)
            m[i][i]=x;
    }
}v[N*4],lazy[N*4];
struct node
{
    int l,r;
}t[N*4];
Matrix operator *(const Matrix &x,const Matrix &y)
{
    Matrix res;res.init(-INF);
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
            for(int k=1;k<=3;k++)
                res.m[i][j]=max(res.m[i][j],x.m[i][k]+y.m[k][j]);
    return res;
}
Matrix operator +(const Matrix &x,const Matrix &y)
{
    Matrix res;res.init(-INF);
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
            res.m[i][j]=max(x.m[i][j],y.m[i][j]);
    return res;
}
Matrix cal(int x)
{
    Matrix res;res.init(-INF);
    res.m[1][1]=a[x];
    res.m[2][1]=a[x];
    res.m[3][1]=0;
    return res;
}
inline void pushup(int k)
{
    v[k]=v[k*2]+v[k*2+1];
}
inline void pushdown(int k)
{
    lazy[k*2]=lazy[k]*lazy[k*2];
    lazy[k*2+1]=lazy[k]*lazy[k*2+1];
    v[k*2]=lazy[k]*v[k*2];
    v[k*2+1]=lazy[k]*v[k*2+1];
    lazy[k].init(0);
}
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    lazy[k].init(0);
    if(l==r)
    {
        v[k]=cal(l);
        return;
    }
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    pushup(k);
}
void add(int k,int l,int r,const Matrix &d)
{
    if(t[k].l>r||t[k].r<l)return ;
    if(l<=t[k].l&&t[k].r<=r)
    {
        lazy[k]=d*lazy[k];
        v[k]=d*v[k];
        return;
    }
    pushdown(k);
    add(k*2,l,r,d);
    add(k*2+1,l,r,d);
    pushup(k);
}
Matrix query(int k,int l,int r)
{
    Matrix res;res.init(-INF);
    if(t[k].l>r||t[k].r<l)return res;
    if(l<=t[k].l&&t[k].r<=r)return v[k];
    pushdown(k);
    res=query(k*2,l,r)+query(k*2+1,l,r);
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    build(1,1,n);
    cin>>q;
    while(q--)
    {
        char c;cin>>c;
        if(c=='Q')
        {
            int x,y;
            cin>>x>>y;
            cout<<query(1,x,y).m[1][1]<<endl;
        }
        else if(c=='A')
        {
            int x,y;
            cin>>x>>y;
            cout<<query(1,x,y).m[2][1]<<endl;
        }
        else if(c=='P')
        {
            int x,y,z;
            cin>>x>>y>>z;
            Matrix d;d.init(-INF);
            d.m[1][1]=d.m[2][1]=z;
            d.m[2][2]=d.m[3][3]=0;
            add(1,x,y,d);
        }
        else//c=='C'
        {
            int x,y,z;
            cin>>x>>y>>z;
            Matrix d;d.init(-INF);
            d.m[1][3]=d.m[2][3]=z;
            d.m[2][2]=d.m[3][3]=0;
            add(1,x,y,d);
        }
    }
    return 0;
}