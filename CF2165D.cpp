#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e6+10;
int n,a[N];
set<int> s[N];
vector<int> v[N];
void solve()
{
    cin>>n;
    for(int i=0;i<=2*n+1;i++)
        v[i].clear(),s[i].clear();
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[a[i]].insert(i);
        v[a[i]].push_back(i);
    }
    int ans=n;
    for(int i=1;i<=2*n;i++)
    {
        for(int j=v[i].size()-1;j>=0;j--)
        {
            int k=v[i][j];
            auto p=s[i-1].lower_bound(k);
            if(p!=s[i-1].end())
            {
                ans--;
                s[i-1].erase(p);
            }
            else
            {
                p=s[i+1].lower_bound(k);
                if(p!=s[i+1].end())
                {
                    ans--;
                    s[i+1].erase(p);
                }
            }
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}