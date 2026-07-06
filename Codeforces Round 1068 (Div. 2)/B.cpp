#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],b[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    int now1=0,now2=0;
    for(int i=1;i<=n;i++)
    {
        int t1=max({now1-a[i],now2-a[i],b[i]-now1,b[i]-now2});
        int t2=min({now1-a[i],now2-a[i],b[i]-now1,b[i]-now2});
        now1=t1,now2=t2;
    }
    cout<<now1<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}