#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,X,t[N],c[N],w[N],fa[N],ans=0,now=0,ver[N];
vector<int> g[N];
struct DSU
{
    int fa[N];
    void init(){for(int i=1;i<=n;i++)fa[i]=i;}
    int get(int x){return x==fa[x]?x:fa[x]=get(fa[x]);}
    void merge(int x,int y){if(get(x)!=get(y))fa[get(x)]=get(y);}
}D;
void dfs(int x)
{
    for(auto v:g[x])
    {
        if(v==fa[x])continue;
        fa[v]=x;
        dfs(v);
    }
}
struct node
{
    int c,w,id,ver;
};
bool operator <(node x,node y)
{
    if(x.w==0||y.w==0)
    {
        if(x.w==0&&y.w==0)return x.id<y.id;
        return x.w!=0;
    }
    if(x.c*y.w==x.w*y.c)return x.id<y.id;
    return x.c*y.w<x.w*y.c;
}
priority_queue<node> q;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>X;
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    for(int i=2;i<=n;i++)
    {
        cin>>t[i];
        if(t[i]==1)
            w[i]=0,c[i]=1;
        else
        {
            int a,d,h;
            cin>>a>>d>>h;
            w[i]=(h+X-d-1)/(X-d)-1;
            c[i]=0;
            ans-=w[i]*a;
        }
    }
    D.init();
    for(int i=2;i<=n;i++)ver[i]=++now,q.push({c[i],w[i],i,ver[i]});
    while(!q.empty())
    {
        node t=q.top();q.pop();
        if(t.ver!=ver[t.id]||!fa[t.id])continue;
        int f=D.get(fa[t.id]);
        ans+=c[f]*w[t.id];
        D.merge(t.id,f);
        c[f]=c[t.id]+c[f];
        w[f]=w[t.id]+w[f];
        ver[f]=++now;
        node tmp={c[f],w[f],f,ver[f]};
        q.push(tmp);
    }
    cout<<ans<<endl;
    return 0;
}