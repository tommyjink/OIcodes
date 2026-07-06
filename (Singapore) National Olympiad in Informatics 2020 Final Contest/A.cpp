#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],mx=0,tag[N];
bool check()
{
    for(int i=1;i<=n;i++)
        if(a[i]>n||a[i]<1)return false;
    return true;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=2;i<=n;i++)
        cin>>a[i],a[i]+=a[i-1],mx=max(mx,a[i]);
    for(int i=1;i<=n;i++)
        a[i]+=n-mx;
    bool res=check();
    for(int i=1;i<=n;i++)
        a[i]--;
    if(res&&!check())
    for(int i=1;i<=n;i++)
        cout<<a[i]+1<<" ";
    else cout<<"-1"<<endl;
    return 0;
}
/*
5
1 3 -2 1


1 2 5 3 4
*/