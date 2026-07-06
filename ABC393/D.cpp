#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6;
int n,sum[N],dis[N],sumb[N],disb[N],ans=1e13;
string s;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>s;
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1];
        dis[i]=dis[i-1]+sum[i];
        if(s[i-1]=='1')sum[i]++;
    }
    for(int i=n;i>=1;i--)
    {
        sumb[i]=sumb[i+1];
        disb[i]=disb[i+1]+sumb[i];
        if(s[i-1]=='1')sumb[i]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(s[i-1]=='0')continue;
        ans=min(ans,dis[i-1]+disb[i+1]-(sum[i-1])*(sum[i-1]-1)/2-sumb[i+1]*(sumb[i+1]-1)/2);
    }
    cout<<ans<<endl;
    return 0;
}//1010101101
//