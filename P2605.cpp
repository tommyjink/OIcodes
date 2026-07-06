#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e4+10,INF=0x3f3f3f3f3f3f3f3f;
int n,K,d[N],c[N],s[N],w[N],st[N],ed[N],lazy[N],f[N];
vector<int> v[N];
struct node
{
    int l,r,val;
}t[N*4];
void pushup(int k)
{
    t[k].val=min(t[k*2].val,t[k*2+1].val);
}
void pushdown(int k)
{
    t[k*2].val+=lazy[k];
    t[k*2+1].val+=lazy[k];
    lazy[k*2]+=lazy[k];
    lazy[k*2+1]+=lazy[k];
    lazy[k]=0;
}
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    lazy[k]=0;
    if(l==r)
    {
        t[k].val=f[l];
        return;
    }
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    pushup(k);
}
void add(int k,int l,int r,int x)
{
    if(t[k].l>r||t[k].r<l)return;
    if(l<=t[k].l&&t[k].r<=r)
    {
        t[k].val+=x;
        lazy[k]+=x;
        return;
    }
    pushdown(k);
    add(k*2,l,r,x);
    add(k*2+1,l,r,x);
    pushup(k);
}
int query(int k,int l,int r)
{
    if(t[k].l>r||t[k].r<l)return INF;
    if(l<=t[k].l&&t[k].r<=r)return t[k].val;
    pushdown(k);
    return min(query(k*2,l,r),query(k*2+1,l,r));
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>K;
    for(int i=2;i<=n;i++)
        cin>>d[i];
    for(int i=1;i<=n;i++)
        cin>>c[i];
    for(int i=1;i<=n;i++)
        cin>>s[i];
    for(int i=1;i<=n;i++)
        cin>>w[i];
    K++,n++;
    d[n]=INF,w[n]=INF;
    for(int i=1;i<=n;i++)
    {
        st[i]=lower_bound(d+1,d+1+n,d[i]-s[i])-d;
        ed[i]=lower_bound(d+1,d+1+n,d[i]+s[i])-d;
        if(d[ed[i]]>d[i]+s[i])ed[i]--;
        v[ed[i]].push_back(i);
    }
    int now=0;
    for(int i=1;i<=n;i++)
    {
        f[i]=now+c[i];
        for(auto j:v[i])
            now+=w[j];
    }
    int ans=f[n];
    for(int i=2;i<=K;i++)
    {
        build(1,1,n);
        for(int j=1;j<=n;j++)
        {
            f[j]=query(1,1,j-1)+c[i];
            for(auto V:v[j])
                add(1,1,st[V]-1,w[V]);
        }
        ans=min(ans,f[n]);
    }
    cout<<ans<<endl;
    return 0;
}
