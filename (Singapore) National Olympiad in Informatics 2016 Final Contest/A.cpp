#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,a[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        cin>>a[i];
    sort(a+1,a+1+m);
    int ans=0;
    for(int i=1;i<=m;i++)
        if(n>=a[i])n-=a[i],ans++;
    cout<<ans<<endl;
    return 0;
}