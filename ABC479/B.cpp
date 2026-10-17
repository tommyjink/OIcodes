#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n;
string s;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>s;
    int ans=0;
    s=" "+s;
    for(int i=1;i<=n;i++)
    {
        int j=i;
        while(j<=n&&s[j]=='R')j++;
        j--;
        ans=max(ans,j-i+1);
    }
    cout<<ans<<endl;
    return 0;
}