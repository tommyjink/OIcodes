#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e5+10;
int n,s,a[N],sum,ans;
vector<int> in[N],out[N];
set<pii> p,q;
void move(int k)
{
    while((int)q.size()>k)
    {
        auto x=q.begin();
        sum-=x->first;
        p.insert(*x);
        q.erase(x);
    }
    while((int)q.size()<k&&!p.empty())
    {
        auto x=prev(p.end());
        // cout<<x->first<<"!"<<endl;
        sum+=x->first;
        q.insert(*x);
        p.erase(x);
    }
    while(!p.empty()&&!q.empty()&&prev(p.end())->first>q.begin()->first)
    {
        auto x=prev(p.end()),y=q.begin();
        pii u=*x,v=*y;
        // cout<<u.first-v.first<<"!"<<endl;
        sum+=u.first-v.first;
        p.erase(x),q.erase(y);
        p.insert(v),q.insert(u);
    }
    // p.clear(),q.clear();
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>s;
    for(int i=1;i<=n;i++)
    {
        int l,r;
        cin>>l>>r>>a[i];
        int x=(s-1)/r+1,y=s/l;
        x=max(x,1ll),y=min(y,n);
        if(x<=y)
        {
            in[x].push_back(i);
            out[y+1].push_back(i);
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(auto i:out[k])
        {
            pii x={a[i],i};
            auto it=q.find(x);
            if(it!=q.end())sum-=a[i],q.erase(it);
            else p.erase(x);
        }
        for(auto i:in[k])
            p.insert({a[i],i});
        move(k);
        if((int)q.size()==k)ans=max(ans,sum);
    }
    cout<<ans<<endl;
    return 0;
}
