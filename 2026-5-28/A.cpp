#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=3510;
int n,l[N],r[N],out[N],ans[N];
vector<int> pre[N];

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>l[i]>>r[i];
        pre[i].clear();
        out[i]=ans[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)continue;
            if(l[i]>l[j]&&r[i]<r[j])
            {
                out[i]++;
                pre[j].push_back(i);
            }
        }
    }
    priority_queue<int> q;
    for(int i=1;i<=n;i++)
        if(!out[i])q.push(i);
    for(int i=n;i>=1;i--)
    {
        int x=q.top();
        q.pop();
        ans[x]=i;
        for(auto v:pre[x])
        {
            out[v]--;
            if(!out[v])q.push(v);
        }
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}
