#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int maxn=1e5+5;
struct node
{
    int l,r;
    int sum;
}tr[maxn<<2];
void build(int u,int l,int r)
{
    tr[u].l=l;
    tr[u].r=r;
    if(l==r)
    {
        tr[u].sum=0;
        return;
    }
    int mid=(l+r)>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
}
int query(int k,int l,int r)
{
    if(tr[k].l==tr[k].r)
    {
        return tr[k].sum;
    }
    int mid=(tr[k].l+tr[k].r)>>1;
    if(r<=mid)
    {
        return query(k<<1,l,r);
    }
    else if(l>mid)
    {
        return query(k<<1|1,l,r);
    }
    else
    {
        return query(k<<1,l,mid)+query(k<<1|1,mid+1,r);
    }
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}