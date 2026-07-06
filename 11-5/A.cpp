#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e6+10;
int n,t[N],w[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>t[i];
    for(int i=1;i<=n;i++)cin>>w[i];
    for(int i=n-1;i>=1;i--)t[i]=min(t[i],t[i+1]);
    int now=0,ans=0;
    for(int i=n;i>=1;i--)
    {
        if(w[i]+now>0) ans+=(w[i]+now)*t[i],now=0;
        else now+=w[i];
    }
    cout<<ans<<endl;
    return 0;
}