#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i+n]=a[i];
    }
    for(int i=1;i<=2*n;i++)
        a[i]+=a[i-1];
    deque<int> q;
    for(int i=1;i<=2*n;i++)
    {
        while(!q.empty()&&a[q.back()]>=a[i])
            q.pop_back();
        q.push_back(i);
        while(!q.empty()&&q.front()<=i-n)
            q.pop_front();
        if(i>=n&&a[q.front()]>=a[i-n])
        {
            cout<<i-n+1<<endl;
            return;
        }
    }
    cout<<-1<<endl;
    return;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}