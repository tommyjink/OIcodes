#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,a[N],lazy[N*4];
struct node
{
    int l,r,sum,lm1,rm1,m1,rm0,lm0,m0;
}t[N*4];
void pushup(int k)
{ 
    t[k].sum=t[k*2].sum+t[k*2+1].sum;
    t[k].lm1=t[k*2].lm1;
    t[k].rm1=t[k*2+1].rm1;
    if(t[k*2].sum==t[k*2].r-t[k*2].l+1)
        t[k].lm1=t[k*2].sum+t[k*2+1].lm1;
    if(t[k*2+1].sum==t[k*2+1].r-t[k*2+1].l+1)
        t[k].rm1=t[k*2+1].sum+t[k*2].rm1;
    t[k].lm0=t[k*2].lm0;
    t[k].lm0=t[k*2].lm0;
    if(t[k*2].sum==0)
        t[k].lm0=t[k].r-t[k].l+1+t[k*2+1].lm0;
    if(t[k*2+1].sum==0)
        t[k].rm0=t[k*2+1].r-t[k*2+1].l+1+t[k*2].rm0;
    t[k].m1=max({t[k*2].m1,t[k*2+1].m1,t[k*2].rm1+t[k*2+1].lm1});
    t[k].m0=max({t[k*2].m0,t[k*2+1].m0,t[k*2].rm0+t[k*2+1].lm0});
}
void pushdown(int k)
{
    if(lazy[k]==0)
    {
        t[k*2].sum=t[k*2+1].sum=0;
        t[k*2].lm0=t[k*2].rm0=t[k*2].m0=t[k*2].r-t[k*2].l+1;
        t[k*2+1].lm0=t[k*2+1].rm0=t[k*2+1].m0=t[k*2+1].r-t[k*2+1].l+1;

    }
}
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    if(l==r)
    {
        if(a[l])
            t[k].sum=t[k].lm1=t[k].rm1=t[k].m1=1;
        else t[k].rm0=t[k].lm0=t[k].m0=1;
        return;
    }
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);

}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}