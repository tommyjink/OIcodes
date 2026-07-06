#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],b[N];
int solve()
{
    int ans=0;
    int l=1,r=n,ll=1,rr=n;
    for(int i=1;i<=n;i++)
    {
        if(a[l]<b[ll]||a[r]<b[rr])
            l++,rr--;
        else if(a[l]>b[ll])
            l++,ll++,ans+=2;
        else if(a[r]>b[rr])
            r--,rr--,ans+=2;
        else if(a[l]==b[rr])
            r--,rr--,ans++;
        else l++,rr--;
    }
    return ans;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    int ans1=0,ans2=0;
    ans1=solve();
    for(int i=1;i<=n;i++)
        swap(a[i],b[i]);
    ans2=solve();
    cout<<ans1<<" "<<2*n-ans2<<endl;
    return 0;
}
/*
6
10000000
10000000
10000000
10000000
10000000
10000000
0
0
0
0
0
0
12 12

2
1
3
2
4
2 0

*/