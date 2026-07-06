#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6;
int n,m,a[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=n-m+1;i<=n;i++)
        cout<<a[i]<<" ";
    for(int i=1;i<=n-m;i++)
        cout<<a[i]<<" ";
    return 0;
}
/*
6 3
1 3 2 1 2 3
*/