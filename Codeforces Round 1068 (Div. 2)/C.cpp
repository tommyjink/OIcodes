#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,k,a[N];
map<int,int> mp,vis;
void solve()
{
    mp.clear();
    vis.clear();
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
        mp[a[i]]=true;
    vector<int> v;
    for(int i=1;i<=n;i++)
    {
        if(!mp.count(a[i]))continue;
        if(vis.count(a[i]))continue;
        v.push_back(a[i]);
        for(int j=a[i];j<=k;j+=a[i])
        {
            if(!mp.count(j))
            {
                cout<<"-1"<<endl;
                return;
            }
            vis[j]=true;
        }
    }
    cout<<v.size()<<endl;
    for(auto i:v)cout<<i<<" ";
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}