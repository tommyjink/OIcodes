#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,k,ans=1e18;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    for(int i=2;k>1;i++)
    {
        int cnt=0;
        while(k%i==0)
        {
            k/=i;
            cnt++;
        }
        if(cnt)
        {
            int x=i,res=0;
            while(x<=n)
            {
                res+=n/x;
                x*=i;
            }
            ans=min(ans,res/cnt);
            // cout<<i<<" "<<res<<" "<<cnt<<endl;
        }
    }
    cout<<ans<<endl;
    
    return 0;
}