#include<bits/stdc++.h>
#define int long long
#define lowbit(x) (x&(-x))
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,q,a[N],p[N],l1[N],l2[N],r1[N],r2[N];
int t00[N],t01[N],t10[N],t11[N],ans[N];
struct nodee{int x,y,d;};
struct nodeq{int x,y,id,tag;};
vector<nodeq> Q;
vector<nodee> E;
bool cmpq(nodeq x,nodeq y){return x.x<y.x;}
bool cmpe(nodee x,nodee y){return x.x<y.x;}
void add(int x,int y,int d)
{
    for(int i=y;i<N;i+=lowbit(i))
    {
        t00[i]+=d;
        t01[i]+=d*y;
        t10[i]+=d*x;
        t11[i]+=d*x*y;
    }
}
int query(int x,int y)
{
    int res=0;
    for(int i=y;i;i-=lowbit(i))
        res+=(x+1)*(y+1)*t00[i]+t11[i]-(x+1)*t01[i]-(y+1)*t10[i];
    return res;
}
void addrec(int x,int y,int xx,int yy,int d)
{
    E.push_back({x,y,d});
    E.push_back({xx+1,yy+1,d});
    E.push_back({x,yy+1,-d});
    E.push_back({xx+1,y,-d});
}
void addq(int x,int y,int xx,int yy,int id)
{
    Q.push_back({x-1,y-1,id,1});
    Q.push_back({xx,yy,id,1});
    Q.push_back({x-1,yy,id,-1});
    Q.push_back({xx,y-1,id,-1});
}
void solve()
{
    sort(Q.begin(),Q.end(),cmpq);
    sort(E.begin(),E.end(),cmpe);
    auto ev=E.begin();
    for(auto qu:Q)
    {
        while(ev!=E.end()&&ev->x<=qu.x)
            add(ev->x,ev->y,ev->d),ev=next(ev);
        ans[qu.id]+=qu.tag*query(qu.x,qu.y);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>a[i],p[a[i]]=i;
    set<int> s;
    for(int i=1;i<=n;i++)
    {
        l1[p[i]]=l2[p[i]]=0;
        r1[p[i]]=r2[p[i]]=n+1;
        auto t=s.lower_bound(p[i]);
        if(t!=s.end())
        {
            r1[p[i]]=*t;
            t=next(t);
            if(t!=s.end())r2[p[i]]=*t;
        }
        s.insert(p[i]);
    }
    s.clear();
    for(int i=1;i<=n;i++)
    {
        auto t=s.lower_bound(p[i]);
        if(t!=s.begin())
        {
            t=prev(t);
            l1[p[i]]=*t;
            if(t!=s.begin())l2[p[i]]=*prev(t);
        }
        s.insert(p[i]);
    }
    for(int i=1;i<=n;i++)
    {
        if(l1[i]!=0)addrec(l2[i]+1,i,l1[i],r1[i]-1,a[i]);
        if(r1[i]!=n+1)addrec(l1[i]+1,r1[i],i,r2[i]-1,a[i]);
    }
    for(int i=1;i<=q;i++)
    {
        int l,r;cin>>l>>r;
        addq(l,l,r,r,i);
    }
    solve();
    for(int i=1;i<=q;i++)
        cout<<ans[i]<<endl;
    return 0;
}