#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e7+10;
int n,a[N];
string s;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>s;
    s=" "+s;
    for(int i=1;i<=2*n-1;i++)
        a[i]=(s[i]=='W'),a[i]+=a[i-1];
    int ans=0;
    for(int i=n;i<=2*n-1;i++)
    {
        int sum=a[i]-a[i-n];
        ans=max(ans,sum);
    }
    cout<<ans<<endl;
    return 0;
}
/*
RWWRRRWWW
W W W W W R R R W
W R W W W R R R W

*/