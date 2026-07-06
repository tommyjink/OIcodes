#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)
    {
        int x,y,ans=0;
        cin>>x>>y;
        while((x>=2&&y>=1)||(y>=2&&x>=1))
        {
            if(x<y)swap(x,y);
            x-=2,y-=1;
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}