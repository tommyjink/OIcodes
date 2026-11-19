#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,x,y,a[N];
int fa[N],r[N];
struct node{int x,y,z;};
bool operator <(node a,node b){return a.z==b.z?(a.x==b.x?a.y>b.y:a.x>b.x):a.z>b.z;}
priority_queue<node> q;
int getfa(int x){return x==fa[x]?x:(fa[x]=getfa(fa[x]));}
void merge(int x,int y)
{
    x=getfa(x),y=getfa(y);
    if(x!=y)r[x]=r[y],fa[y]=x;
}
void solve()
{
    cin>>n>>x>>y;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)fa[i]=i,r[i]=i;
    while(!q.empty())q.pop();
    for(int i=1;i<n;i++)q.push({i,i+1,a[i]+a[i+1]});
    int ans=0;
    while(!q.empty())
    {
        node t=q.top();q.pop();
        // cout<<t.x<<" "<<t.y<<" "<<t.z<<endl;
        if(a[getfa(t.x)]+a[getfa(t.y)]!=t.z||getfa(t.x)==getfa(t.y)||t.z<x)continue;
        ans++;
        merge(t.x,t.y);
        int now=getfa(t.x);
        a[now]=y;
        int ll=now-1,rr=r[now]+1;
        if(ll>=1)q.push({ll,now,a[getfa(ll)]+y});
        if(rr<=n)q.push({now,rr,a[getfa(rr)]+y});
    }
    cout<<ans<<endl;
}
signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}