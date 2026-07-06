#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int t, m, val[1005], ti[1005], f[1005];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t>>m;
    for(int i=1;i<=m;i++)
        cin>>ti[i]>>val[i];
    for(int i=1;i<=m;i++)
        for(int j=t;j>=ti[i];j--)
            f[j]=max(f[j],f[j-ti[i]]+val[i]);
    cout<<f[t];
    return 0;
}