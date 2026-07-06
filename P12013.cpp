#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+100,INF=1e18;
int n,m,a[N],lazy2[N*4],lazy3[N*4];
struct node
{
    int l,r,val2,val3;
}t[N*4];

int gcd(int x,int y)
{
    return y==0?x:gcd(y,x%y);
}

void pushup(int k)
{
    t[k].val2=max(t[k*2].val2,t[k*2+1].val2);
    t[k].val3=max(t[k*2].val3,t[k*2+1].val3);
}

void pushdown(int k)
{
    if(lazy2[k])
    {
        lazy2[k*2]+=lazy2[k];
        lazy2[k*2+1]+=lazy2[k];
        t[k*2].val2+=lazy2[k];
        t[k*2+1].val2+=lazy2[k];
        lazy2[k]=0;
    }
    if(lazy3[k])
    {
        lazy3[k*2]+=lazy3[k];
        lazy3[k*2+1]+=lazy3[k];
        t[k*2].val3+=lazy3[k];
        t[k*2+1].val3+=lazy3[k];
        lazy3[k]=0;
    }
}

void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    lazy2[k]=lazy3[k]=0;
    if(l==r)
    {
        
        t[k].val2=(l+1<=n)?(a[l]+a[l+1]):-INF;
        
        t[k].val3=(l+2<=n)?(a[l]+a[l+1]+a[l+2]):-INF;
        return;
    }
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    pushup(k);
}

void add2(int k,int l,int r,int d)
{
    if(t[k].l>r||t[k].r<l||l>r)return;
    if(l<=t[k].l&&t[k].r<=r)
    {
        t[k].val2+=d;
        lazy2[k]+=d;
        return;
    }
    pushdown(k);
    add2(k*2,l,r,d);
    add2(k*2+1,l,r,d);
    pushup(k);
}

void add3(int k,int l,int r,int d)
{
    if(t[k].l>r||t[k].r<l||l>r)return;
    if(l<=t[k].l&&t[k].r<=r)
    {
        t[k].val3+=d;
        lazy3[k]+=d;
        return;
    }
    pushdown(k);
    add3(k*2,l,r,d);
    add3(k*2+1,l,r,d);
    pushup(k);
}

int query2(int k,int l,int r)
{
    if(l>r||r>n-1||l<1)return -INF;  
    if(t[k].l>r||t[k].r<l)return -INF;
    if(l<=t[k].l&&t[k].r<=r)return t[k].val2;
    pushdown(k);
    return max(query2(k*2,l,r),query2(k*2+1,l,r));
}

int query3(int k,int l,int r)
{
    if(l>r||r>n-2||l<1)return -INF;  
    if(t[k].l>r||t[k].r<l)return -INF;
    if(l<=t[k].l&&t[k].r<=r)return t[k].val3;
    pushdown(k);
    return max(query3(k*2,l,r),query3(k*2+1,l,r));
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
        int op,l,r;
        cin>>op>>l>>r;
        if(op==1)
        {
            int x;cin>>x;
            
            if(l==r)
            {
                add2(1,l-1,r,x);
                add3(1,l-2,r,x);
                continue;
            }
            if(l>1) add2(1,l-1,l-1,x);  
            if(l<r) add2(1,l,r-1,2*x);  
            if(r<n) add2(1,r,r,x);      
            
            
            if(l>2) add3(1,l-2,l-2,x);      
            if(l>1&&l<n) add3(1,l-1,l-1,2*x); 
            if(l<r-1) add3(1,l,r-2,3*x);    
            if(r>1&&r<n) add3(1,r-1,r-1,2*x); 
            if(r<n-1) add3(1,r,r,x);        
        }
        else
        {
            int res2=query2(1,l,r-1);
            int res3=query3(1,l,r-2);
            
            
            if(res3==-INF||res2*3>res3*2)
            {
                int g=gcd(abs(res2),2);
                int num=res2/g;
                int den=2/g;
                if(den<0) {num*=-1; den*=-1;}
                cout<<num<<"/"<<den<<endl;
            }
            else
            {
                int g=gcd(abs(res3),3);
                int num=res3/g;
                int den=3/g;
                if(den<0) {num*=-1; den*=-1;}
                cout<<num<<"/"<<den<<endl;
            }
        }
    }
    return 0;
}