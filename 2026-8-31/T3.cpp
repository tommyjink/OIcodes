#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=5e5+10,P=998244353;
int n,ans;
int a[N],nxt[N],pos[N],mex[N],vis[N];
int inv[N],h[N],pre[N],tag[N<<2],val[N<<2];
struct node
{
    int mn,mx,sum;
}tr[N<<2];

void pushup(int k)
{
    tr[k].mn=min(tr[k<<1].mn,tr[k<<1|1].mn);
    tr[k].mx=max(tr[k<<1].mx,tr[k<<1|1].mx);
    tr[k].sum=(tr[k<<1].sum+tr[k<<1|1].sum)%P;
}

void addtag(int k,int l,int r,int t,int v)
{
    tr[k].mn=tr[k].mx=v;
    tr[k].sum=(pre[r-t+1]-pre[l-t]+P)%P;
    tag[k]=t;
    val[k]=v;
}

void pushdown(int k,int l,int r)
{
    if(!tag[k])return;
    int mid=(l+r)>>1;
    addtag(k<<1,l,mid,tag[k],val[k]);
    addtag(k<<1|1,mid+1,r,tag[k],val[k]);
    tag[k]=0;
}

void build(int k,int l,int r)
{
    if(l==r)
    {
        tr[k].mn=tr[k].mx=mex[l];
        tr[k].sum=h[l];
        return;
    }
    int mid=(l+r)>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    pushup(k);
}

pii queryl(int k,int l,int r,int x,int v)
{
    if(r<x||tr[k].mx<=v)return {-1,-1};
    if(l==r)return {l,tr[k].mx};
    int mid=(l+r)>>1;
    pushdown(k,l,r);
    pii t=queryl(k<<1,l,mid,x,v);
    if(t.first!=-1)return t;
    return queryl(k<<1|1,mid+1,r,x,v);
}

int queryr(int k,int l,int r,int x,int v)
{
    if(r<x||tr[k].mn>v)return -1;
    if(l==r)return l;
    int mid=(l+r)>>1;
    pushdown(k,l,r);
    int t=queryr(k<<1|1,mid+1,r,x,v);
    if(t!=-1)return t;
    return queryr(k<<1,l,mid,x,v);
}

int query(int k,int l,int r,int x,int y)
{
    if(x<=l&&r<=y)return tr[k].sum;
    int mid=(l+r)>>1,res=0;
    pushdown(k,l,r);
    if(x<=mid)res=query(k<<1,l,mid,x,y);
    if(y>mid)res=(res+query(k<<1|1,mid+1,r,x,y))%P;
    return res;
}

void modify(int k,int l,int r,int x,int y,int t,int v)
{
    if(x<=l&&r<=y)
    {
        addtag(k,l,r,t,v);
        return;
    }
    int mid=(l+r)>>1;
    pushdown(k,l,r);
    if(x<=mid)modify(k<<1,l,mid,x,y,t,v);
    if(y>mid)modify(k<<1|1,mid+1,r,x,y,t,v);
    pushup(k);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=n;i>=1;i--)
    {
        nxt[i]=pos[a[i]]?pos[a[i]]:n+1;
        pos[a[i]]=i;
    }
    int now=0;
    for(int i=1;i<=n;i++)
    {
        vis[a[i]]=1;
        while(vis[now])now++;
        mex[i]=now;
    }
    inv[1]=1;
    for(int i=2;i<=n;i++)inv[i]=(P-P/i)*inv[P%i]%P;
    for(int i=1;i<=n;i++)
    {
        h[i]=(h[i-1]+inv[i])%P;
        pre[i]=(pre[i-1]+h[i])%P;
    }
    build(1,1,n);
    for(int i=1;i<=n;i++)
    {
        if(i>1)
        {
            int l=i,r;
            while(l<nxt[i-1])
            {
                pii t=queryl(1,1,n,l,a[i-1]);
                l=t.first;
                if(l==-1||l>=nxt[i-1])break;
                r=min(queryr(1,1,n,l,t.second),nxt[i-1]-1);
                int x=(pre[r-i+1]-pre[l-i]+P)%P;
                ans=(ans+(query(1,1,n,l,r)-x+P)%P*t.second)%P;
                modify(1,1,n,l,r,i,a[i-1]);
                l=r+1;
            }
        }
        if(a[i]==0)ans=(ans+query(1,1,n,i,i))%P;
    }
    cout<<ans<<endl;
    return 0;
}
