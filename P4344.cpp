#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e6+10;
int n,m,lazy[N*4],now=0;
struct node
{
    int l,r,val,left,right,middle;
}t[N*4];
int zero(int k)
{
    return t[k].r-t[k].l+1-t[k].val;
}
void pushup(int k)
{
    t[k].val=t[k*2].val+t[k*2+1].val;
    t[k].middle=max({t[k*2].middle,t[k*2+1].middle,t[k*2].right+t[k*2+1].left});
    if(t[k*2].val==0)t[k].left=t[k*2].left+t[k*2+1].left;
    else t[k].left=t[k*2].left;
    if(t[k*2+1].val==0)t[k].right=t[k*2].right+t[k*2+1].right;
    else t[k].right=t[k*2+1].right;
}
void pushdown(int k)
{
    if(lazy[k]==1)
    {
        t[k*2].val=t[k*2].r-t[k*2].l+1;
        t[k*2+1].val=t[k*2+1].r-t[k*2+1].l+1;
        lazy[k*2]=lazy[k*2+1]=1;
        t[k*2].left=t[k*2].right=t[k*2].middle=0;
        t[k*2+1].left=t[k*2+1].right=t[k*2+1].middle=0;
        lazy[k]=-1;
    }
    else if(lazy[k]==0) 
    {
        t[k*2].val=0;
        t[k*2+1].val=0;
        lazy[k*2]=lazy[k*2+1]=0;
        t[k*2].left=t[k*2].right=t[k*2].middle=t[k*2].r-t[k*2].l+1;
        t[k*2+1].left=t[k*2+1].right=t[k*2+1].middle=t[k*2+1].r-t[k*2+1].l+1;
        lazy[k]=-1;
    }
}
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    lazy[k]=-1;
    if(l==r)
    {
        t[k].val=1;
        t[k].left=t[k].right=t[k].middle=0;
        return;
    } 
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    pushup(k);
}
void update(int k,int l,int r,int d)
{ 
    if(t[k].l>r||t[k].r<l)return;
    if(l<=t[k].l&&t[k].r<=r)
    {
        if(d==1)
        {
            t[k].val=t[k].r-t[k].l+1;
            t[k].left=t[k].right=t[k].middle=0;
            lazy[k]=1;
        }
        else
        {
            t[k].val=0;
            t[k].left=t[k].right=t[k].middle=t[k].r-t[k].l+1;
            lazy[k]=0;
        }
        return;
    }
    pushdown(k);
    update(k*2,l,r,d);
    update(k*2+1,l,r,d);
    pushup(k);
}
int query(int k,int l,int r)
{
    if(t[k].l>r||t[k].r<l)return 0;
    if(l<=t[k].l&&t[k].r<=r)return t[k].val;
    pushdown(k);
    return query(k*2,l,r)+query(k*2+1,l,r);
}
int query0(int k,int l,int r)
{
    if(t[k].l>r||t[k].r<l)return 0;
    if(l<=t[k].l&&t[k].r<=r)return t[k].r-t[k].l+1-t[k].val;
    pushdown(k);
    return query0(k*2,l,r)+query0(k*2+1,l,r);
}
int query_max(int k,int l,int r)
{
    if(t[k].l>r||t[k].r<l)return 0;
    if(l<=t[k].l&&t[k].r<=r)return t[k].middle;
    pushdown(k);
    
    if(r <= t[k*2].r) return query_max(k*2, l, r);
    if(l >= t[k*2+1].l) return query_max(k*2+1, l, r);
    
    int cross = min(t[k*2].right, t[k*2].r - l + 1) + min(t[k*2+1].left, r - t[k*2+1].l + 1);
    int left_max = query_max(k*2, l, r);
    int right_max = query_max(k*2+1, l, r);
    
    return max({cross, left_max, right_max});
}
int find(int k, int l, int r, int d) 
{
    if(t[k].l>r||t[k].r<l)return -1;
    if(l<=t[k].l&&t[k].r<=r&&zero(k)==d)return t[k].r;
    pushdown(k);
    if(t[k*2].r<l)return find(k*2+1,l,r,d);
    if(query0(k*2,l,t[k*2].r)<d)return find(k*2+1,t[k*2+1].l,r,d-query0(k*2,l,t[k*2].r));
    else return find(k*2,max(l,t[k*2].l),min(r,t[k*2].r),d);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    build(1,1,n);
    while(m--)
    {
        int op;
        cin>>op;
        if(op==0)
        {
            int l,r;
            cin>>l>>r;
            update(1,l,r,0);
        }
        else if(op==1)
        {
            int l,r,ll,rr;
            cin>>ll>>rr>>l>>r;
            int sum=query(1,ll,rr);
            update(1,ll,rr,0);
            int res=find(1,l,r,min(sum,query0(1,l,r)));
            if(res!=-1&&sum>0)update(1,l,res,1);
            if(res==-1&&sum>0)cout<<"FFF"<<endl;
            // cout<<sum<<"!!"<<res<<endl;
        }
        else if(op==2)
        {
            int l,r;
            cin>>l>>r;
            cout<<query_max(1,l,r)<<endl;
        }
        // for(int i=1;i<=n;i++)
        //     cout<<query(1,i,i)<<" ";
        // cout<<endl;
    }
    return 0;
}