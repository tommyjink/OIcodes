#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5005;
int n,a[N];
int dfs(int l,int r,int now)
{
    if(l==r)return now!=a[l];
    if(l>r)return 0;
    int p=l;
    for(int i=l;i<=r;i++)if(a[i]<a[p])p=i;
    return min(r-l+1,dfs(p+1,r,a[p])+dfs(l,p-1,a[p])+a[p]-now);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    cout<<dfs(1,n,0);
    return 0;
}