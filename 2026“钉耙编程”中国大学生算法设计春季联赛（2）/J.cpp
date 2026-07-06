#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int x,k;
vector<int> ans;

void solve()
{
    cin>>x>>k;
    ans.clear();
    int now=x;
    while(1)
    {
        if(now>61)
        {
            ans.push_back(1);
            now--;
            if(k==1) break;
            k--;
            continue;
        }
        for(int i=1;i<=now;i++)
        {
            int cnt=1ll<<(now-i);
            if(k>cnt) k-=cnt;
            else
            {
                ans.push_back(i);
                now-=i;
                break;
            }
        }
        if(k==1) break;
        k--;
    }
    for(auto i:ans) cout<<i<<' ';
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