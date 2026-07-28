#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=3e5+10;
int n,m,x,mx;
int cnt[N],sum[N],ans[N];
__int128 f[N];

__int128 C(int n,int m)
{
    if(n<m)return 0;
    __int128 ans=1;
    for(int i=1;i<=m;i++)
        ans=ans*(n-i+1)/i;
    return ans;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("sor.in","r",stdin);
    freopen("sor.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        cnt[x]++;
        mx=max(mx,x);
    }
    for(int i=1;i<=mx;i++)
        for(int j=i;j<=mx;j+=i)
            sum[i]+=cnt[j];
    for(int i=1;i<=m;i++)
        ans[i]=-1;
    for(int t=1;t<=7;t++)
    {
        for(int i=mx;i>=1;i--)
        {
            f[i]=C(sum[i],t);
            for(int j=i+i;j<=mx;j+=i)
                f[i]-=f[j];
            if(i<=m&&ans[i]==-1&&f[i]>0)
                ans[i]=t;
        }
    }
    for(int i=1;i<=m;i++)
    {
        if(ans[i]==-1)cout<<"-1 -1"<<endl;
        else cout<<ans[i]<<" "<<sum[i]<<endl;
    }
    return 0;
}
