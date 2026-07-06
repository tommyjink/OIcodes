#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,m,a[1005],f[100005]={1},sum=0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {    
        cin>>a[i];
        sum+=a[i];
    }
    for(int i=1;i<=n;i++)
        for(int j=sum;j>=a[i];j--)
            f[j]+=f[j-a[i]];
    cout<<f[m]<<endl;
    return 0;
}