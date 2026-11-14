#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N];
set<int> s;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    int ans=0;
    vector<int> del;
    for(int i=1;i<=n;i++)
        s.insert(i);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        auto p=s.upper_bound(a[i]);
        if(p==s.begin())
        {
            for(int j:del)s.insert(j);
            del.clear();
            ans++;
            s.erase(a[i]);
            del.push_back(a[i]);
        }
        else
        {
            p=prev(p);
            del.push_back(*p);
            s.erase(p);
        }
    }
    cout<<ans<<endl;
    return 0;
}