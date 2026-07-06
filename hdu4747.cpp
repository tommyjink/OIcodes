//https://acm.hdu.edu.cn/showproblem.php?pid=4747
#include<stdio.h>
#include<iostream>
#include<map>
#include<math.h>
#define int long long
#define endl "\n"
#define max(a,b) (a>b?a:b)
using namespace std;
const int N=1e6+10;
int n,a[N],lazy[N*4],b[N],c[N];
map<int,int>nxt,tag;
struct node
{
    int l,r,maxval,val;
}t[N*4];
void pushup(int k)
{
    t[k].maxval=max(t[k*2].maxval,t[k*2+1].maxval);
    t[k].val=t[k*2].val+t[k*2+1].val;
}
void pushdown(int k)
{
    if(lazy[k]==-1) return;
    t[k*2].maxval=t[k*2+1].maxval=lazy[k];
    t[k*2].val=lazy[k]*(t[k*2].r-t[k*2].l+1);
    t[k*2+1].val=lazy[k]*(t[k*2+1].r-t[k*2+1].l+1);
    lazy[k*2]=lazy[k*2+1]=lazy[k];
    lazy[k]=-1;
}
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    lazy[k]=-1;
    if(l==r)
    {
        t[k].maxval=t[k].val=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    pushup(k);
}
void update(int k,int l,int r,int d)
{
    if(t[k].r<l||t[k].l>r)return;
    if(l<=t[k].l&&t[k].r<=r)
    {
        t[k].maxval=d;
        t[k].val=d*(t[k].r-t[k].l+1);
        lazy[k]=d;
        return;
    }
    pushdown(k);
    update(k*2,l,r,d);
    update(k*2+1,l,r,d);
    pushup(k);
}
int find(int k,int l,int r,int d)
{
    if(t[k].r<l||t[k].l>r)return -1;
    if(t[k].maxval<=d)return -1;
    if(t[k].l==t[k].r)return t[k].l;
    int res1=find(k*2,l,r,d);
    int res2=find(k*2+1,l,r,d);
    if(res1==-1)return res2;
    else return res1;
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin>>n&&n)
    {
        nxt.clear();
        tag.clear();
        // memset(tag,0,sizeof(tag));
        // memset(a,0,sizeof(a));
        // memset(c,0,sizeof(c));
        // memset(b,0,sizeof(b));
        int p=0;
        for(int i=1;i<=n;i++)
        {
            cin>>b[i];
            nxt[b[i]]=n+1;
            tag[b[i]]=true;
            while(tag[p])p++;
            a[i]=p;
        }
        for(int i=n;i>=1;i--)
        {
            c[i]=nxt[b[i]];
            nxt[b[i]]=i;
        }
        build(1,1,n);
        int ans=query(1,1,n);
        // for(int i=1;i<=n;i++)
        //     cout<<a[i]<<" ";
        // cout<<endl;
        // for(int i=1;i<=n;i++)
        //     cout<<c[i]<<" ";
        // cout<<endl;
        for(int i=2;i<=n;i++)
        { 
            // for(int j=1;j<=n;j++)
            //     cout<<query(1,j,j)<<" ";
            // cout<<endl;
            int pos=find(1,i-1,n,b[i-1]);
            // cout<<pos<<endl;
            if(pos!=-1&&pos<=c[i-1]-1)update(1,pos,c[i-1]-1,b[i-1]);
            ans+=query(1,i,n);
        }
        cout<<ans<<endl;
    }
    return 0;
}