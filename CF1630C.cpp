#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],l[N],r[N],lazy[N];
struct node
{
    int l,r,val;
}t[N*4];
void pushdown(int k)
{
    if(lazy[k]==1)
    {
        lazy[k]=false;
        lazy[k*2]=lazy[k*2+1]=1;
        t[k*2].val=t[k*2].r-t[k*2].l+1;
        t[k*2+1].val=t[k*2+1].r-t[k*2+1].l+1;
    }
    else if(lazy[k]==2)
    {
        lazy[k]=false;
        lazy[k*2]=lazy[k*2+1]=2;
        t[k*2].val=t[k*2+1].val=0;
    }
}
void pushup(int k)
{
    t[k].val=t[k*2].val+t[k*2+1].val;
}
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    if(l==r)return;
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    pushup(k);
}
void add(int k,int l,int r,int d)
{
    if(t[k].r<l||t[k].l>r)return;
    if(l<=t[k].l&&t[k].r<=r)
    {
        if(d==1)t[k].val=t[k].r-t[k].l+1;
        else t[k].val=0;
        lazy[k]=d;
        return;
    }
    pushdown(k);
    add(k*2,l,r,d);
    add(k*2+1,l,r,d);
    pushup(k);
}
int query(int k,int l,int r)
{
    if(t[k].r<l||t[k].l>r)return 0;
    if(l<=t[k].l&&t[k].r<=r)return t[k].val;
    pushdown(k);
    return query(k*2,l,r)+query(k*2+1,l,r);
}
signed main()
{
    // freopen("test.in","r",stdin);
    // freopen("test1.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    memset(l,127,sizeof(l));
    memset(r,0,sizeof(r));
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        l[a[i]]=min(l[a[i]],i);
        r[a[i]]=max(r[a[i]],i);
    }
    build(1,1,n);
    for(int i=1;i<=n;i++)
    {
        int len=r[a[i]]-l[a[i]]+1;
        int sum=query(1,l[a[i]],r[a[i]]);
        if(len==2)continue;
        if(len-2>=sum)
        {
            add(1,l[a[i]],r[a[i]],2);
            add(1,l[a[i]]+1,r[a[i]]-1,1);
        }
    }
    // for(int i=1;i<=n;i++)
    //     cout<<query(1,i,i)<<" ";
    // cout<<endl;
    cout<<query(1,1,n)<<endl;
    return 0;
}

/*
1 2 3 2 1 3 3 4 5 5 5 4 7
0 0 1 1 1 1 0 0 1 1 1 0 0

10
1 7 7 1 9 1 1 3 7 9 
0 1 1 1 0 1 1 1 1 0
0 1 1 1 1 1 0 1 1 0
0 0 1 1 1 1 1 1 0 0

1 7 7 1 9 1 1 3 7 9 
0 0 1 1 1 1 1 1 0 0
*/