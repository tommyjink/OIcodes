#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,a[N],p=1,cnt=0,ans=0;
pair<int,int> b[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i],ans+=a[i];
    for(int i=1;i<=m;i++)cin>>b[i].first;
    for(int i=1;i<=m;i++)cin>>b[i].second;
    sort(a+1,a+1+n,greater<int>());
    sort(b+1,b+1+m,greater<pair<int,int>>());
    priority_queue<int,vector<int>,greater<int> > q;
    for(int i=1;i<=m;i++)
    {
        while(p<=n&&b[i].first<=a[p])p++,cnt++;
        if(cnt>0)cnt--,ans-=b[i].second,q.push(b[i].second);
        else if(!q.empty()&&q.top()<b[i].second)ans=ans+q.top()-b[i].second,q.pop(),q.push(b[i].second);
    }
    cout<<ans<<endl;
    return 0;
}