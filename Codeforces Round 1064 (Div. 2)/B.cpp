#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int a,b,n;
void solve()
{
    cin>>a>>b>>n;
    int m=(int)(a/b);
    if(a/n>=b)cout<<1<<endl;
    else if(m==1&&a==b)cout<<1<<endl;
    else cout<<2<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
/*
12
8 1 6
9 6 2
10 3 1
10 1 10
9 2 1
5 5 6
6 2 7
9 1 9
3 2 6
8 1 7
8 1 9
8 2 4


*/