#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6;
int n,a[N],ans=0,t=-1e9,cnt=0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i==1)continue;
        if(a[i]-a[i-1]==t)
            cnt++;
        else
        {
            ans+=(1+cnt)*cnt/2-cnt;
            t=a[i]-a[i-1];
            cnt=2;
        }
    }
    ans+=(1+cnt)*cnt/2-cnt;
    cout<<ans+n;
    return 0;
}