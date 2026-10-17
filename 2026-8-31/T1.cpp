#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],b[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    int ans=0;
    while(next_permutation(a+1,a+1+n))
    {
        int res=0,now=a[1];
        for(int i=1;i<=n;i++)
            now&=a[i],res+=now;
        ans=max(ans,res);
    }
    cout<<ans<<endl;
    return 0;
}