#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],b[N];
struct node
{
    int l,r,minval,maxval;
}t[N*4];
void pushup(int k)
{
    t[k].minval=min(t[k*2].minval,t[k*2+1].minval);
    t[k].maxval=max(t[k*2].maxval,t[k*2+1].maxval);
}
void build(int k,int l,int r)
{ 
    t[k].l=l;
    t[k].r=r;
    if(l==r)
    {
        t[k].minval=t[k].maxval=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    pushup(k);
}
int query_min(int k,int l,int r)
{ 
    if(t[k].r<l||t[k].l>r)return 1e9;
    if(l<=t[k].l&&t[k].r<=r)return t[k].minval;
    return min(query_min(k*2,l,r),query_min(k*2+1,l,r));
}
int query_max(int k,int l,int r)
{ 
    if(t[k].r<l||t[k].l>r)return -1;
    if(l<=t[k].l&&t[k].r<=r)return t[k].maxval;
    return max(query_max(k*2,l,r),query_max(k*2+1,l,r));
}
void modify(int k,int x,int d)
{
    if(t[k].l>x||t[k].r<x)return;
    if(t[k].l==t[k].r)
    {
        t[k].minval=t[k].maxval=d;
        return;
    }
    modify(k*2,x,d);
    modify(k*2+1,x,d);
    pushup(k);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],b[a[i]]=i;
    build(1,1,n);
    int q;
    cin>>q;
    while(q--)
    { 
        int l,r;
        cin>>l>>r;
        if(l==1&&r==n)
        {
            cout<<"peace"<<endl;
            continue;
        }
        if(l==1&&r==n-1&&b[n]==n)
        {
            cout<<"peace"<<endl;
            continue;
        }
        if(l==2&&r==n&&b[n]==1)
        {
            cout<<"peace"<<endl;
            continue;
        }
        int x=query_min(1,1,l-1);
        int y=query_min(1,r+1,n);
        int z=min(x,y);
        cout<<z<<endl;
        modify(1,b[z],z+1);
        modify(1,b[z+1],z);
        swap(b[z],b[z+1]);
    }
    return 0;
}