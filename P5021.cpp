#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N=5e4+10;
int n,m,mid,ans=0,f[N];
int head[N],tot=0;
struct node
{
    int from,to,next,val;
}e[N*2];
void add(int x,int y,int z)
{
    e[++tot]=(node){x,y,head[x],z};
    head[x]=tot;
}
void dfs(int x,int fa)
{
    f[x]=0;
    multiset<int> s;
    for(int i=head[x],v=e[i].to;i;i=e[i].next,v=e[i].to)
        if(v!=fa)dfs(v,x),s.insert(f[v]+e[i].val);
    while(!s.empty()&&*s.rbegin()>=mid)
        s.erase(--s.end()),ans++;
    while(!s.empty())
    {
        int now=*s.begin();s.erase(s.begin());
        auto p=s.lower_bound(mid-now);
        if(p==s.end())f[x]=max(f[x],now);
        else ans++,s.erase(p);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n-1;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
        add(y,x,z);
    }
    int l=0,r=1e9;
    while(l<r)
    {
        ans=0,mid=(l+r+1)>>1;
        dfs(1,0);
        // cout<<mid<<","<<ans<<endl;
        if(ans<m)r=mid-1;
        else l=mid;
    }
    cout<<l<<endl;
    return 0;
}