#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    pii a[100000];
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i].first,a[i].second=i;
    sort(a+1,a+1+n);
    cout<<a[1].second<<" "<<a[2].second<<" "<<a[3].second<<endl;
    return 0;
}