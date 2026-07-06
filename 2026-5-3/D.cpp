#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,q,a[N],lazyand[N],lazymod[N];
struct node
{
    int l,r,val;
}t[N*4];
void pushup(int k)
{
    t[k].val=t[k*2].val&t[k*2+1].val;
}
void pushdown(int k)
{
    if(~lazymod[k])
    {
        t[k*2].val=t[k*2+1].val=lazymod[k];
        lazymod[k*2]=lazymod[k*2+1]=lazymod[k];
        lazyand[k*2]=lazyand[k*2+1]=0;
        lazymod[k]=-1;
    }
    if(~lazyand[k])
    {
        if(~lazymod[k*2])lazymod[k*2]&=lazyand[k];
        else lazyand[k*2]&=lazyand[k];
        if(~lazymod[k*2+1])lazymod[k*2+1]&=lazyand[k];
        else lazymod[k*2+1]&=lazyand[k];
        lazyand[k]=-1;
    }
}
void build(int k,int l,int r)
{
    lazyand[k]=lazymod[k]=-1;
    t[k].l=l,t[k].r=r;
    if(l==r)
    {
        t[k].val=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    pushup(k);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    
    return 0;
}