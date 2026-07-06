#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],ans=0;
priority_queue<int,vector<int>,greater<int>> q;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        q.push(a[i]);
        if(q.top()<a[i])ans+=a[i]-q.top(),q.pop(),q.push(a[i]);
    }
    cout<<ans<<endl;
    return 0;
}