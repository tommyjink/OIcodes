#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,INF=1e16,P=1e9+7;
int n,m,a[N];
struct node
{
    int l,r,sum,dsum,mn,mx;
}t[N*8];
node merge(node A,node B)
{
    node C;
    C.sum=A.sum+B.sum;
    C.dsum=(A.dsum+B.dsum)%P;
    C.mn=min(A.mn,B.mn);
    C.mx=max(A.mx,B.mx);
    C.l=A.l,C.r=B.r;
    return C;
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
void pushup(int k)
{
    t[k]=merge(t[k*2],t[k*2+1]);
}
void build(int k,int l,int r)
{
    // cout<<l<<","<<r<<endl;
    t[k].l=l,t[k].r=r;
    t[k].mn=INF,t[k].mx=-INF;
    if(l==r)
    {
        t[k].sum=t[k].mn=t[k].mx=a[l];
        t[k].dsum=a[l]*a[l]%P;
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
        t[k].sum=t[k].mn=t[k].mx=a[x];
        t[k].dsum=a[x]*a[x]%P;
        return;
    }
    modify(k*2,x);
    modify(k*2+1,x);
    pushup(k);
}
node query(int k,int l,int r)
{
    if(t[k].l>r||t[k].r<l)return (node){0,0,0,0,INF,-INF};
    if(t[k].l>=l&&t[k].r<=r)return t[k];
    return merge(query(k*2,l,r),query(k*2+1,l,r));
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    build(1,1,n);
    while(m--)
    { 
        int op,x,y;
        cin>>op>>x>>y;
        if(op==1)
        {
            a[x]=y;
            modify(1,x);
        }
        else
        {
            node res=query(1,x,y);
            int len=(y-x+1),d=(res.mx-res.mn)/(len-1);
            int sum=(res.mn+res.mx)*len/2;
            int dsum=(len*res.mn%P*res.mn%P+qpow(6,P-2)*(len-1)%P*(2*len-1)%P*len%P*d%P*d%P+len*(len-1)%P*res.mn%P*d%P)%P;
            if(sum==res.sum&&dsum==res.dsum)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}