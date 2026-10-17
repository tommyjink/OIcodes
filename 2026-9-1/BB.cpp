#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=3e5+10;
int n,m,A,B,C,nxt[N][30],tot=0,cnt[N],L=0,len;
int val[N],dep[N],tag[N],g[N],v[N],id[N];
int ans[N],now,st[N],ed[N];
set<int> t;
vector<int> V,W;
struct node
{
    int l,r,id;
}q[N];
bool cmp(node x,node y)
{
    if(id[x.l]==id[y.l])return (id[x.l]&1)^(x.r>y.r);
    return id[x.l]<id[y.l];
}
int gcd(int x,int y)
{
    return y==0?x:gcd(y,x%y);
}
bool ok(int x)
{
    return (cnt[x]&&B*val[x]+A*dep[x]>=C);
}
void insG(int x)
{
    auto p=t.insert(x).first;
    int l=*prev(p);
    int r=*next(p);
    now-=(r-l-1)*(r-l)/2;
    now+=(x-l-1)*(x-l)/2;
    now+=(r-x-1)*(r-x)/2;
}
void delG(int x)
{
    auto p=t.find(x);
    int l=*prev(p);
    int r=*next(p);
    t.erase(p);
    now+=(r-l-1)*(r-l)/2;
    now-=(x-l-1)*(x-l)/2;
    now-=(r-x-1)*(r-x)/2;
}
inline void insert(int p,int w)
{
    bool old=ok(p);
    cnt[p]++;
    val[p]+=w;
    bool now=ok(p);
    if(old^now)
        if(++tag[g[dep[p]]]==1)insG(g[dep[p]]);
}
inline void del(int p,int w)
{
    
    bool old=ok(p);
    cnt[p]--;
    val[p]-=w;
    bool now=ok(p);
    if(old^now)
        if(!--tag[g[dep[p]]])delG(g[dep[p]]);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>A>>B>>C;
    for(int i=1;i<=n;i++)cin>>v[i];
    V.push_back(0);
    W.push_back(0);
    for(int i=1;i<=n;i++)
    {
        string s;cin>>s;
        L=max(L,(int)s.length());
        st[i]=V.size();
        int p=0;
        for(char c:s)
        {
            int cc=c-'a';
            if(!nxt[p][cc])nxt[p][cc]=++tot,dep[tot]=dep[p]+1;
            p=nxt[p][cc];
            V.push_back(p);
            W.push_back(v[i]);
        }
        ed[i]=V.size()-1;
    }
    for(int i=1;i<=L;i++)cin>>g[i];
    t.insert(0),t.insert(L+1);
    now=L*(L+1)/2;
    cin>>m;
    for(int i=1;i<=m;i++)cin>>q[i].l>>q[i].r,q[i].id=i,q[i].l=st[q[i].l],q[i].r=ed[q[i].r];
    len=sqrt(V.size());
    for(int i=1;i<=V.size();i++)id[i]=(i-1)/len+1;
    sort(q+1,q+1+m,cmp);
    int l=1,r=0;
    for(int i=1;i<=m;i++)
    {
        while(r<q[i].r)++r,insert(V[r],W[r]);
        while(l>q[i].l)--l,insert(V[l],W[l]);
        while(r>q[i].r)del(V[r],W[r]),--r;
        while(l<q[i].l)del(V[l],W[l]),++l;
        ans[q[i].id]=now;
    }
    for(int i=1;i<=m;i++)
    {
        int x=L*(L+1)/2-ans[i];
        int y=L*(L+1)/2;
        int d=gcd(x,y);
        x/=d,y/=d;
        cout<<x<<"/"<<y<<endl;
    }
    return 0;
}