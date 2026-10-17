#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,P=1e9+7;
int n,m,a[N],fac[N],inv[N];
struct node
{
    int sum,val,lazy;
}t[N<<2];

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
    t[k].sum=t[k<<1].sum+t[k<<1|1].sum;
    t[k].val=t[k<<1].val+t[k<<1|1].val;
}

void addtag(int k,int l,int r,int v)
{
    t[k].sum+=(r-l+1)*v;
    if((r-l+1)&1)t[k].val+=(l&1?-v:v);
    t[k].lazy+=v;
}

void pushdown(int k,int l,int r)
{
    if(!t[k].lazy)return;
    int mid=(l+r)>>1;
    addtag(k<<1,l,mid,t[k].lazy);
    addtag(k<<1|1,mid+1,r,t[k].lazy);
    t[k].lazy=0;
}

void build(int k,int l,int r)
{
    if(l==r)
    {
        t[k].sum=a[l];
        t[k].val=(l&1)?-a[l]:a[l];
        return; 
    }
    int mid=(l+r)>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    pushup(k);
}

void modify(int k,int l,int r,int x,int y,int v)
{
    if(x<=l&&r<=y)
    {
        addtag(k,l,r,v);
        return;
    }
    int mid=(l+r)>>1;
    pushdown(k,l,r);
    if(x<=mid)modify(k<<1,l,mid,x,y,v);
    if(y>mid)modify(k<<1|1,mid+1,r,x,y,v);
    pushup(k);
}

node query(int k,int l,int r,int x,int y)
{
    if(x<=l&&r<=y)return t[k];
    int mid=(l+r)>>1;
    pushdown(k,l,r);
    if(y<=mid)return query(k<<1,l,mid,x,y);
    if(x>mid)return query(k<<1|1,mid+1,r,x,y);
    node p=query(k<<1,l,mid,x,y);
    node q=query(k<<1|1,mid+1,r,x,y);
    return (node){p.sum+q.sum,p.val+q.val,0};
}
inline int C(int x,int y)
{
    return fac[x]*inv[y]%P*inv[x-y]%P;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    n*=2;
    for(int i=1;i<=n;i++)cin>>a[i];
    fac[0]=1;
    for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%P;
    inv[n]=qpow(fac[n],P-2);
    for(int i=n-1;i>=0;i--)inv[i]=inv[i+1]*(i+1)%P;
    build(1,1,n);
    while(m--)
    {
        int op,l,r;
        cin>>op>>l>>r;
        if(!op)
        {
            int x;
            cin>>x;
            modify(1,1,n,l,r,x);
        }
        else
        {
            int mid=(l+r)>>1;
            node x=query(1,1,n,l,mid);
            node y=query(1,1,n,mid+1,r);
            int k=(r-l+1)/2;
            int mx=y.sum-x.sum;
            int mn=x.val+y.val;
            if(!(l&1))mn=-mn;
            // int cnt=fac[k*2]*inv[k]%P*inv[k+1]%P;
            int cnt=C(2*k,k)*qpow(k+1,P-2)%P;
            cout<<mx<<" "<<mn<<" "<<cnt<<endl;
        }
    }   
    return 0;
}
