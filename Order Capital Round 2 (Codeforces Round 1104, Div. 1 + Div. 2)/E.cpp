#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=2e5+10;
int n,m,flg;
int a[N],b[N],id[N],p[N],vis[N],to[N],sh[N],use[N],ans[N];
vector<int> c[N];
map<int,set<pii> > mp;
void fill(int x)
{
    int y=to[x],s=sh[x],len=c[x].size();
    for(int i=0;i<len;i++)
        ans[c[x][i]]=c[y][(i+s)%len];
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        vis[i]=0;
        ans[i]=-1;
    }
    for(int i=1;i<=n;i++)
        cin>>b[i];
    m=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i])continue;
        c[++m].clear();
        for(int x=i;!vis[x];x=a[x])
        {
            vis[x]=1;
            id[x]=m;
            p[x]=c[m].size();
            c[m].push_back(x);
        }
    }
    for(int i=1;i<=m;i++)
    {
        to[i]=-1;
        sh[i]=0;
        use[i]=-1;
    }
    flg=1;
    for(int i=1;i<=n&&flg;i++)
    {
        if(b[i]==-1)continue;
        int x=id[i],y=id[b[i]],len=c[x].size();
        if((int)c[y].size()!=len)flg=0;
        else
        {
            int s=(p[b[i]]-p[i]+len)%len;
            if(to[x]!=-1&&(to[x]!=y||sh[x]!=s))flg=0;
            to[x]=y;
            sh[x]=s;
        }
    }
    for(int i=1;i<=m&&flg;i++)
    {
        if(to[i]==-1)continue;
        if(use[to[i]]!=-1&&use[to[i]]!=i)flg=0;
        use[to[i]]=i;
    }
    mp.clear();
    if(flg)
    {
        for(int i=1;i<=m;i++)
        {
            if(to[i]!=-1)fill(i);
            if(use[i]==-1)
            {
                int mn=c[i][0];
                for(int j=1;j<(int)c[i].size();j++)
                    mn=min(mn,c[i][j]);
                int len=c[i].size();
                mp[len].insert((pii){mn,i});
            }
        }
    }
    for(int i=1;i<=n&&flg;i++)
    {
        int x=id[i];
        if(to[x]!=-1)continue;
        int len=c[x].size();
        if(mp[len].empty())
        {
            flg=0;
            break;
        }
        pii now=*mp[len].begin();
        mp[len].erase(mp[len].begin());
        int mn=now.first,y=now.second;
        to[x]=y;
        sh[x]=(p[mn]-p[i]+len)%len;
        fill(x);
    }
    for(int i=1;i<=n&&flg;i++)
        if(b[i]!=-1&&b[i]!=ans[i])flg=0;
    if(!flg)
    {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}
