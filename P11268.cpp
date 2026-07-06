#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m;
pair<int,int> a[N],b[N];
priority_queue<int> q;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i].first>>a[i].second;
    for(int i=1;i<=m;i++)
        cin>>b[i].first>>b[i].second;
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);
    int p=1,ans=0;
    for(int i=1;i<=n;i++)
    {
        while(p<=m&&b[p].first<=a[i].first)
            q.push(b[p].second),p++;
        if(q.empty()||a[i].first-a[i].second>=q.top())
            ans+=a[i].second;
        else ans+=a[i].first-q.top(),q.pop(),q.push(a[i].first-a[i].second);
    }
    cout<<ans<<endl;
    return 0;
}