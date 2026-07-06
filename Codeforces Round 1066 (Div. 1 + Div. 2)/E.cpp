#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int t,n,k,x,num[500005],ans;
set<int> st;
vector<int> e;
void solve(){
    ans=x=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>x;
        num[x]++;
    }
    for(int i=1;i<=3*n;i++){
        if(!num[i]) st.insert(i);
    }
    for(int i=3*n;i>=1;i--){
        if(num[i]<=1) continue;
        int tot=0,lst=i;
        auto p=st.lower_bound(i);
        while(p!=st.end()){
            e.emplace_back(*p);
            tot++;
            lst=*p;
            p=next(p);
            if(num[i]-tot<=1) break;
            if(p==st.end()) break;
        }
        if(num[i]>k) ans=max(ans,lst-i);
        for(auto u:e) st.erase(u);
        e.clear();
    }
    if(ans==0) cout<<"0\n";
    else cout<<ans-k+1<<"\n";
    st.clear();
    for(int i=1;i<=2*n;i++) num[i]=0;
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}