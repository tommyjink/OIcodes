#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=2010;
int n,d,tar,ans;
int cnt[N],s1[N],s2[N];
vector<int> e[N];

void dfs(int x,int fa,int dep)
{
    if(dep>tar)return;
    cnt[dep]++;
    for(auto v:e[x])
    {
        if(v==fa)continue;
        dfs(v,x,dep+1);
    }
}
/*
void bfs(int s,int fa)
{
    struct node{int num,dep,fa;};
    queue<node> q;
    q.push({s,1,fa});
    for(int i=1;i<=n;i++)cnt[i]=0;
    while(!q.empty())
    {
        node t=q.front();q.pop();
        if(t.dep>tar)continue;
        cnt[t.dep]++;
        for(auto v:e[t.num])
        {
            if(v!=t.fa)
                q.push({v,t.dep+1,t.num});
        }
    }
}
*/
void solve()
{
    cin>>n>>d;
    tar=d-1,ans=0;
    for(int i=1;i<=n;i++)e[i].clear();
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        e[u].push_back(v),e[v].push_back(u);
    }
    for(int rt=1;rt<=n;rt++)
    {
        for(int i=0;i<=tar;i++)s1[i]=s2[i]=0;
        for(auto v:e[rt])
        {
            for(int i=0;i<=tar;i++)cnt[i]=0;
            dfs(v,rt,1);
            for(int i=1;i<=tar;i++)
            {
                if(!cnt[i])continue;
                int j=tar-i;
                if(j>=1)ans+=cnt[i]*(s1[j]+s2[j]);
            }
            for(int i=1;i<=tar;i++)
            {
                if(!cnt[i])continue;
                for(int j=1;i+j<=tar;j++)
                {
                    if(!s1[j])continue;
                    s2[i+j]+=cnt[i]*s1[j];
                }
            }
            for(int i=1;i<=tar;i++)s1[i]+=cnt[i];
        }
    }
    cout<<ans<<endl;
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
