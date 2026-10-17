#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define lowbit(x) (x&(-x))
using namespace std;
const int N=2e5+10,P=998244353,INF=1e18;
int dp[N],lazy[N];
int n,a[N],len=0,id[N],st[N],ed[N];
struct BIT
{
    int t[N];
    void add(int x,int d)
    {
        for(int i=x;i<=n;i+=lowbit(i))
            t[i]=(t[i]+d)%P;
    }
    int query(int x)
    {
        int res=0;
        for(int i=x;i;i-=lowbit(i))
            res=(res+t[i])%P;
        return res;
    }
    int sum(int l,int r)
    {
        if(l<=0)return query(r);
        else return (query(r)-query(l-1)+P)%P;
    }
}t;
struct node
{
    int id,mx,dp,sum;
}b[N];
vector<node> v[N];
bool operator <(node x,node y)
{
    if(x.mx==y.mx)return x.id<y.id;
    return x.mx<y.mx;
}
void upd0(int x)
{
    for(node i:v[x])
        b[i.id]={i.id,max(i.mx,lazy[x]),i.dp,0};
    lazy[x]=0;
}
void upd1(int x)
{
    v[x].clear();
    for(int i=st[x];i<=ed[x];i++)
        v[x].push_back(b[i]);
    sort(v[x].begin(),v[x].end());
    int now=0;
    for(int i=0;i<v[x].size();i++)
        now=(now+v[x][i].dp)%P,v[x][i].sum=now;
}
int query(int l,int r,int x)
{
    if(l>r)return 0;
    int res=0;
    if(id[l]==id[r])
    {
        for(int i=l;i<=r;i++)
            if(max(b[i].mx,lazy[id[i]])>x)res=(res+b[i].dp)%P;
        return res;
    }
    for(int i=l;i<=ed[id[l]];i++)
        if(max(b[i].mx,lazy[id[i]])>x)res=(res+b[i].dp)%P;
    for(int i=st[id[r]];i<=r;i++)
        if(max(b[i].mx,lazy[id[i]])>x)res=(res+b[i].dp)%P;
    for(int i=id[l]+1;i<=id[r]-1;i++)
    {
        auto p=upper_bound(v[i].begin(),v[i].end(),(node){INF,x,0,0});
        if(lazy[i]>x)p=v[i].begin();
        if(p==v[i].end())continue;
        int tmp=v[i][v[i].size()-1].sum;
        if(p!=v[i].begin())tmp=(tmp-prev(p)->sum+P)%P;
        res=(res+tmp)%P;
    }
    return res;
}
void modify(int l,int r,int x)
{
    if(id[l]==id[r])
    {
        upd0(id[l]);
        for(int i=l;i<=r;i++)
            b[i].mx=max(b[i].mx,x);
        upd1(id[l]);
        return;
    }
    upd0(id[l]);
    upd0(id[r]);
    for(int i=l;i<=ed[id[l]];i++)
        b[i].mx=max(b[i].mx,x);
    for(int i=st[id[r]];i<=r;i++)
        b[i].mx=max(b[i].mx,x);
    upd1(id[l]);
    upd1(id[r]);
    for(int i=id[l]+1;i<=id[r]-1;i++)
        lazy[i]=max(lazy[i],x);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    len=sqrt(n);
    for(int i=1;i<=n;i++)
        cin>>a[i],id[i]=(i-1)/len+1;
    for(int i=1;i<=n;i++)
        st[id[i]]=st[id[i]]?st[id[i]]:i,
        ed[id[i]]=i;
    for(int i=1;i<=n;i++)
        v[id[i]].push_back({i,0,0,0}),
        b[i]={i,0,0,0};
    for(int i=1;i<=n;i++)
    {
        int x=a[i],u=a[i-1];
        if(i==1)dp[x]=1;
        else
        {
            dp[x]=(x<a[1]);
            if(u<x)dp[x]=(dp[x]+t.sum(u,x-1))%P;
            dp[x]=(dp[x]+query(1,min(u,x)-1,x))%P;
        }
        if(i>1&&u<=x)modify(u,x,x);
        upd0(id[x]);
        b[x].mx=0;
        b[x].dp=dp[x];
        upd1(id[x]);
        t.add(x,dp[x]);
    }
    int ans=0;
    for(int i=a[n];i<=n;i++)
        ans=(ans+dp[i])%P;
    cout<<ans<<endl;
    return 0;
}