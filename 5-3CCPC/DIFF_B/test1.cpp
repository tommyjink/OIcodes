#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
queue<int> q;
int n,m,cnt[N],tot[N],num[N],p[N],tt=0;
vector<pair<int,int>> a[N],b[N];  
map<int,int> mp;
bool cmp(pair<int,int> x,pair<int,int> y)
{
    return x.second<y.second;
}
int f(int x)
{
    if(!mp.count(x))
        mp[x]=++tt;
    return mp[x];
    // tt=n;
    return x;
}
void solve()
{
    int ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        tot[f(x)]=y;
    }
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>cnt[i];
        for(int j=1;j<=cnt[i];j++)
        {
            int x,y;
            cin>>x>>y;
            a[f(x)].push_back(make_pair(i,y));
        }
        cin>>num[i];
        for(int j=1;j<=num[i];j++)
        {
            int x,y;
            cin>>x>>y;
            b[i].push_back(make_pair(f(x),y));
        }
    }
    for(int i=1;i<=tt;i++)
        sort(a[i].begin(),a[i].end(),cmp);
    while(!q.empty())q.pop();
    for(int i=1;i<=tt;i++)
        q.push(i);
    for(int i=1;i<=m;i++)
        if(cnt[i]==0)
        {
            for(auto j:b[i])
                tot[j.first]+=j.second;
            ans++;
        }
    while(!q.empty())
    {
        int t=q.front();q.pop();
        // cout<<t<<"!"<<endl;
        while(p[t]<(int)a[t].size()&&a[t][p[t]].second<=tot[t])
        {
            cnt[a[t][p[t]].first]--;
            if(cnt[a[t][p[t]].first]==0)
            {
                for(auto i:b[a[t][p[t]].first])
                    q.push(i.first),tot[i.first]+=i.second;
                ans++;
                // cout<<"get:"<<a[t][p[t]].first<<endl;
            }
            p[t]++;
        }
        // cout<<p[t]<<"__"<<endl;
    }
    cout<<ans<<endl;
    // cout<<tt<<" "<<n<<endl;
}
signed main()
{
    // freopen("test.in","r",stdin);
    // freopen("test1.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
/*
3 1 1 2 1 3 1
4
3 1 1 2 1 3 1
3 1 1 2 1 3 1
3 1 2 2 2 3 2
3 1 1 2 1 3 1
3 1 3 2 3 3 3
3 1 1 2 1 3 1
3 1 99 2 99 3 99
3 1 1 2 1 3 1
*/