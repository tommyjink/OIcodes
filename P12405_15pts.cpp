#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int P=998244353;
int a[10000];
int qpow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)res=res*x%P;
        y>>=1;
        x=x*x%P;
    }
    return res%P;
}
void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    if(k==0)
    {
        cout<<"0"<<endl;
        return ;
    }
    memset(a,0,sizeof(a));
    a[n]=1;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            for(int jj=j+1;jj<=n;jj++)
                a[j]+=a[jj];
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        // cout<<a[i]<<" ";
        ans=(ans+a[i]*qpow(k,i)%P)%P;
    }
    // cout<<endl;
    cout<<ans<<endl;
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