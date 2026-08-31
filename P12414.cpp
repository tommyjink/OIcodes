#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10;
int n,m,cnt[N];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)cnt[i]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            int x;cin>>x;cnt[x]++;
        }
    for(int i=1;i<=n;i++)
        if(cnt[i]<m){cout<<"Yes"<<endl;return;}
    cout<<"No"<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}