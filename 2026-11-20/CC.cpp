#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define lowbit(x) (x&(-x))
using namespace std;
const int N=2e5+10,P=998244353;
int n,r[N],w[N];
int tot=1,siz[N];
int head[N],d[N];
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
            t[i]+=d;
    }
    int sum(int x)
    {
        int res=0;
        for(int i=x;i;i-=lowbit(i))
            res+=t[i];
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
        if(v==fa)continue;
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
    S.push_back(x);
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        d[v]=d[x]+e[i].val;
        s[v]=r[v]-d[v];
        dfs1(v,x);
    }
}
void solve(int x,int sum)
{
    x=dfs(x,0,sum);
    S.clear();
    dfs1(x,0);  
    m=0;
    for(int v:S)b[++m]=d[v],b[++m]=s[v];
    sort(b+1,b+1+m);
    m=unique(b+1,b+1+m)-b-1;
    for(int v:S)
    {
        d[v]=lower_bound(b+1,b+1+m,d[v])-b;
        s[v]=lower_bound(b+1,b+1+m,s[v])-b;
    }
    D=S;
    sort(S.begin(),S.end(),cmps);
    sort(D.begin(),D.end(),cmpd);
    int p=0;
    for(int now:S)
    {
        while(p<D.size()&&d[D[p]]<=s[now])t.add(s[D[p]],w[D[p]]),p++;
        
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
    return 0;
}