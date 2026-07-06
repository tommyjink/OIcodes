#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=5e5+5;
int T,n,ans;
struct node{
    int id,x;
}a[N];
inline bool cmp(node x,node y){
    if(x.x!=y.x)return x.x>y.x;
    return x.id>y.id;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n;ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i].x;
            a[i].x-=i;
            a[i].id=i;
        }
        sort(a+1,a+n+1,cmp);
        int cnt=1;
        for(int i=2;i<=n;i++){
            if(a[i].x!=a[i-1].x){
                cnt=1;
                continue;
            }
            if(cnt%2!=0)ans+=max(a[i].x+a[i-1].x+a[i].id+a[i-1].id,0ll);
            cnt++;
        }
        cout<<ans<<endl;
    }
    return 0;
}