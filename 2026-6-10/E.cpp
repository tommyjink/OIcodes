#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,S,l[N],r[N],a[N];
int lazy[N];
struct node
{
    int sum,l,r;
}t[N*4];
void pushdown(int k)
{
    if(lazy[k])
    {
        t[k*2].sum+=lazy[k]*(t[k*2].r-t[k*2].l+1);
        t[k*2+1].sum+=lazy[k]*(t[k*2+1].r-t[k*2+1].l+1);
        lazy[k]=0;
    }
}
void pushup(int k)
{
    t[k].sum=t[k*2].sum+t[k*2+1].sum;
}
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    lazy[k]=0;
    if(l==r)
    {
        t[k].sum=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
}
void add(int k,int l,int r,int d)
{
    if(t[k].l>r||t[k].r<l)return;
    if(l<=t[k].l&&t[k].r<=r)
    {
        lazy[k]+=d;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>S;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y>>a[i];
        r[i]=S/x;
        l[i]=(S+y-1)/y;
    }
    for(int i=1;i<=n;i++)
    {

    }
    return 0;
}