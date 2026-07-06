#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,k;
void solve()
{
    cin>>n>>k;
    int t=n,p=0;
    while(t)
        p+=t%3,t/=3;
    if(k<p||(k-p)%2==1)
        cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("split.in","r",stdin);
    freopen("split.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}
/*
4
5 3
17 2
163 79
1000000000000000000 1000000000000000000

Yes
No
Yes
Yes
*/