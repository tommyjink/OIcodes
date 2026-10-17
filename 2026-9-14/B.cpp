#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2005;
int n,a[N],cnt[N];
vector<int> v[N],ans;
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
        if(a[i]>i){cout<<"NO"<<endl;return;}
    for(int i=1;i<=n;i++)cnt[i]=0,v[i].clear();
    for(int i=n;i>=1;i--)cnt[a[i]]++,v[a[i]].push_back(i);
    ans.clear();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            // cout<<"i="<<i<<",j="<<j<<",a[j]="<<a[j]<<",cnt[i]="<<cnt[i]<<",cnt[j]="<<cnt[j]<<endl;
            while(cnt[a[j]]>1&&cnt[j])
            {
                ans.push_back(v[j].back());
                cnt[a[j]]--;
                v[a[j]].pop_back();
                a[j]++;
                v[a[j]].push_back(j);
                cnt[a[j]]++;
            }
        }
    }
    cout<<"YES"<<endl;
    cout<<ans.size()<<endl;
    for(int i:ans)cout<<i<<" ";
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