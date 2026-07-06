#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],q,P,mul[N*4],lazy[N*4];
struct node
{
    int l,r,val;
}t[N*4];
void pushdown(int k)
{
    if(mul[k]!=1)
    {
        t[k*2].val=t[k*2].val*mul[k]%P;
        mul[k*2]=mul[k*2]*mul[k]%P;
        t[k*2+1].val=t[k*2+1].val*mul[k]%P;
        mul[k*2+1]=mul[k*2+1]*mul[k]%P;
        lazy[k*2]=lazy[k*2]*mul[k]%P;
        lazy[k*2+1]=lazy[k*2+1]*mul[k]%P;
        mul[k]=1;
    }
    if(lazy[k])
    {
        t[k*2].val=(t[k*2].val+(t[k*2].r-t[k*2].l+1)*lazy[k]%P)%P;
        t[k*2+1].val=(t[k*2+1].val+(t[k*2+1].r-t[k*2+1].l+1)*lazy[k]%P)%P;
        lazy[k*2]=(lazy[k*2]+lazy[k])%P;
        lazy[k*2+1]=(lazy[k*2+1]+lazy[k])%P;
        lazy[k]=0;
    }
}
void pushup(int k)
{
    t[k].val=(t[k*2].val+t[k*2+1].val)%P;
}
void build(int k,int l,int r)
{
    mul[k]=1;
    t[k].l=l,t[k].r=r;
    if(l==r)
    {
        t[k].val=a[l]%P;
        return;
    }
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    pushup(k);
}
void modify_add(int k,int l,int r,int d)
{
    if(t[k].l>r||t[k].r<l)return;
    if(l<=t[k].l&&t[k].r<=r)
    {
        // pushdown(k);
        t[k].val=(t[k].val+(t[k].r-t[k].l+1)*d%P)%P;
        lazy[k]=(lazy[k]+d)%P;
        return;
    }
    pushdown(k);
    modify_add(k*2,l,r,d);
    modify_add(k*2+1,l,r,d);
    pushup(k);
}
void modify_mul(int k,int l,int r,int d)
{
    if(t[k].l>r||t[k].r<l)return ;
    if(l<=t[k].l&&t[k].r<=r)
    {
        // pushdown(k);
        t[k].val=t[k].val*d%P;
        lazy[k]=lazy[k]*d%P;
        mul[k]=mul[k]*d%P;
        return;
    }
    pushdown(k);
    modify_mul(k*2,l,r,d);
    modify_mul(k*2+1,l,r,d);
    pushup(k);
}
int query(int k,int l,int r)
{
    if(t[k].l>r||t[k].r<l)return 0;
    if(l<=t[k].l&&t[k].r<=r)return t[k].val%P;
    pushdown(k);
    return (query(k*2,l,r)+query(k*2+1,l,r))%P;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q>>P;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    build(1,1,n);
    while(q--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int x,y,z;
            cin>>x>>y>>z;
            modify_mul(1,x,y,z);
        }
        else if (op==2)
        {
            int x,y,z;
            cin>>x>>y>>z;
            modify_add(1,x,y,z);
        }
        else
        {
            int x,y;
            cin>>x>>y;
            cout<<query(1,x,y)<<endl;
        }
        // for(int i=1;i<=n;i++)
        //     cout<<query(1,i,i)<<" ";
        // cout<<endl;
    }
    return 0;
}