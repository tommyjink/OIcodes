#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<double,int>
using namespace std;
const int N=1e6+10;
int n,k,x,a[N];
void solve()
{
    priority_queue<pii> q;
    cin>>n>>k>>x;
    for(int i=1;i<=n;i++)
        cin>>a[i],q.push(pii((double)a[i],1));
    while(1)
    {
        pii t=q.top();q.pop();
        // cout<<t.first<<" "<<t.second<<endl;
        if(t.second>k)
        {
            q.push(pii(t.first/2.0,k));
            q.push(pii(t.first,t.second-k));
            break;
        }
        else k-=t.second,q.push(pii(t.first/2.0,t.second*2));
    }
    while(1)
    {
        pii t=q.top();q.pop();
        if(t.second>=x)
        {
            printf("%.18lf\n",t.first);
            return;
        }
        else x-=t.second;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int __t;
    cin>>__t;
    while(__t--)
        solve();
    return 0;
}