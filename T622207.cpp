#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2000+10;
int n,a[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        a[x+1000]++;
    }
    int ans=0;
    for(int i=0;i<=2000;i++)
    {
        for(int j=i+1;j<=2000;j++)
        {
            ans+=(j-i)*(j-i)*(a[i]*a[j]);
        }
    }
    cout<<ans<<endl;
    return 0;
}