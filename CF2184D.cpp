#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,k,ans,C[105][105];
void solve()
{
    ans=0;
    cin>>n>>k;
    for(int i=0;(1LL<<i)<=n;i++)
    {
        if((1LL<<i)==n)
        {
            if(i+1<=k)ans++;
            break;
        }
        for(int j=1;j<=i+1;j++)
        {
            if(i+j<=k)
            {
                ans+=C[i][j-1];
            }
        }
    }
    cout<<n-ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=0;i<=60;i++)
    {
        C[i][0]=1;
        for(int j=1;j<=i;j++)
            C[i][j]=C[i-1][j]+C[i-1][j-1];
    }
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}