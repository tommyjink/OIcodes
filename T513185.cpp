#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,q,a[N],mx=0,mn=1e10;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i],mx=max(mx,a[i]),mn=min(mn,a[i]);
    
    return 0;
}