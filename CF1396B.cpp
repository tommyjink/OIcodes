#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N];
priority_queue<int> q;
void solve()
{
    while(!q.empty())q.pop();
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],q.push(a[i]);
    while(!q.empty())
    {
        int t=q.top()-1;q.pop();
        if(q.empty())
        {
            cout<<"T"<<endl;
            return;
        }
        int tt=q.top()-1;q.pop();
        if(t)q.push(t);
        if(tt)q.push(tt);
    }
    cout<<"HL"<<endl;
    return ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)
        solve();
    return 0;
}