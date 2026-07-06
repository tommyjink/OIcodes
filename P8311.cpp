#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,d[1000000],mind=1e9+10,tot=0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>d[i],
        mind=min(mind,d[i]),
        tot+=d[i];
    cout<<mind*(n-1)+tot-mind;
    return 0;
}