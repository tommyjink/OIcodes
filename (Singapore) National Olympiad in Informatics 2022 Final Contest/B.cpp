#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e6+10;
int n,sum=0;
pii a[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        a[i]=pii(x,x);
    }
    for(int i=1;i<=n;i++)
    {
        int l;cin>>l;
        a[i].first+=l;
    }
    sort(a+1,a+1+n);
    priority_queue<int> q;
    for(int i=1;i<=n;i++)
    {
        q.push(a[i].second);
        sum+=a[i].second;
        // cout<<a[i].first<<","<<a[i].second<<endl;
        while(!q.empty()&&sum>a[i].first)
        {
            sum-=q.top();
            q.pop();
        }
    }
    cout<<q.size()<<endl;
    return 0;
}