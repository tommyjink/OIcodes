#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6;
int n,a[N],b[N],c[N],d[N],ans=0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=2;i<=n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<=20;j++)
            if(i&(1ll<<j))
                b[j]++;
    for(int i=1;i<=n;i++)
    {
        c[i]=c[i-1]^a[i];
        for(int j=0;j<=20;j++)
            if(c[i]&(1ll<<j))
                d[j]++;
    }
    for(int i=0;i<=20;i++)
        if(d[i]!=b[i])
            ans^=(1ll<<i);
    for(int i=1;i<=n;i++)
    {
        ans^=a[i];
        cout<<ans<<" ";
    }
    return 0;
}
/*
6
1 6 1 4 1

2 3 5 4 0 1

0 1 7 6 2 3

4
2 1 2

0 2 3 1
*/