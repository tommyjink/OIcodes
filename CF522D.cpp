#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5e5+100,INF=1e10;
int n,m,a[N],b[N],ls[N],nxt[N],ans[N];
struct node
{
    int l,r,minval;
}t[N*8];
struct node1
{
    int l,r,id;
}q[N];
bool cmp(node1 x,node1 y)
{
    return x.r<y.r;
}
void pushup(int k)
{
    t[k].minval=min(t[k*2].minval,t[k*2+1].minval);
}
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    if(l==r)
    {
        t[k].minval=INF;
        return;
    }
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    pushup(k);
}
void change(int k,int x)
{
    if(t[k].r<x||t[k].l>x)return;
    if(t[k].l==t[k].r)
    {
        t[k].minval=nxt[x]-x;
        return;
    }
    change(k*2,x);
    change(k*2+1,x);
    pushup(k);
    return;
}
int query(int k,int l,int r)
{
    if(t[k].l>r||t[k].r<l)return INF;
    if(l<=t[k].l&&t[k].r<=r)
        return t[k].minval;
    return min(query(k*2,l,r),query(k*2+1,l,r));
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i],b[i]=a[i];
    sort(b+1,b+1+n);
    for(int i=1;i<=n;i++)   
        a[i]=lower_bound(b+1,b+1+n,a[i])-b;
    build(1,1,n);
    // while(1)
    // {
    //     int ch;
    //     cin>>ch;
    //     if(ch==1)
    //     {
    //         int x;
    //         cin>>x;
    //         change(1,x);
    //     }
    //     if(ch==2)
    //     {
    //         int x,y;
    //         cin>>x>>y;
    //         cout<<query(1,x,y)<<endl;
    //     }
    //     for(int i=1;i<=n;i++)
    //         cout<<query(1,i,i)<<" ";
    //     cout<<endl;
    // }
    for(int i=1;i<=m;i++)
        cin>>q[i].l>>q[i].r,q[i].id=i;
    sort(q+1,q+1+m,cmp);
    int now=0;
    for(int i=1;i<=m;i++)
    {
        for(;now<=q[i].r;now++)
        {
            if(ls[a[now]])
            nxt[ls[a[now]]]=now;
            change(1,ls[a[now]]);
            ls[a[now]]=now;
        }
        // cout<<q[i].l<<" "<<q[i].r<<":"<<endl;
        // for(int j=1;j<=now;j++)
        //     for(int k=j;k<=now;k++)
        //         printf("query(%lld,%lld)=%lld ",j,k,query(1,j,k));
        // cout<<endl;
        // for(int j=1;j<=now;j++)
        //     printf("%lld ",query(1,j,j));
        // cout<<endl;
        ans[q[i].id]=query(1,q[i].l,q[i].r);
        if(ans[q[i].id]>=N)ans[q[i].id]=-1;
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<endl;
    return 0;
}