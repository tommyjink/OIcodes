#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("digit.out","w",stdout);
    freopen("digit.in","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        int sum=r1-l1+r2-l2,ans=0;
        for(int i=0;i<=min(sum,10ll);i++)
        {
            int x=r1+r2-i;
            while(x)
            {
                ans=max(ans,x%10);
                x/=10;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}