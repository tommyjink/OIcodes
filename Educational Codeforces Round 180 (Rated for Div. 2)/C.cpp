#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N];
void solve()
{
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n-2;i++)
    {
        for(int j=i+1;j<=n-1;j++)
        {
            int l=a[n]-a[i]-a[j]+1;
            int r=a[i]+a[j];
            int pl=lower_bound(a+j+1,a+1+n,l)-a;
            int pr=lower_bound(a+j+1,a+1+n,r)-a-1;
            if(pr>=pl)ans+=pr-pl+1;
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}

/*

6
3
1 2 3
4
1 1 2 4
5
7 7 7 7 7
5
1 1 2 2 4
6
2 3 3 4 5 5
5
1 1 1 1 3
*/