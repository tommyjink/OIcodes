#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=2e5+10,INF=1e16;
int n,tag[N];
struct node
{
    vector<pii> l,r;
    int ans;
};
bool operator <(node x,node y)
{
    return x.ans<y.ans;
}
node dfs1(int k,vector<pii> a)
{
    if(a.size()<=0)return {vector<pii>(),vector<pii>(),INF};
    if(k<0)
    {
        node res={vector<pii>(),vector<pii>(),0};
        for(int i=0;i<a.size();i++)
        {
            if(i&1)res.l.push_back(a[i]);
            else res.r.push_back(a[i]);
        }
        return res;
    }
    vector<pii> L,R;
    for(pii i:a)
        if(i.first&(1ll<<k))L.push_back(i);
        else R.push_back(i);
    if(max(L.size(),R.size())>2)
    {
        node x=dfs1(k-1,L),y=dfs1(k-1,R);
        node res;
        res.ans=min(x.ans,y.ans);
        res.l=x.l;
        res.r=x.r;
        for(auto i:y.l)res.l.push_back(i);
        for(auto i:y.r)res.r.push_back(i);
        return res;
    }
    node res={vector<pii>(),vector<pii>(),0};
    for(int i=0;i<(1<<L.size());i++)
    {
        for(int j=0;j<(1<<R.size());j++)
        {
            vector<pii> ll,rr;
            for(int ii=0;ii<L.size();ii++)
                if(i&(1<<ii))ll.push_back(L[ii]);
                else rr.push_back(L[ii]);
            for(int ii=0;ii<R.size();ii++)
                if(j&(1<<ii))ll.push_back(R[ii]);
                else rr.push_back(R[ii]);
            node now={ll,rr,INF};
            for(int ii=0;ii<ll.size();ii++)
                for(int jj=ii+1;jj<ll.size();jj++)
                    now.ans=min(now.ans,ll[ii].first^ll[jj].first);
            for(int ii=0;ii<rr.size();ii++)
                for(int jj=ii+1;jj<rr.size();jj++)
                    now.ans=min(now.ans,rr[ii].first^rr[jj].first);
            res=max(res,now);
        }
    }
    return res;
}
void solve()
{
    cin>>n;
    vector<pii> a;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        a.push_back({x,i});
    }
    node res=dfs1(40,a);
    cout<<(res.ans==INF?0:res.ans)<<endl;
    for(pii i:res.l)tag[i.second]=1;
    for(pii i:res.r)tag[i.second]=2;
    for(int i=1;i<=n;i++)
        cout<<tag[i];
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}