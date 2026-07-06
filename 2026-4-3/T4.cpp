#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10;
int n,k,cnt[N],a[N];
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        a[i]=cnt[i]+n/i-1;
    // cout<<endl;
    sort(a+1,a+1+n,greater<int>());
    cout<<a[k]<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=1;i<N;i++)
    {
        for(int j=1;j*j<=i;j++)
        {
            if(j==i)continue;
            if(i%j==0)
            {
                cnt[i]++;
                if(i/j!=j&&i/j!=i)cnt[i]++;
            }
        }
    }
    // for(int i=1;i<=10;i++)cout<<cnt[i]<<" ";
    int t;cin>>t;
    while(t--)solve();
    return 0;
}