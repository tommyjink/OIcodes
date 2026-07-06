#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int x,y,ans_p,ans_q,mi;
void check(int p,int q){
    if((p&q)==0 && abs(p-x)+abs(q-y)<mi){
        mi=abs(p-x)+abs(q-y);
        ans_p=p; ans_q=q;
    }
}
void solve(){
    cin>>x>>y;
    mi=2e18;
    check(x,y);
    for(int i=0;i<30;i++){
        if(!((x&y)>>i&1)) continue;
        int msk=(1ll<<i)-1;
        check(((x>>i)+1)<<i, y);
        check(x, ((y>>i)+1)<<i);
        check(((x>>i)<<i)-1, y>>i<<i);
        check(x>>i<<i, ((y>>i)<<i)-1);
    }
    cout<<ans_p<<" "<<ans_q<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}