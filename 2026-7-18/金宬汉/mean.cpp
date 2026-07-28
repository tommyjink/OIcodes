#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10;
int T,n,k,tot;
int cnt[N],a[N],ans[N];
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=k;i++)
        cnt[i]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cnt[a[i]]++;
        ans[i]=0;
    }
    tot=0;
    int id=0;
    for(int i=1;i<=k;i++)
    {
        if(cnt[i]&1)
        {
            tot++;
            id=i;
        }
    }
    if(tot>(n&1))
    {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    int l=1,r=n;
    if(n&1)
    {
        ans[(n+1)/2]=id;
        cnt[id]--;
    }
    for(int i=1;i<=k;i++)
    {
        while(cnt[i])
        {
            ans[l]=ans[r]=i;
            l++,r--;
            cnt[i]-=2;
        }
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("mean.in","r",stdin);
    freopen("mean.out","w",stdout);
    cin>>T;
    while(T--)solve();
    return 0;
}
