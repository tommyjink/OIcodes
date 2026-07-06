#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6;
int V,n,v[N],f[N];
signed main()
{
    cin>>V>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    for(int i=1;i<=n;i++)
        for(int j=V;j>=v[i];j--)
            f[j]=max(f[j],f[j-v[i]]+v[i]);
    cout<<V-f[V];
    return 0;
}