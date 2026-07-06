#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,m,ans=0;
priority_queue<int> q;
signed main()
{
    freopen("shopping.in","r",stdin);
    freopen("shopping.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        q.push(x);
    }
    while(m--&&!q.empty())
    {
        int t=q.top();q.pop();
        q.push(t/2);
    }
    while(!q.empty())
        ans+=q.top(),q.pop();
    cout<<ans<<endl;
    return 0;
}