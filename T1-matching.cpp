#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6;
int n,a[N],b[N],c[N];
vector<int> d[N];
void solve()
{
    int ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {        
        cin>>a[i];
        c[i]=b[i]=a[i]-i;
    }
    sort(b+1,b+1+n);
    for(int i=1;i<=n;i++)
    {
        c[i]=lower_bound(b+1,b+1+n,c[i])-b;
        d[c[i]].push_back(i);
    }
    for(int i=1;i<=n;i++)
    {
        if(d[i].empty())continue;
        int siz=d[i].size();
        for(int j=siz-1;j>=0;j-=2)
        {
            if(j==0)continue;
            if(a[d[i][j]]+a[d[i][j-1]]>0)
                ans+=a[d[i][j]]+a[d[i][j-1]];
        }
        d[i].clear();
    }
    cout<<ans<<endl;
}
signed main()
{
    freopen("matching.in","r",stdin);
    freopen("matching.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
        solve();
    
    return 0;
}