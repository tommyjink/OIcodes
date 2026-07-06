#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl "\n"
using namespace std;
const int N=1e5+10;
int n,m,a[N],b[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    int ans=4e18;
    for(int c=-100;c<=100;c++)
    {
        for(int k=0;k<n;k++)
        {
            int res=0;
            for(int i=1;i<=n;i++)
            {
                int idx=(i+k-1)%n+1;
                res+=(a[i]+c-b[idx])*(a[i]+c-b[idx]);
            }
            ans=min(ans,res);
        }
    }
    cout<<ans<<endl;
    return 0;
}