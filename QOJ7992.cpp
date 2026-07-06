#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=2e5+10,K=20,mod=1<<20;
int n,q,a[N],lazy[N*4],c[K][K],pw[K];
struct node
{
    int f[K];
}t[N*4];

void clear(node &x)
{
    for(int i=0;i<K;i++)
        x.f[i]=0;
}

node merge(node x,node y)
{
    node res;
    clear(res);
    for(int i=0;i<K;i++)
    {
        if(!x.f[i])continue;
        for(int j=0;i+j<K;j++)
        {
            if(!y.f[j])continue;
            res.f[i+j]=(res.f[i+j]+x.f[i]*y.f[j])%mod;
        }
    }
    return res;
}

void move(node &x,int v)
{
    v%=mod;
    pw[0]=1;
    for(int i=1;i<K;i++)
        pw[i]=pw[i-1]*v%mod;
    node res;
    clear(res);
    for(int i=0;i<K;i++)
    {
        if(!x.f[i])continue;
        for(int j=0;j<=i;j++)
            res.f[j]=(res.f[j]+x.f[i]*c[i][j]%mod*pw[i-j])%mod;
    }
    x=res;
}

void addtag(int k,int v)
{
    v%=mod;
    move(t[k],v);
    lazy[k]=(lazy[k]+v)%mod;
}

void pushdown(int k)
{
    if(!lazy[k])return;
    addtag(k*2,lazy[k]);
    addtag(k*2+1,lazy[k]);
    lazy[k]=0;
}

void pushup(int k)
{
    t[k]=merge(t[k*2],t[k*2+1]);
}

void build(int k,int l,int r)
{
    lazy[k]=0;
    clear(t[k]);
    if(l==r)
    {
        t[k].f[0]=a[l]%mod;
        t[k].f[1]=1;
        return;
    }
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    pushup(k);
}

void change(int k,int l,int r,int x,int y,int v)
{
    if(x<=l&&r<=y)
    {
        addtag(k,v);
        return;
    }
    pushdown(k);
    int mid=(l+r)>>1;
    if(x<=mid)change(k*2,l,mid,x,y,v);
    if(y>mid)change(k*2+1,mid+1,r,x,y,v);
    pushup(k);
}

node query(int k,int l,int r,int x,int y)
{
    if(x<=l&&r<=y)
        return t[k];
    pushdown(k);
    int mid=(l+r)>>1;
    if(y<=mid)return query(k*2,l,mid,x,y);
    if(x>mid)return query(k*2+1,mid+1,r,x,y);
    return merge(query(k*2,l,mid,x,y),query(k*2+1,mid+1,r,x,y));
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=0;i<K;i++)
    {
        c[i][0]=c[i][i]=1;
        for(int j=1;j<i;j++)
            c[i][j]=c[i-1][j-1]+c[i-1][j];
    }
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]%=mod;
    }
    build(1,1,n);
    while(q--)
    {
        int op,l,r;
        cin>>op>>l>>r;
        if(op==1)
        {
            int x;
            cin>>x;
            change(1,1,n,l,r,x);
        }
        else
        {
            node ans=query(1,1,n,l,r);
            cout<<ans.f[0]<<endl;
        }
    }
    return 0;
}
