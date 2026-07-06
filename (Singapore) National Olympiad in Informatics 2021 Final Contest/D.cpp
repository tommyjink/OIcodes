#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=30005;
const int M=1000000007;
int n,q;
char s[4][N];
struct Mat
{
    int a[8][8];
    Mat(int f=0)
    {
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                a[i][j]=(f&&i==j);
            }
        }
    }
    Mat operator*(const Mat& o)const
    {
        Mat r;
        for(int i=0;i<8;i++)
        {
            for(int k=0;k<8;k++)
            {
                if(!a[i][k])continue;
                for(int j=0;j<8;j++)
                {
                    r.a[i][j]=(r.a[i][j]+a[i][k]*o.a[k][j])%M;
                }
            }
        }
        return r;
    }
};
Mat tr[N<<2],w[8];

int mk(int i)
{
    return (s[1][i]=='x')|((s[2][i]=='x')<<1)|((s[3][i]=='x')<<2);
}

void pushup(int p)
{
    tr[p]=tr[p<<1]*tr[p<<1|1];
}

void build(int p,int l,int r)
{
    if(l==r)
    {
        tr[p]=w[mk(l)];
        return;
    }
    int m=(l+r)>>1;
    build(p<<1,l,m);
    build(p<<1|1,m+1,r);
    pushup(p);
}

void upd(int p,int l,int r,int x)
{
    if(l==r)
    {
        tr[p]=w[mk(l)];
        return;
    }
    int m=(l+r)>>1;
    if(x<=m)upd(p<<1,l,m,x);
    else upd(p<<1|1,m+1,r,x);
    pushup(p);
}

Mat ask(int p,int l,int r,int L,int R)
{
    if(L<=l&&r<=R)return tr[p];
    int m=(l+r)>>1;
    if(R<=m)return ask(p<<1,l,m,L,R);
    if(L>m)return ask(p<<1|1,m+1,r,L,R);
    return ask(p<<1,l,m,L,R)*ask(p<<1|1,m+1,r,L,R);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int b=0;b<8;b++)
    {
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                w[b].a[i][j]=0;
                if(i&b)continue;
                if((i|b)&j)continue;
                int t=i|b|j;
                w[b].a[i][j]++;
                if(!(t&3))w[b].a[i][j]++;
                if(!(t&6))w[b].a[i][j]++;
            }
        }
    }
    cin>>n>>q;
    for(int i=1;i<=3;i++)
    {
        string t;
        cin>>t;
        for(int j=1;j<=n;j++)s[i][j]=t[j-1];
    }
    build(1,1,n);
    while(q--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int x,y;
            cin>>x>>y;
            s[x][y]^=('.'^'x');
            upd(1,1,n,y);
        }
        else
        {
            int l,r;
            cin>>l>>r;
            Mat z=ask(1,1,n,l,r);
            cout<<z.a[0][0]<<endl;
        }
    }
    return 0;
}
