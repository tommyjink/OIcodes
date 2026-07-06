
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
pair<int,int> a[N];
int n,ans;
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].first,a[i].second=i;
    sort(a+1,a+1+n);
    ans=1;
    for(int i=1,value=-1,last=0x3f3f3f3f;i<=n;i++){
        int j=i;
        while(j+1<=n&&a[i].first==a[j+1].first) j++;
        if(value==-1){
            if(a[j].second<last) last=a[i].second;
            else value=1,last=a[j].second;
        }else{
            if(a[i].second>last) last=a[j].second;
            else ans++,value=-1,last=a[i].second;
        }
        i=j;
    }
    cout<<ans;
    return 0;
}
