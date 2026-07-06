#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=25;
int n,k,a[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int ans=0;
    sort(a+1,a+1+n);
    do
    {
        int res=0;
        for(int i=1;i<n;i++)
            res+=((a[i+1]-a[i])%k+k)%k;
        ans=max(ans,res);
    }while(next_permutation(a+1,a+1+n));
    cout<<ans<<endl;
    return 0;
}