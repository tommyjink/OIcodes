#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,INF=1e16;
int n,q,lazy[N],l[N],r[N],id[N],a[N];
struct node1
{
    int x,y,z;
}b[N];
bool cmp1(node1 x,node1 y)
{
    return x.z<y.z;
}
struct node
{
    int l,r,val;
}t[N*8];
void pushup(int k)
{
    t[k].val=min(t[k*2].val,t[k*2+1].val);
}
void pushdown(int k)
{
    if(~lazy[k])
    {
        lazy[k*2]=lazy[k*2+1]=lazy[k];
        t[k*2].val=t[k*2+1].val=lazy[k];
        lazy[k]=-1;
    }
}
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    lazy[k]=-1;
    if(l==r)
    {
        t[k].val=0;
        return;
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
        lazy[k]=d;
        t[k].val=d;
        return;
    }
    pushdown(k);
    modify(k*2,l,r,d);
    modify(k*2+1,l,r,d);
    pushup(k);
}
int query(int k,int l,int r)
{
    if(t[k].l>r||t[k].r<l)return INF;
    if(l<=t[k].l&&t[k].r<=r)return t[k].val;
    pushdown(k);
    return min(query(k*2,l,r),query(k*2+1,l,r));
}
int qfind(int k,int l,int r,int d)
{
    // cout<<k<<"!"<<t[k].l<<"~"<<t[k].r<<":"<<t[k].val<<endl;
    if(t[k].val>d)return -1;
    if(t[k].l>r||t[k].r<l)return -1;
    if(t[k].l==t[k].r)return t[k].l;
    int res=qfind(k*2,l,r,d);
    if(~res)return res;
    return qfind(k*2+1,l,r,d);
}
void rep()
{
    for(int i=1;i<=n;i++)cout<<"-1 ";
    cout<<endl;
    exit(0);
}
bool cmp(int x,int y)
{
    return r[x]==r[y]?x<y:r[x]<r[y];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q;
    for(int i=0;i<n;i++)
        l[i]=1,r[i]=n;
    build(1,1,n);
    // while(1)
    // {
    //     for(int i=1;i<=n;i++)
    //         cout<<query(1,i,i)<<" ";
    //     cout<<endl;
    //     int op;
    //     cin>>op;
    //     if(op==1)
    //     {
    //         int x,y,z;
    //         cin>>x>>y>>z;
    //         modify(1,x,y,z);
    //     }
    //     else
    //     {
    //         int x,y,z;
    //         cin>>x>>y>>z;
    //         cout<<qfind(1,x,y,z)<<endl;
    //     }
    // }
    for(int i=1;i<=q;i++)
        cin>>b[i].x>>b[i].y>>b[i].z;
    sort(b+1,b+1+q,cmp1);
    for(int i=1;i<=q;i++)
    {
        int x=b[i].x,y=b[i].y,z=b[i].z;
        x++,y++;
        modify(1,x,y,z);
        if(y<l[z]||x>r[z])rep();
        else l[z]=max(l[z],x),r[z]=min(r[z],y);
        // cout<<x<<"|"<<y<<"|"<<z<<".  "<<l[z]<<","<<r[z]<<endl;
    }
    // for(int i=1;i<=n;i++)
    //     cout<<query(1,i,i)<<" ";
    // cout<<endl;
    for(int i=0;i<n;i++)id[i]=i;
    sort(id,id+n,cmp);
    for(int ii=0;ii<n;ii++)
    {
        int i=id[ii],p=qfind(1,l[i],r[i],i);

        // for(int i=1;i<=n;i++)
        //     cout<<query(1,i,i)<<" ";
        // cout<<endl;
        // cout<<i<<":"<<l[i]<<","<<r[i]<<":"<<p<<endl;
        if(p==-1)rep();
        modify(1,p,p,INF);
        a[p]=i;
    }
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}