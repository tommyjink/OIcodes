#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("circle.in","r",stdin); freopen("circle.out","w",stdout);
    int T; cin>>T;
    while(T--){
        int n; ll m; cin>>n>>m;
        vector<ll>a(n); for(auto &x:a){cin>>x; x%=m;}
        sort(a.begin(),a.end()); a.resize(2*n);
        for(int i=0;i<n;i++) a[n+i]=a[i]+m;
        vector<ll> p(2*n+1);
        for(int i=0;i<2*n;i++) p[i+1]=p[i]+a[i];
        ll ans=LLONG_MAX;
        for(int l=0;l<n;l++){
            int k=n/2, mid=l+k, r=l+n;
            ll left=a[mid]*k-(p[mid]-p[l]);
            ll right=(p[r]-p[mid+1])-a[mid]*(r-mid-1);
            ans=min(ans,left+right);
        }
        cout<<ans<<'\n';
    }
}
