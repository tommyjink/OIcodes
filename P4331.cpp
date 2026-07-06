#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,ans=0,res[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    priority_queue<int> q;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;x-=i;
        q.push(x),q.push(x);
        ans+=q.top()-x;
        q.pop();
        res[i]=q.top();
    }
    for(int i=n-1;i>=1;i--)
        res[i]=min(res[i],res[i+1]);
    cout<<ans<<endl;
    for(int i=1;i<=n;i++)cout<<res[i]+i<<endl;
    return 0;
}