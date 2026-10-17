#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],cnt[N],vis[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],vis[a[i]]++;
    for(int i=N-1;i>=1;i--)
    {
        for(int j=i;j<N;j+=i)cnt[i]+=vis[j];
        if(cnt[i]>1)cout<<i<<endl,exit(0);
    }

    return 0;
}