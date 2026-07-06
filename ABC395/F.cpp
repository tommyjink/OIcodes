#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+100;
int n,x,u[N],d[N],l=0,r=1e10,ans=0;
bool check(int k)
{
    int l=k-d[1],r=u[1];
    for(int i=2;i<=n;i++)
    {
        int ll=k-d[i],rr=u[i];
        l=max(l-x,ll);
        r=min(r+x,rr);
        if(l>r)return false;
    }
    return true;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>x;
    for(int i=1;i<=n;i++)
        cin>>u[i]>>d[i],
        r=min(r,u[i]+d[i]);
    while(l<r)
    {
        int mid=(l+r+1)>>1;
        if(check(mid))l=mid;
        else r=mid-1;
    }
    for(int i=1;i<=n;i++)
        ans+=u[i]+d[i]-l;
    cout<<ans<<endl;
    return 0;
}