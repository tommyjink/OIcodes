#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,f[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    f[1]=1,f[2]=1;
    for(int i=3;i<=n;i++)f[i]=(f[i-1]+f[i-2])%998244353;
    cout<<f[n];
    return 0;
}