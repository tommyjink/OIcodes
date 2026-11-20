#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define lowbit(x) (x&(-x))
using namespace std;
const int N=2e5+10,P=998244353;
int n,r[N],w[N];
int tot=1,siz[N];
int head[N],d[N],ans[N];
int s[N],b[N*2],m=0;
vector<int> S,D;
struct node
{
    int to,next,val,ban;
}e[N*2];
struct BIT
{
    int t[N*2];
    void add(int x,int d)
    {
        for(int i=x;i<=m;i+=lowbit(i))
            t[i]=t[i]+d;
    }
    int sum(int x)
    {
        int res=0;
        for(int i=x;i;i-=lowbit(i))
            res=res+t[i];
        return res;
    }
}t;
bool cmps(int x,int y)
{
    return s[x]<s[y];
}
bool cmpd(int x,int y)
{
    return d[x]<d[y];
}
void add(int x,int y,int z)
{
    e[++tot]=(node){y,head[x],z};
    head[x]=tot;
}
int dfs(int x,int fa,int sum)
{
    siz[x]=1;
    int tag=1;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(e[i].ban||v==fa)continue;
        int res=dfs(v,x,sum);
        if(res)return res;
        siz[x]+=siz[v];
        if(siz[v]>sum/2)tag=0;
    }
    if(sum-siz[x]>sum/2)tag=0;
    return tag*x;
}
void dfs1(int x,int fa)
{
    siz[x]=1;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(e[i].ban||v==fa)continue;
        d[v]=d[x]+e[i].val;
        s[v]=r[v]-d[v];
        dfs1(v,x);
        siz[x]+=siz[v];
    }
}
void dfs2(int x,int fa)
{
    S.push_back(x);
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(e[i].ban||v==fa)continue;
        dfs2(v,x);
    }
}
void cal(int o)
{
    D=S;
    sort(S.begin(),S.end(),cmps);
    sort(D.begin(),D.end(),cmpd);
    int p=0;
    for(int now:S)
    {
        while(p<D.size()&&d[D[p]]<=s[now])t.add(s[D[p]],w[D[p]]),p++;
        ans[now]=(ans[now]+o*(t.sum(m)-t.sum(d[now]-1)))%P;
    } 
    for(int i=0;i<p;i++)
        t.add(s[D[i]],-w[D[i]]);
}
void solve(int x,int sum)
{
    x=dfs(x,0,sum);
    d[x]=0;
    s[x]=r[x];
    dfs1(x,0);  
    S.clear();
    dfs2(x,0);
    m=0;
    for(int v:S)b[++m]=d[v],b[++m]=s[v];
    sort(b+1,b+1+m);
    m=unique(b+1,b+1+m)-b-1;
    for(int v:S)
    {
        d[v]=lower_bound(b+1,b+1+m,d[v])-b;
        s[v]=lower_bound(b+1,b+1+m,s[v])-b;
    }
    cal(1);
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(e[i].ban)continue;
        S.clear();
        dfs2(v,x);
        cal(-1);
    }
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(e[i].ban)continue;
        e[i].ban=e[i^1].ban=true;
        solve(v,siz[v]);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>r[i]>>w[i];
    for(int i=1;i<=n-1;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
        add(y,x,z);
    }
    solve(1,n);
    for(int i=1;i<=n;i++)
        cout<<(ans[i]-w[i]%P+P)%P*w[i]%P<<" ";
    cout<<endl;
    return 0;
}