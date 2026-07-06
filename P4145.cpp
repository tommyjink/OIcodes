#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6;
int n,m,a[N],tag[N*2];
struct node
{
    int l,r,val;
}t[N*4];
void pushup(int k)
{
    t[k].val=t[k*2].val+t[k*2+1].val;
    if(tag[k*2]&&tag[k*2+1])tag[k]=1;
}
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    if(l==r)
    {
        t[k].val=a[l];
        if(t[k].val==1)tag[k]=1;
        return;
    }
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    pushup(k);
}
void change(int k,int l,int r)
{
    if(t[k].l>r||t[k].r<l)return;
    if(t[k].l==t[k].r)
    {
        t[k].val=max((int)sqrt(t[k].val),1ll);
        if(t[k].val==1)tag[k]=1;
        return;
    }
    if(l<=t[k].l&&t[k].r<=r)
    {
        if(!tag[k*2])change(k*2,t[k*2].l,t[k*2].r);
        if(!tag[k*2+1])change(k*2+1,t[k*2+1].l,t[k*2+1].r);
        pushup(k);
        return;
    }
    change(k*2,l,r);
    change(k*2+1,l,r);
    pushup(k);
}
int query(int k,int l,int r)
{
    if(t[k].r<l||t[k].l>r)return 0;
    if(l<=t[k].l&&t[k].r<=r)return t[k].val;
    return query(k*2,l,r)+query(k*2+1,l,r);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    build(1,1,n);
    cin>>m;
    while(m--)
    {
        int ch,x,y;
        cin>>ch>>x>>y;
        if(x>y)swap(x,y);
        if(ch==0)
        {
            change(1,x,y);
        }
        if(ch==1)
        {
            cout<<query(1,x,y)<<endl;
        }
    }
    return 0;
}