#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,P=1e9+7,B=13331;
int n,m,a[N];

struct node
{
    
    int l,r,val,lazy,sum,lazy_B; 
}t[2][N*4];

int Pow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)res=res*x%P;
        y>>=1;
        x=x*x%P;
    }
    return res;
}

int qpow(int x,int y)
{
    if(y<0)return Pow(qpow(x,-y),P-2);
    else return Pow(x,y);
}

void pushup(node *t,int k)
{
    t[k].val=(t[k*2].val+t[k*2+1].val)%P;
    t[k].sum=t[k*2].sum+t[k*2+1].sum;
}

void pushdown(node *t,int k)
{
    if(t[k].lazy)
    {
        int lz = t[k].lazy;
        int lz_B = t[k].lazy_B; 

        t[k*2].val = t[k*2].val * lz_B % P;
        t[k*2].sum += lz * (t[k*2].r - t[k*2].l + 1);
        t[k*2].lazy += lz;
        t[k*2].lazy_B = t[k*2].lazy_B * lz_B % P;

        t[k*2+1].val = t[k*2+1].val * lz_B % P;
        t[k*2+1].sum += lz * (t[k*2+1].r - t[k*2+1].l + 1);
        t[k*2+1].lazy += lz;
        t[k*2+1].lazy_B = t[k*2+1].lazy_B * lz_B % P;

        t[k].lazy = 0;
        t[k].lazy_B = 1; 
    }
}

void build(node *t,int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    t[k].lazy=0;
    t[k].lazy_B=1; 
    if(l==r)
    {
        t[k].val=qpow(B,a[l]);
        t[k].sum=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(t,k*2,l,mid);
    build(t,k*2+1,mid+1,r);
    pushup(t,k);
}


void add(node *t,int k,int l,int r,int v,int B_v)
{
    if(t[k].l>r||t[k].r<l)return;
    if(l<=t[k].l&&t[k].r<=r)
    {
        t[k].lazy+=v;
        t[k].lazy_B=t[k].lazy_B*B_v%P; 
        t[k].val=t[k].val*B_v%P;       
        t[k].sum+=v*(t[k].r-t[k].l+1);
        return;
    }
    pushdown(t,k);
    add(t,k*2,l,r,v,B_v);
    add(t,k*2+1,l,r,v,B_v);
    pushup(t,k);
}

int query(node *t,int k,int l,int r)
{
    if(t[k].l>r||t[k].r<l)return 0;
    if(l<=t[k].l&&t[k].r<=r)return t[k].val;
    pushdown(t,k);
    return (query(t,k*2,l,r)+query(t,k*2+1,l,r))%P;
}

int querysum(node *t,int k,int l,int r)
{
    if(t[k].l>r||t[k].r<l)return 0;
    if(l<=t[k].l&&t[k].r<=r)return t[k].sum;
    pushdown(t,k);
    return querysum(t,k*2,l,r)+querysum(t,k*2+1,l,r);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    build(t[0],1,1,n);
    for(int i=1;i<=n;i++)a[i]=-a[i];
    build(t[1],1,1,n);
    while(m--)
    {
        int op,l,r;
        cin>>op>>l>>r;
        if(op==1)
        {
            int v;
            cin>>v;
            
            int B_v = qpow(B, v);
            int B_inv_v = qpow(B, -v); 
            add(t[0],1,l,r,v,B_v);
            add(t[1],1,l,r,-v,B_inv_v);
        }
        else
        {
            int res0=query(t[0],1,l,r);
            int res1=query(t[1],1,l,r);
            int sum=querysum(t[0],1,l,r);
            if(sum*2%(r-l+1)){cout<<"NO"<<endl;continue;}
            int d=sum*2/(r-l+1);
            res1=res1*qpow(B,d)%P;
            if(res0==res1)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}