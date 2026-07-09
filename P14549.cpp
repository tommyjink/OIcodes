#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=2e5+10,INF=1e10;
int n,k,a[N],fa[N],best[N],bx[N],by[N];
vector<int> v[N];
int get(int x)
{
    if(x==fa[x])return fa[x];
    return fa[x]=get(fa[x]);
}
void solve()
{
    int ans=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i],a[i]%=k;
    if(n==0){cout<<"0"<<endl;return;}
    for(int i=1;i<=n;i++)fa[i]=i;
    int cnt=n;
    set<pii> s;
    for(int i=1;i<=n;i++)
        s.insert({a[i],i});
    while(cnt>1)
    {
        for(int i=1;i<=n;i++)
            v[i].clear(),best[i]=INF;
        for(int i=1;i<=n;i++)
        {
            int rt=get(i);
            v[rt].emplace_back(i);
        }
        for(int rt=1;rt<=n;rt++)
        {
            if(v[rt].empty())continue;
            for(auto x:v[rt])s.erase({a[x],x});
            for(auto x:v[rt])
            {
                auto p=s.begin();
                if(p!=s.end())
                {
                    if((p->first+a[x])%k<best[rt])
                    {
                        best[rt]=(p->first+a[x])%k;
                        bx[rt]=x,by[rt]=p->second;
                    }
                }
                p=s.lower_bound({k-a[x],-INF});
                if(p!=s.end())
                {
                    if((p->first+a[x])%k<best[rt])
                    {
                        best[rt]=(p->first+a[x])%k;
                        bx[rt]=x,by[rt]=p->second;
                    }
                }
            }
            for(auto x:v[rt])s.insert({a[x],x});
        }
        for(int rt=1;rt<=n;rt++)
        {
            if(best[rt]==INF)continue;
            int x=get(bx[rt]);
            int y=get(by[rt]);
            if(x!=y)
            {
                fa[y]=x;
                ans+=best[rt];
                cnt--;
            }
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}