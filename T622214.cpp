#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        int nn,n,k,cnt=0;
        cin>>nn>>k;n=nn;
        while(nn)cnt+=nn%3,nn/=3;
        // cout<<n<<","<<cnt<<endl;
        if(k<=n&&k>=cnt&&(k-cnt)%2==0)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}