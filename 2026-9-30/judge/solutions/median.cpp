#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll INF=4e18;
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("median.in","r",stdin); freopen("median.out","w",stdout);
    int n;cin>>n; vector<int>a(n),state(n,0);vector<ll>c(n);
    vector<array<ll,3>>dp(n);
    map<int,vector<int>>nodes, queries;vector<int> coords;
    for(int i=0;i<n;i++){cin>>a[i]>>c[i];nodes[a[i]].push_back(i);coords.push_back(a[i]);}
    int q;cin>>q;vector<ll>ans(q);
    for(int i=0,x;i<q;i++){cin>>x;queries[x].push_back(i);coords.push_back(x);}
    auto calc=[&](int u){
        array<ll,3>own{c[u],c[u],c[u]};own[state[u]]=0;
        if(2*u+1>=n){dp[u]=own;return;}
        int l=2*u+1,r=2*u+2;
        dp[u].fill(INF);
        for(int x=0;x<3;x++) for(int y=0;y<3;y++) for(int z=0;z<3;z++){
            int v=x+y+z-min({x,y,z})-max({x,y,z});
            dp[u][v]=min(dp[u][v],own[x]+dp[l][y]+dp[r][z]);
        }
    };
    for(int u=n-1;u>=0;u--)calc(u);
    auto update=[&](int u,int v){state[u]=v;while(true){calc(u);if(!u)break;u=(u-1)/2;}};
    sort(coords.begin(),coords.end());coords.erase(unique(coords.begin(),coords.end()),coords.end());
    for(int x:coords){
        for(int u:nodes[x])update(u,1);
        for(int i:queries[x])ans[i]=dp[0][1];
        for(int u:nodes[x])update(u,2);
    }
    for(ll v:ans)cout<<v<<'\n';
}
