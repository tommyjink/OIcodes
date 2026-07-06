#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10;
int n,a[N],f[N],g[N];
vector<int> v[N];
void solve()
{
    memset(g,0,sizeof(g));
    memset(f,0,sizeof(f));
    int ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        for(auto j:v[a[i]])
            g[j]=f[j]++;
        for(auto j:v[a[i]])
            for(auto k:v[j])
                if(j!=k)g[k]-=g[j];
        for(auto j:v[a[i]])
            ans+=g[j]*j*(n-i);
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=N-1;i>0;i--)
        for(int j=1;j*i<N;j++)
            v[i*j].push_back(i);
    int t;cin>>t;
    while(t--)
        solve();
    return 0;
}