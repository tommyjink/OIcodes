#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e6+10;
int n,k,m,pre[N],tag[N];
pii a[N];
struct state{int sum,k,v,lim,id;};
bool operator<(state x,state y){return x.sum>y.sum;}
struct node{int fa,s,t;};
void solve()
{
    cin>>n>>k>>m;
    for(int i=1;i<=n;i++)cin>>a[i].first,a[i].second=i;
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i].first;
    int s=0,ls=-1,lid=-1;
    while(pre[++s]<=k&&s<=n);
    if(s==1){cout<<"0"<<endl;return;}
    vector<pii> ans;
    vector<node> way;
    while(--s>=1)
    {
        if(ans.size()==m)break;
        priority_queue<state> q;
        way.push_back({-1,-1,-1});
        q.push({pre[s],s,s,n+1,(int)way.size()-1});
        while(!q.empty()&&ans.size()<m)
        {
            state t=q.top();q.pop();
            if(t.sum>k)break;
            ans.push_back(pii(s,t.sum));
            ls=s,lid=t.id;
            if(t.v+1<t.lim)
            {
                way.push_back({t.id,t.v,t.v+1});
                q.push({t.sum-a[t.v].first+a[t.v+1].first,t.k,t.v+1,t.lim,(int)way.size()-1});
            }
            if(t.k>1&&t.k<t.v)
            {
                way.push_back({t.id,t.k-1,t.k});
                q.push({t.sum-a[t.k-1].first+a[t.k].first,t.k-1,t.k,t.v,(int)way.size()-1});
            }
        }
    }
    cout<<ans.size()<<endl;
    for(auto i:ans)cout<<i.first<<" "<<i.second<<endl;
    for(int i=1;i<=n;i++)tag[i]=(i<=ls?true:false);
    vector<node> V;
    while(lid!=-1&&way[lid].fa!=-1)V.push_back(way[lid]),lid=way[lid].fa;
    reverse(V.begin(),V.end());
    for(auto i:V)tag[i.s]=false,tag[i.t]=true;
    for(int i=1;i<=n;i++)
        if(tag[i])cout<<a[i].second<<" ";
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