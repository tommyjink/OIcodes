#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e6+10;
int T,n,m,tot,ecnt,ans;
int a[N],val[N],lim[N],head[N];
struct node
{
    int l,r,v,id;
}q[N];
struct edge
{
    int r,v,nxt;
}e[N];
void add(int l,int r,int v)
{
    e[++ecnt]=(edge){r,v,head[l]};
    head[l]=ecnt;
}
int calc(vector<int> &p,vector<int> &id,int v)
{
    int cnt=p.size();
    vector<int> mi(cnt+2,cnt+1),nxt(cnt+1);
    for(int i=0;i<(int)id.size();i++)
    {
        int x=id[i];
        int l=lower_bound(p.begin(),p.end(),q[x].l)-p.begin()+1;
        int r=upper_bound(p.begin(),p.end(),q[x].r)-p.begin();
        if(l>r)return -1;
        mi[l]=min(mi[l],r);
    }
    int mn=cnt+1;
    for(int i=cnt;i>=0;i--)
    {
        if(i<cnt)mn=min(mn,mi[i+1]);
        nxt[i]=mn;
    }
    priority_queue<pii,vector<pii>,greater<pii> > h;
    h.push({0,nxt[0]});
    for(int i=1;i<=cnt+1;i++)
    {
        while(!h.empty()&&h.top().second<i)h.pop();
        if(h.empty())return -1;
        int now=h.top().first;
        if(i==cnt+1)return now;
        now+=max(0ll,a[p[i-1]]-v);
        h.push({now,nxt[i]});
    }
    return -1;
}
void solve()
{
    cin>>n>>m;
    tot=ecnt=ans=0;
    val[++tot]=1;
    for(int i=1;i<=n+1;i++)head[i]=0;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)
    {
        cin>>q[i].l>>q[i].r>>q[i].v;
        val[++tot]=q[i].v;
        add(q[i].l,q[i].r,q[i].v);
    }
    sort(val+1,val+tot+1);
    tot=unique(val+1,val+tot+1)-val-1;
    vector<vector<int> > p(tot+1),id(tot+1);
    priority_queue<pii> h;
    for(int i=1;i<=n;i++)
    {
        for(int j=head[i];j;j=e[j].nxt)
            h.push({e[j].v,e[j].r});
        while(!h.empty()&&h.top().second<i)h.pop();
        lim[i]=h.empty()?1:h.top().first;
        ans+=max(0ll,lim[i]-a[i]);
        int x=lower_bound(val+1,val+tot+1,lim[i])-val;
        p[x].push_back(i);
    }
    for(int i=1;i<=m;i++)
    {
        q[i].id=lower_bound(val+1,val+tot+1,q[i].v)-val;
        id[q[i].id].push_back(i);
    }
    for(int i=1;i<=tot;i++)
    {
        if(id[i].empty())continue;
        int x=calc(p[i],id[i],val[i]);
        if(x<0)
        {
            cout<<-1<<endl;
            return;
        }
        ans+=x;
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--)solve();
    return 0;
}
