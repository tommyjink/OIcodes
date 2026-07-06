#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e6+100;
int a[N];
void solve(int n)
{
    int ans=0;
    for(int i=1;i<=n;i++)
        a[i]=0;
    a[1]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=n/i,k=1;j>1;j--,k++)
        {
            a[i*j]=max(a[i*j],a[i]+k);
        }
        ans+=a[i];
        // cout<<a[i]<<" ";
        // printf("%3lld ",a[i]);
    }
    // cout<<endl;
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("test1.txt","w",stdout);
    for(int i=1;i<=100;i++)
        solve(i);
    return 0;
}