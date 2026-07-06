#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10,M=8e5+10;
int n,m,deg[N],p[N],id[N],mx[N],mn[N],f[N],g[N],L[N],R[N],ord[N],ans[N];
vector<int> G[N];
pair<int,int> e[M];
void solve(int l,int r,int ql,int qr)
{
    // cout<<l<<" "<<r<<" "<<ql<<" "<<qr<<endl;
    if(r<l)return;
    if(qr<ql)
    {
        for(int i=l;i<=r;i++)ans[ord[i]]=ql;
        return;
    }
    int mid=(ql+qr)>>1;
    for(int i=l;i<=r;i++)
    {
        mx[ord[i]]=0,mn[ord[i]]=n+1;
        f[ord[i]]=g[ord[i]]=ord[i];
    }
    for(int i=ql;i<=mid;i++)
    {
        mx[e[i].first]=max(mx[e[i].first],e[i].second);
        mn[e[i].second]=min(mn[e[i].second],e[i].first);
    }
    for(int i=l;i<=r;i++)f[ord[i]]=max(f[ord[i]],mx[ord[i]]);
    for(int i=l+1;i<=r;i++)f[ord[i]]=max(f[ord[i]],f[ord[i-1]]);
    for(int i=l;i<=r;i++)f[ord[i]]=max(f[ord[i]],f[f[ord[i]]]);
    for(int i=l+1;i<=r;i++)f[ord[i]]=max(f[ord[i]],f[ord[i-1]]);
    for(int i=r;i>=l;i--)g[ord[i]]=min(g[ord[i]],mn[ord[i]]);
    for(int i=r-1;i>=l;i--)g[ord[i]]=min(g[ord[i]],g[ord[i+1]]);
    for(int i=r;i>=l;i--)g[ord[i]]=min(g[ord[i]],g[g[ord[i]]]);
    for(int i=r-1;i>=l;i--)g[ord[i]]=min(g[ord[i]],g[ord[i+1]]);
    for(int i=l;i<=r;i++)L[ord[i]]=g[ord[i]],R[ord[i]]=f[ord[i]];
    // for(int i=l;i<=r;i++)cout<<ord[i]<<":"<<L[ord[i]]<<","<<R[ord[i]]<<endl;
    int c1=0,c2=0;
    for(int i=l;i<=r;i++)
        if(f[ord[i]]==g[ord[i]])c1++;
        else c2++;
    vector<int> a(c1+1),b(c2+1);
    c1=c2=0;
    for(int i=l;i<=r;i++)
        if(f[ord[i]]==g[ord[i]])a[++c1]=ord[i];
        else b[++c2]=ord[i];
    for(int i=1;i<=c1;i++)ord[l+i-1]=a[i];
    for(int i=1;i<=c2;i++)ord[l+c1+i-1]=b[i];
    solve(l,l+c1-1,ql,mid-1);
    for(int i=l;i<=r;i++)f[ord[i]]=0,g[ord[i]]=n+1;
    for(int i=l+c1;i<=r;i++)
    {
        if(L[ord[i]]<=ord[i]-1)g[L[ord[i]]]=min(g[L[ord[i]]],ord[i]);
        if(R[ord[i]]>=ord[i]+1)f[R[ord[i]]]=max(f[R[ord[i]]],ord[i]);
    }
    for(int i=l+1;i<=r;i++)f[ord[i]]=max(f[ord[i]],f[ord[i-1]]);
    for(int i=l+c1;i<=r;i++)
        if(f[ord[i]])L[ord[i]]=min(L[ord[i]],L[f[ord[i]]]);
    for(int i=r-1;i>=l;i--)g[ord[i]]=min(g[ord[i]],g[ord[i+1]]);
    for(int i=r;i>=l+c1;i--)
        if(g[ord[i]]!=n+1)R[ord[i]]=max(R[ord[i]],R[g[ord[i]]]);
    solve(l+c1,r,mid+1,qr);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>e[i].first>>e[i].second;
        G[e[i].first].push_back(e[i].second);
        deg[e[i].second]++;
        // cout<<e[i].first<<" "<<e[i].second<<endl;
    }
    queue<int> q;
    for(int i=1;i<=n;i++)
        if(!deg[i])q.push(i);
    for(int i=1;i<=n;i++)
    {
        int x=q.front();q.pop();
        p[i]=x,id[x]=i;
        for(auto v:G[x])
            if(--deg[v]==0)q.push(v);
    }
    // for(int i=1;i<=n;i++)cout<<p[i]<<" ";cout<<endl;
    for(int i=1;i<=m;i++)
        e[i]={id[e[i].first],id[e[i].second]};
    // for(int i=1;i<=m;i++)cout<<e[i].first<<","<<e[i].second<<endl;
    for(int i=1;i<=n;i++)ord[i]=i;
    solve(1,n,1,m);
    for(int i=1;i<=n;i++)
    {
        if(ans[id[i]]==m+1)cout<<-1;
        else cout<<ans[id[i]];
        cout<<" ";
    }
    // cout<<endl;
    return 0;
}
