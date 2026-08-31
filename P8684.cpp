#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=3e5+10;
int n,a[N],tag[N];
vector<int> b;
void solve()
{
    b.clear();
    cin>>n;
    for(int i=0;i<=n+1;i++)tag[i]=a[i]=0;
    for(int i=2;i<=n+1;i++)cin>>a[i],a[i]+=a[i-1];
    int L=a[1],R=a[n+1],p=1,q=1;
    if(L>R)swap(L,R);
    sort(a+1,a+1+n+1);
    for(int i=1;i<=n+1;i++)if(a[i]==L)p=i;
    for(int i=1;i<=n+1;i++)if(a[i]==R)q=i;
    for(int i=p;i>=1;i-=2)b.push_back(a[i]),tag[i]=true;
    for(int i=tag[1]?2:1;i<=p;i+=2)b.push_back(a[i]),tag[i]=true;
    for(int i=p+1;i<=q-1;i++)b.push_back(a[i]),tag[i]=true;
    for(int i=q+1;i<=n+1;i+=2)b.push_back(a[i]),tag[i]=true;
    for(int i=tag[n+1]?n:n+1;i>=q;i-=2)b.push_back(a[i]),tag[i]=true;
    int ans=0;
    for(int i=0;i<b.size()-1;i++)
        ans=max(ans,abs(b[i]-b[i+1]));
    // for(auto i:b)cout<<i<<" ";
    // cout<<endl;
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}