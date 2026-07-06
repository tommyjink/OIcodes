#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
/*
f[i]:i个点无向完全图圈的数量
g[i]:i个点无向完全图a->b路径数量
ans[i]:i个点答案

f[i]=f[i-1]+g[i-1]*C(i-1,2)
g[i]=g[i-1]*(i-2)+1
ans[i]=f[i-1]+C(i-2,2)*g[i-1]
*/
const int P=998244353;
int c(int x)
{
    return (x*(x-1)/2)%P;
}
void solve()
{
    int n=999000000;
    cin>>n;
    if(n<=1e5)
    {
        int f=0,g=0,ans=0;
        for(int i=1;i<=n;i++)
            ans=(f+c(i-2)*g)%P,f=(f+g*c(i-1))%P,g=(g*(i-2)+1)%P;
        cout<<ans<<endl;
        // cout<<f<<" "<<g<<" "<<ans<<endl;
    }
    else
    {
        int f=930477414,g=653816133,ans=276661282;
        for(int i=999000000+1;i<=n;i++)
            ans=(f+c(i-2)*g)%P,f=(f+g*c(i-1))%P,g=(g*(i-2)+1)%P;
        cout<<ans<<endl;
    }
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