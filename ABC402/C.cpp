#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6;
int n,m,k[N],b[N],ans[N];
vector<int> a[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            int x;
            cin>>x;
            a[i].push_back(x);
        }
    }
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        b[x]=i;
    }
    for(int i=1;i<=m;i++)
    {
        int res=0;
        for(int j=0;j<k[i];j++)
        {
            res=max(res,b[a[i][j]]);
        }
        ans[res]++;
    }
    for(int i=1;i<=n;i++)
    {
        ans[i]+=ans[i-1];
        cout<<ans[i]<<endl;
    }
    return 0;
}