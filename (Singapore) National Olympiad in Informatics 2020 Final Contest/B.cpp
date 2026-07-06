#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],f[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n==1)cout<<a[1]<<endl;
    if(n==2)cout<<min({a[1]+a[1]+a[2],max(a[1],a[2])*2});
    if(n==3)cout<<min({a[1]+a[1]+a[2]+a[1]+a[2]+a[3],
            max(a[1],a[2])*2+max(a[1],a[2])+a[3],
            a[1]+(max(a[2],a[3])+a[1])*2,
            max({a[1],a[2],a[3]})*3});
    return 0;
}
/*
7
1 1 2 2 2 2 2

14



5
1 3 2 6 3


27
*/