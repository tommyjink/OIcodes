#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e6+10;
int n,m,a[N],ans;
pii b[N];
priority_queue<int> q;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)
    {
        ans=0;while(!q.empty())q.pop();
        cin>>n>>m;
        for(int i=1;i<=n;i++)cin>>a[i],q.push(a[i]),ans+=a[i];
        for(int i=1;i<=m;i++)cin>>b[i].second;
        for(int i=1;i<=m;i++)cin>>b[i].first;
        sort(b+1,b+1+m,greater<pii>());
        for(int i=1;i<=m;i++)
        {
            int x=q.top(),save=min(b[i].first,x)-b[i].second;
            if(save>0){q.pop(),q.push(b[i].second);ans-=save;}
        }
        cout<<ans<<endl;
    }
    return 0;
}