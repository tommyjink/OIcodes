
#include<bits/stdc++.h>
using namespace std;
int T,n,q,a[100005],b[100005],ans[40],al,pc;
void sol(){
    cin>>n>>q;al=0;
    for(int i=1;i<=n;i++)cin>>a[i],al|=a[i];
    pc=__builtin_popcount(al);
    for(int i=0;i<=31;i++)ans[i]=0;
    for(int i=1,m=0;i+pc<=31;i++,m++){
        for(int j=1;j<=n;j++)b[j]=a[j];
        while((al>>m)&1)++m;
        for(int j=m;j>=0;j--){
            for(int k=1;k<=n;k++)b[k]&=(1<<(j+1))-1;
            int mx=max_element(b+1,b+n+1)-b;
            if(b[mx]>=(1<<j))continue;
            ans[i+pc]+=(1<<j)-b[mx];
            b[mx]=1<<j;
        }
    }
    while(q--){
        int x;cin>>x;
        cout<<upper_bound(ans,ans+32,x)-ans-1<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--)sol();
    return 0;
}
