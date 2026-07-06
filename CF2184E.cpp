#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+100;
int n,a[N];
void solve()//4 3 2 1
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++)
        a[i]=abs(a[i+1]-a[i]);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t; 
    while(t--)solve();
    return 0;
}