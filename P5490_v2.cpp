#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10;
int n,X[N*2];
int x[N],y[N],xx[N],yy[N];
struct node
{
    int y,x,xx,op;
}q[N*2];
struct Tree
{
    int l,r,w,v;
}t[N*16];
bool cmp(node x,node y)
{
    return x.y<y.y;
}
inline void cal(int &x,int *a)
{
    x=lower_bound(a+1,a+1+2*n,x)-a;
}
void pushup(int k)
{
    if(t[k].v)t[k].w=X[t[k].r+1]-X[t[k].l];
    else t[k].w=t[k*2].w+t[k*2+1].w;
}
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    if(l==r)return;
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    pushup(k);
}
void add(int k,int l,int r,int d)
{
    if(t[k].l>r||t[k].r<l)return;
    if(l<=t[k].l&&t[k].r<=r)
    {
        // cout<<k<<"___"<<t[k].v<<"__"<<t[k].l<<","<<t[k].r<<endl;
        t[k].v+=d;
        pushup(k);
        // cout<<t[k].w<<endl;
        return;
    }
    add(k*2,l,r,d);
    add(k*2+1,l,r,d);
    pushup(k);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i]>>y[i]>>xx[i]>>yy[i];
        X[i]=x[i],X[i+n]=xx[i];
    }
    sort(X+1,X+1+2*n);
    for(int i=1;i<=n;i++)
    {
        cal(x[i],X),cal(xx[i],X);
        q[i]=(node){y[i],x[i],xx[i],1};
        q[i+n]=(node){yy[i],x[i],xx[i],-1};
    }
    sort(q+1,q+1+2*n,cmp);
    build(1,1,2*n);
    int ans=0;
    for(int i=1;i<2*n;i++)
    {
        add(1,q[i].x,q[i].xx-1,q[i].op);
        // cout<<q[i].y<<":"<<X[q[i].x]<<","<<X[q[i].xx]<<","<<q[i].op<<" "<<t[1].w<<endl;
        ans+=t[1].w*(q[i+1].y-q[i].y);
    }
    cout<<ans<<endl;
    return 0;
}