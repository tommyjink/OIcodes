#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6;
int n,m,a[N],tag[N],ans=N,mx=0;

signed main()
{
    freopen("mex.in","r",stdin);
    freopen("mex.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i],mx=max(mx,a[i]);
    mx++;
    for(int i=1;i<=min(n,m);i++)
        tag[a[i]]++;
    for(int i=0;i<=mx;i++)
    {
        if(!tag[i])
        {
            ans=i;
            break;
        }
    }
    for(int i=m+1;i<=n;i++)
    {
        tag[a[i]]++;
        tag[a[i-m]]--;
        if(tag[a[i-m]]==0)
            ans=min(ans,a[i-m]);
    }
    cout<<ans<<endl;
    return 0;
}