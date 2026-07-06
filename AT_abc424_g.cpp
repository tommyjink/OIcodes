#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl "\n"
using namespace std;
const int N=1e3+10;
int n,m,a[N];
pii b[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>b[i].first>>b[i].second;
    sort(a+1,a+1+n,greater<int>());
    sort(b+1,b+1+m);
    int ans=0,p=1;
    priority_queue<int> q;
    for(int i=1;i<=n;i++)
    {
        a[i]-=a[i+1];
        while(p<=m&&b[p].first<=i)
            q.push(b[p++].second);
        while(!q.empty()&&a[i])
        {
            a[i]--;
            ans+=q.top();
            q.pop();
        }

    }
    cout<<ans<<endl;
    return 0;
}