#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("jobs.in","r",stdin); freopen("jobs.out","w",stdout);
    int T;cin>>T;
    while(T--){
        int n;cin>>n; vector<pair<ll,ll>> a(n);
        for(auto &[d,t]:a){ll s;cin>>s>>t;d=s+t;}
        sort(a.begin(),a.end()); priority_queue<ll> pq; ll sum=0;
        for(auto [d,t]:a){pq.push(t);sum+=t;if(sum>d){sum-=pq.top();pq.pop();}}
        cout<<pq.size()<<'\n';
    }
}
