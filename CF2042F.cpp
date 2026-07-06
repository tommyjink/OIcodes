#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int INF=1e15,N=2e5+10;
int n,q,a[N],b[N];
struct Matrix
{
    int m[6][6];
    void init(int x)
    {
        for(int i=1;i<=5;i++)
            for(int j=1;j<=5;j++)
                m[i][j]=-INF;
        for(int i=1;i<=5;i++)
            m[i][i]=x;
    }
}v[N*4];
Matrix operator *(const Matrix &x,const Matrix &y)
{
    Matrix res;res.init(-INF);
    for(int i=1;i<=5;i++)
        for(int j=1;j<=5;j++)
            for(int k=1;k<=5;k++)
                res.m[i][j]=max(res.m[i][j],x.m[i][k]+y.m[k][j]);
    return res;
}
struct node
{
    int l,r;
}t[N*4];
Matrix cal(int x)
{
    Matrix res;res.init(-INF);
    res.m[1][1]=a[x];
    res.m[1][5]=a[x]+b[x];
    res.m[2][1]=a[x]+b[x];
    res.m[2][2]=0;
    res.m[2][5]=a[x]+2*b[x];
    res.m[3][2]=a[x]+b[x];
    res.m[3][3]=a[x];
    res.m[4][2]=a[x]+2*b[x];
    res.m[4][3]=a[x]+b[x];
    res.m[4][4]=0;
    res.m[5][5]=0;
    return res;
}
inline void pushup(int k)
{
    v[k]=v[k*2+1]*v[k*2];
}
void build(int k,int l,int r)
{
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
void modify(int k,int x)
{
    if(t[k].l>x||t[k].r<x)return;
    if(t[k].l==t[k].r)
    {
        v[k]=cal(t[k].l);
        return;
    }
    modify(k*2,x);
    modify(k*2+1,x);
    pushup(k);
}
Matrix query(int k,int l,int r)
{
    Matrix res;res.init(0);
    if(t[k].l>r||t[k].r<l)return res;
    if(l<=t[k].l&&t[k].r<=r)return v[k];
    res=query(k*2+1,l,r)*query(k*2,l,r);
    return res;
}
void print(Matrix x)
{
    cout<<"______________________________"<<endl;

    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=5;j++)
        {
            if(x.m[i][j]<-1000)cout<<" -INF";
            else printf("%5lld",x.m[i][j]);
        }
        cout<<endl;
    }

    cout<<"______________________________"<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    cin>>q;
    build(1,1,n);
    // print(cal(1));
    // Matrix A;A.init(-INF);
    // A.m[5][1]=0;
    // print(A);
    // print(cal(1)*A);
    while(q--)
    {
        int op,x,y;
        cin>>op>>x>>y;
        if(op==1)
        {
            a[x]=y;
            modify(1,x);
        }
        else if(op==2)
        {
            b[x]=y;
            modify(1,x);
        }   
        else
        {
            Matrix A;A.init(-INF);
            A.m[5][1]=0;
            Matrix res=query(1,x,y)*A;
            // print(query(1,x,y));
            // print(res);
            cout<<res.m[4][1]<<endl;
        }
    }
    return 0;
}