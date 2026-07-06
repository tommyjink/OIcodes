#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10;
int n,m,q,lazy[N*4];
struct node
{
    int l,r,val;
}t[N*4];
void pushup(int k)
{
    t[k].val=t[k*2].val|t[k*2+1].val;
}
void pushdown(int k)
{
    if(!lazy[k])return;
    lazy[k*2]=lazy[k*2+1]=lazy[k];
    t[k*2].val=t[k*2+1].val=lazy[k];
    lazy[k]=0;
}
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    if(l==r)
    {
        t[k].val=1;
        return ;
    }
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    pushup(k);
}
void modify(int k,int l,int r,int d)
{
    if(t[k].l>r||t[k].r<l)return;
    if(l<=t[k].l&&t[k].r<=r)
    {
        lazy[k]=t[k].val=d;
        return;
    }
    pushdown(k);
    modify(k*2,l,r,d);
    modify(k*2+1,l,r,d);
    pushup(k);
}
int query(int k,int l,int r)
{
    if(t[k].l>r||t[k].r<l)return 0;
    if(l<=t[k].l&&t[k].r<=r)return t[k].val;
    pushdown(k);
    return query(k*2,l,r)|query(k*2+1,l,r);
}
signed main()
{
    // freopen("P1558_1.in","r",stdin);
    // freopen("P1558.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>q;
    build(1,1,n);
    while(q--)
    {
        char ch;
        cin>>ch;
        if(ch=='C')
        {
            int l,r,x;
            cin>>l>>r>>x;
            if(l>r)swap(l,r);
            modify(1,l,r,1ll<<(x-1));
        }
        else
        {
            int l,r;
            cin>>l>>r;
            if(l>r)swap(l,r);
            cout<<__builtin_popcount(query(1,l,r))<<endl;
        }
    }
    return 0;
}