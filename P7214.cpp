#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e5+10,INF=4e18;
int n,m,dis[N],mn1[N*4],mn2[N*4];
vector<int> v;
priority_queue<pii> q;
struct node
{
    int t,l,r,c;
    bool operator <(const node &x)const
    {
        return t<x.t;
    }
}a[N];
void pushup(int k)
{
    mn1[k]=min(mn1[k*2],mn1[k*2+1]);
    mn2[k]=min(mn2[k*2],mn2[k*2+1]);
}
void build(int k,int l,int r)
{
    mn1[k]=mn2[k]=INF;
    if(l==r)return;
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
}
void change(int k,int l,int r,int x,int v1,int v2)
{
    if(l==r)
    {
        mn1[k]=v1;
        mn2[k]=v2;
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid)change(k*2,l,mid,x,v1,v2);
    else change(k*2+1,mid+1,r,x,v1,v2);
    pushup(k);
}
void ask(int k,int l,int r,int x,int y,int val,int op)
{
    if(y<l||r<x)return;
    if((op?mn1[k]:mn2[k])>val)return;
    if(l==r)
    {
        v.push_back(l);
        mn1[k]=mn2[k]=INF;
        return;
    }
    int mid=(l+r)>>1;
    ask(k*2,l,mid,x,y,val,op);
    ask(k*2+1,mid+1,r,x,y,val,op);
    pushup(k);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i].t>>a[i].l>>a[i].r>>a[i].c;
        a[i].l--;
    }
    sort(a+1,a+m+1);
    build(1,1,m);
    for(int i=1;i<=m;i++)
    {
        if(a[i].l==0)
        {
            dis[i]=a[i].c;
            q.push((pii){-dis[i],i});
        }
        else
        {
            dis[i]=INF;
            change(1,1,m,i,a[i].l-a[i].t,a[i].l+a[i].t);
        }
    }
    while(!q.empty())
    {
        int x=q.top().second;
        q.pop();
        v.clear();
        if(x>1)ask(1,1,m,1,x-1,a[x].r-a[x].t,1);
        if(x<m)ask(1,1,m,x+1,m,a[x].r+a[x].t,0);
        for(auto y:v)
        {
            if(dis[y]>dis[x]+a[y].c)
            {
                dis[y]=dis[x]+a[y].c;
                q.push((pii){-dis[y],y});
            }
        }
    }
    int ans=INF;
    for(int i=1;i<=m;i++)
        if(a[i].r==n)ans=min(ans,dis[i]);
    if(ans==INF)cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}
