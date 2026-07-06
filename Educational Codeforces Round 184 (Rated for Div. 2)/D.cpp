#include<bits/stdc++.h>
#define int unsigned long long
#define endl "\n"
using namespace std;
int x,y,k;
bool check(int mid)
{
    for(int i=1;i<=x;i++)
    {
        mid-=mid/y;
        if(mid<k)return false;
    }
    return true;
}

void solve()
{
    cin>>x>>y>>k;
    int l=0,r=1e13;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(!check(mid))l=mid+1;
        else r=mid;
    }
    if(l>1e12)cout<<"-1"<<endl;
    else cout<<l<<endl;
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
6
2 3 5
2 5 1
20 2 1000000000000
175 10 28
100000 998244353 1999999999
1 1 1


101-123390303042000199999-1

*/