#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6;
int n,m,x,val[N],ff[N],fb[N],ans=-1,sum[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>x;
    for(int i=1;i<=n;i++)
        cin>>val[i],sum[i]=sum[i-1]+val[i];
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        ff[i]=ff[i-1];
        cnt+=val[i];
        if(cnt>=x)ff[i]++,cnt=0;
    }
    cnt=0;
    for(int i=n;i>=1;i--)
    {
        fb[i]=fb[i+1];
        cnt+=val[i];
        if(cnt>=x)fb[i]++,cnt=0;
    }
    if(ff[n]<m)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    for(int i=1;i<=n+1;i++)
    {
        int p=lower_bound(ff+1,ff+1+i-1,m-fb[i])-ff;
        ans=max(ans,sum[i-1]-sum[p]);
    }
    cout<<ans<<endl;
    return 0;
}