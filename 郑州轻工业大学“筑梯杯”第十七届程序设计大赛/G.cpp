#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6;
int n,a[N],b[N],aa[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],aa[i]=a[i];
    for(int j=1;j<=n;j++)
        cin>>b[j];
    sort(a+1,a+1+n);
    // sort(b+1,b+1+n);
    for(int i=1;i<=n;i++)
    {
        int p=lower_bound(a+1,a+1+n,aa[i])-a-1;
        // cout<<p<<endl;
        cout<<max(0ll,b[i]*2-p)<<" ";
    }
    return 0;
}