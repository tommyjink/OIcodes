#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],p[N],siz[N],cnt[N],tag=1,dfn[N];
int b[N],num=0;
vector<int> g[N];
void dfs(int x)
{
    dfn[x]=++num;
    b[num]=x;
    siz[x]=1;
    for(int v:g[x])
    {
        dfs(v);
        siz[x]+=siz[v];
    }
}
bool cmp(int x,int y)
{
    for(int i=1;i<=min(siz[x],siz[y]);i++)
    {
        int xx=b[dfn[x]+i-1];
        int yy=b[dfn[y]+i-1];
        if(cnt[xx]!=cnt[yy])
            return cnt[xx]<cnt[yy];
    }
    return siz[x]<=siz[y];
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],p[a[i]]=i,g[i].clear(),siz[i]=cnt[i]=0;
    tag=1;
    if(a[1]!=n){cout<<"No"<<endl;return;}
    int now=n;
    for(int i=2;i<=n;i++)
    {
        if(a[i]>=now)continue;
        for(int j=a[i];j<now;j++)
            g[a[i-1]].push_back(j),cnt[a[i-1]]++;
        for(int j=a[i]+1;j<now;j++)
        {
            // cout<<p[j-1]<<","<<p[j]<<endl;
            if(p[j-1]>p[j]){cout<<"No"<<endl;return;}
        }
        now=a[i];
    }
    // for(int i=1;i<=n;i++)
    //     for(int j:g[i])cout<<i<<","<<j<<endl;
    num=0,dfs(n);
    for(int i=1;i<=n;i++)
        if(b[i]!=a[i]){cout<<"No"<<endl;return;}
    for(int i=1;i<=n;i++)
    {
        int lst=0;
        for(int v:g[i])
        {
            if(!lst||cmp(lst,v))
                lst=v;
            else {cout<<"No"<<endl;return;}
        }
    }
    cout<<"Yes"<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}