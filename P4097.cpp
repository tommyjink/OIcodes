#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=4e5+10,P=1e9,M=39989;
const double eps=1e-5;
int n,lst=0,num=0;
// int qpow(int x,int y)
// {
//     int res=1;
//     while(y)
//     {
//         if(y&1)res=res*x%P;
//         x=x*x%P;
//         y>>=1;
//     }
//     return res;
// }
struct Line
{
    double k,b;
    int id=0;
    double get(int x)
    {
        return k*x+b;
    }
}t[N*4];
bool cmp(Line x,Line y,int mid)
{
    double xx=x.get(mid),yy=y.get(mid);
    if(x.id==0)return false;
    if(y.id==0)return true;
    if(fabs(xx-yy)<eps)return x.id<y.id;
    return xx>yy;
}
void insert(int k,int l,int r,int L,int R,Line d)
{
    int mid=(l+r)>>1;
    if(l>R||r<L)return;
    if(L<=l&&r<=R)
    {
        if(cmp(d,t[k],mid))swap(d,t[k]);
        if(l==r)return;
        if(cmp(d,t[k],l))insert(k*2,l,mid,L,R,d);
        else if(cmp(d,t[k],r))insert(k*2+1,mid+1,r,L,R,d);
        return;
    }   
    insert(k*2,l,mid,L,R,d);
    insert(k*2+1,mid+1,r,L,R,d);
}
Line query(int k,int l,int r,int x)
{
    Line res=t[k];
    int mid=(l+r)>>1;
    if(l==r)return res;
    if(x<=mid)
    {
        Line tmp=query(k*2,l,mid,x);
        if(cmp(tmp,res,x))res=tmp;
    }
    else
    {
        Line tmp=query(k*2+1,mid+1,r,x);
        if(cmp(tmp,res,x))res=tmp;
    }
    return res;
}
void cal(int &x,int L)
{
    x=(x+lst-1)%L+1;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    while(n--)
    {
        int op;cin>>op;
        if(op==0)
        {
            int x;cin>>x;
            cal(x,M);
            Line res=query(1,1,M,x);
            lst=res.id;
            cout<<res.id<<endl;
        }
        else
        {
            int x,y,xx,yy;
            cin>>x>>y>>xx>>yy;
            cal(x,M),cal(xx,M);
            cal(y,P),cal(yy,P);
            if(x>xx)swap(x,xx),swap(y,yy);
            if(x==xx)insert(1,1,M,x,xx,{0,max(1.0*yy,1.0*y),++num});
            else
            { //y=kx+b b=y-kx;
                double k=(y*1.0-yy*1.0)/(x*1.0-xx*1.0),b=y*1.0-k*(x*1.0);
                insert(1,1,M,x,xx,{k,b,++num});
            }
        }
    }
    return 0;
}