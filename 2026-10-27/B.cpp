#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=2e5+10,INF=4e18;
int n,a[N],b[N],vis[N],pre[N],nxt[N];
pii p[N];
struct node
{
    int val,x,y,z;
    bool operator<(const node &b)const
    {
        return val==b.val?x>b.x:val>b.val;
    }
};
priority_queue<node> q;
void add(int x)
{
    if(!x||!nxt[x]||!nxt[nxt[x]])return;
    int y=nxt[x],z=nxt[y];
    q.push({a[z]-a[x],x,y,z});
}
void solve()
{
    for(int i=1;i<=n;i++)pre[i]=i-1,nxt[i]=i+1;
    nxt[n]=0;
    for(int i=1;i+2<=n;i++)add(i);
    for(int t=1;t<=n/3;t++)
    {
        node now=q.top();q.pop();
        while(vis[now.x]||vis[now.y]||vis[now.z]||nxt[now.x]!=now.y||nxt[now.y]!=now.z)
        {
            now=q.top();q.pop();
        }
        int x=now.x,y=now.y,z=now.z;
        cout<<x<<" "<<y<<" "<<z<<endl;
        vis[x]=vis[y]=vis[z]=1;
        int l=pre[x],r=nxt[z];
        nxt[l]=r;
        pre[r]=l;
        add(l);
        if(l)add(pre[l]);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],p[i]={a[i],i};
    int tag=1;
    for(int i=2;i<=n;i++)
        if(a[i]<a[i-1])tag=0;
    if(tag)
    {
        solve();
        return 0;
    }
    sort(p+1,p+n+1);
    int now=0;
    for(int t=1;t<=n/3;t++)
    {
        int m=0,mn=INF;
        for(int i=1;i<=n;i++)
            if(!vis[p[i].second])b[++m]=p[i].second;
        for(int i=1;i+2<=m;i++)
            mn=min(mn,a[b[i+2]]-a[b[i]]);
        now=max(now,mn);
        int l=1,x=n+1,y=n+1,z=n+1;
        set<int> st;
        for(int r=1;r<=m;r++)
        {
            st.insert(b[r]);
            while(a[b[r]]-a[b[l]]>now)st.erase(b[l++]);
            if(st.size()<3)continue;
            auto it=st.begin();
            int i=*it++;
            int j=*it++;
            int k=*it;
            if(i<x||(i==x&&(j<y||(j==y&&k<z))))
                x=i,y=j,z=k;
        }
        cout<<x<<" "<<y<<" "<<z<<endl;
        vis[x]=vis[y]=vis[z]=1;
    }
    return 0;
}
