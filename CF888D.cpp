#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int f[]={1,0,1,2,9};
int n,k;
int C(int x,int y)
{
    int res=1;
    for(int i=x;i>=x-y+1;i--)res*=i;
    for(int i=y;i>=1;i--)res/=i;
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    int ans=0;
    for(int i=0;i<=k;i++)
        ans+=C(n,i)*f[i];
    cout<<ans<<endl;
    return 0;
}