#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e6+10;
int n,now=0;
pii a[N];
priority_queue<int> q;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].second>>a[i].first;
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        if(now+a[i].second<=a[i].first)
            q.push(a[i].second),now+=a[i].second;
        else if(!q.empty()&&q.top()>a[i].second)
            now-=q.top()-a[i].second,q.pop(),q.push(a[i].second);
    }
    cout<<q.size();
    return 0;
}