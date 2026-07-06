#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,a[N];
struct Matrix
{
    int m[4][4];
    void init(int x)
    {
        memset(m,0,sizeof(m));
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
    Matrix res;res.init(0);
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
            for(int k=1;k<=3;k++)
                res.m[i][j]+=x.m[i][k]*y.m[k][j];
    return res;
}
Matrix operator +(const Matrix &x,const Matrix &y)
{
    Matrix res;res.init(0);
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
            res.m[i][j]=x.m[i][j]+y.m[i][j];
    return res;
}
inline Matrix cal(int x)
{
    Matrix res;res.init(0);
    res.m[1][1]=a[x];
    res.m[2][1]=a[x];
    res.m[3][1]=1;
    return res;
}
void pushup(int k)
{
    v[k]=v[k*2]+v[k*2+1];
}
void pushdown(int k)
{
    v[k*2]=lazy[k]*v[k*2];
    v[k*2+1]=lazy[k]*v[k*2+1];
    lazy[k*2]=lazy[k]*lazy[k*2];
    lazy[k*2+1]=lazy[k]*lazy[k*2+1];
    lazy[k].init(1);
}
void build(int k,int l,int r)
{
    v[k].init(0);
    lazy[k].init(1);
    t[k].l=l,t[k].r=r;
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
void add(int k,int l,int r,Matrix d)
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
    Matrix res;res.init(0);
    if(t[k].l>r||t[k].r<l)return res;
    if(l<=t[k].l&&t[k].r<=r)return v[k];
    pushdown(k);
    res=query(k*2,l,r)+query(k*2+1,l,r);
    return res;
}
void print(Matrix x)
{
    cout<<"_________________"<<endl;
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
            printf("%5lld",x.m[i][j]);
        cout<<endl;
    }
    cout<<"_________________"<<endl;
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
        int op;cin>>op;
        if(op==1)
        {
            int l,r,x;
            cin>>l>>r>>x;
            Matrix d;d.init(1);
            d.m[1][3]=x;
            add(1,l,r,d);
        }
        else
        {
            int l,r;
            cin>>l>>r;
            // print(query(1,l,r));
            cout<<query(1,l,r).m[2][1]<<endl;
        }
        Matrix d;
        d.init(1);d.m[2][1]=1;
        add(1,1,n,d);
    }
    return 0;
}