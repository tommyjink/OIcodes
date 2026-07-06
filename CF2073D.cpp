#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,P=998244353;
int n,q,p[N],base[N];
struct Matrix
{
    int m[5][5];
    void init(int x)
    {
        memset(m,0,sizeof(m));
        for(int i=1;i<=4;i++)
            m[i][i]=x;
    }
}v[N*4];
Matrix operator *(Matrix x,Matrix y)
{
    Matrix res;res.init(0);
    for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++)
            for(int k=1;k<=4;k++)
                res.m[i][j]=(res.m[i][j]+x.m[i][k]*y.m[k][j]%P)%P;
    return res;
}
struct node
{
    int l,r;
}t[N*4];
Matrix cal(int x)
{
    Matrix res;res.init(0);
    if(p[x]==1)
    {
        res.m[1][1]=res.m[2][3]=res.m[3][2]=res.m[4][4]=1;
        res.m[2][4]=res.m[3][4]=base[x-1];
    }
    if(p[x]==2)
    {
        res.m[1][3]=res.m[2][2]=res.m[3][1]=res.m[4][4]=1;
        res.m[1][4]=res.m[3][4]=base[x-1];
    }
    if(p[x]==3)
    {
        res.m[1][2]=res.m[2][1]=res.m[3][3]=res.m[4][4]=1;
        res.m[1][4]=res.m[2][4]=base[x-1];
    }
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
    Matrix res;res.init(1);
    if(t[k].l>r||t[k].r<l||l>r)return res;
    if(l<=t[k].l&&t[k].r<=r)return v[k];
    res=query(k*2+1,l,r)*query(k*2,l,r);
    return res;
}
int qpow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)res=res*x%P;
        x=x*x%P;
        y>>=1;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q;
    base[0]=1;
    for(int i=1;i<N;i++)
        base[i]=base[i-1]*2%P;
    for(int i=1;i<=n;i++)
        cin>>p[i];
    build(1,1,n);
    while(q--)
    {
        char c;
        int x,y;
        cin>>c>>x>>y;
        if(c=='s')
        {
            Matrix A;A.init(0);
            A.m[4][1]=1;
            Matrix res=query(1,x,y)*A;
            cout<<res.m[1][1]*qpow(base[x-1],P-2)%P<<endl;
        }
        else
        {   
            p[x]=y;
            modify(1,x);
        }
    }
    return 0;
}