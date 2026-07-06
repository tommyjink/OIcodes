#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=2e5+10;
int n,ans,sum;
int p[N],f[N],cnt[N];
vector<int> e[N];

void dfs(int x,int fa,int mex,int flg)
{
    cnt[p[x]]++;
    while(cnt[mex])mex++;
    if(flg)f[x]=mex;
    sum+=mex;
    for(auto v:e[x])
    {
        if(v==fa)continue;
        dfs(v,x,mex,flg);
    }
    cnt[p[x]]--;
}

int cal(int flg)
{
    sum=0;
    for(int i=0;i<=n;i++)cnt[i]=0;
    dfs(1,0,0,flg);
    return sum;
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
        e[i].clear();
    }
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        e[x].push_back(y),e[y].push_back(x);
    }
    ans=cal(1);
    for(int i=1;i<=n;i++)
    {
        int t=p[i];
        p[i]=f[i];
        ans=max(ans,cal(0));
        p[i]=t;
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
