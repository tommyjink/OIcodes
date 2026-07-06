#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,ans=0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    priority_queue<int> q;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        q.push(x);q.push(x);
        ans+=q.top()-x;
        q.pop();
    }
    cout<<ans<<endl;
    return 0;
}