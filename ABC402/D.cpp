#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+100;
int n,m,sum[N*2],ans=0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    ans=m*(m-1)/2;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        sum[(x+y-1)%n+1]++;
    }
    // for(int i=1;i<=2*n;i++)
    //     if(sum[i])cout<<i<<"!"<<sum[i]<<endl;
    for(int i=1;i<=2*n;i++)
        ans-=sum[i]*(sum[i]-1)/2;
    cout<<ans<<endl;
    return 0;
}