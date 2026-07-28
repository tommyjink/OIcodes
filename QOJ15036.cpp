#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define ls(x) t[x].l
#define rs(x) t[x].r
using namespace std;
const int N=2e6+10,P=998244353;
int n,c[N],tot,fac[N],w[N],f[N],out[N];
int head[N],tot1=0,root[N],cnt[N],ans=0,all=0;
struct node1
{
    int from,to,next;
}e[N*2];
void add(int x,int y)
{
    e[++tot1]=(node1){x,y,head[x]};
    head[x]=tot1;
}
struct node
{
    int l,r,sum,val,val2;
}t[N*4];
void pushup(int k)
{
    t[k].sum=t[ls(k)].sum+t[rs(k)].sum;
    t[k].val=(t[ls(k)].val+t[rs(k)].val)%P;
    t[k].val2=(t[ls(k)].val2+t[rs(k)].val2)%P;
}
inline int mod(int x){return (x%P+P)%P;}
void insert(int &k,int l,int r,int x)
{
    if(!k){k=++tot;t[k]={0,0,0,0,0};}
    if(l==r)
    {
        t[k].sum++;
        t[k].val=w[t[k].sum];
        t[k].val2=mod(w[cnt[l]]-w[cnt[l]-t[k].sum]);
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid)insert(ls(k),l,mid,x);
    else insert(rs(k),mid+1,r,x);
    pushup(k);
}
int merge(int l,int r,int x,int y)
{
    if(!x||!y)return x+y;
    if(l==r)
    {
        t[x].sum+=t[y].sum;
        t[x].val=w[t[x].sum];
        t[x].val2=mod(w[cnt[l]]-w[cnt[l]-t[x].sum]);
        return x;
    }
    int mid=(l+r)>>1;
    ls(x)=merge(l,mid,ls(x),ls(y));
    rs(x)=merge(mid+1,r,rs(x),rs(y));
    pushup(x);
    return x;
}
void dfs(int x,int fa)
{
    int now=0;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dfs(v,x);
        root[x]=merge(1,n,root[x],root[v]);
        ans=mod(ans-now*f[v]%P);
        now=(now+f[v])%P;
    }
    f[x]=t[root[x]].val;
    out[x]=mod(all-t[root[x]].val2);
    ans=(ans+mod(f[x]-now)*out[x]%P)%P;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>c[i],cnt[c[i]]++;
    for(int i=1;i<=n;i++)all=(all+w[cnt[i]])%P;
    for(int i=1;i<=n;i++)insert(root[i],1,n,c[i]);
    for(int i=1;i<n;i++)
    {
        int x,y;cin>>x>>y;
        add(x,y),add(y,x);
    }
    dfs(1,0);
    ans=ans*2%P;
    cout<<ans<<endl;
    for(int i=0;i<=n;i++)head[i]=root[i]=cnt[i]=0;
    tot=tot1=all=0;
    ans=0;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fac[0]=1;
    for(int i=1;i<N;i++)fac[i]=fac[i-1]*2%P,w[i]=mod(fac[i]-1);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}