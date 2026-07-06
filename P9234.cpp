#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=100,INF=1e9;
int n,m,a[N],ans=INF,ti=0;
unordered_map<int,int> mp;
inline void dfs(int l,int r,int cnt,int val,int mode)
{
    if(++ti>2e7+7e6)return;
    if(cnt>=ans||val>m)return;
    if(l>r)
    {
        if(mode)
        {
            if(mp[val])mp[val]=min(mp[val],cnt+1);
            else mp[val]=cnt+1;
        }
        else if(mp[m-val])
            ans=min(ans,cnt+mp[m-val]-1);
        return;
    }
    dfs(l+1,r,cnt+1,val+(a[l]>>1),mode);
    dfs(l+1,r,cnt,val+a[l],mode);
    dfs(l+1,r,cnt,val,mode);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    scanf("%lld%lld",&n,&m),m*=2;
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]),a[i]*=2;
    sort(a+1,a+1+n);
    dfs(1,n/2,0,0,true);
    dfs(n/2+1,n,0,0,false);
    if(ans!=INF) cout<<ans;
    else cout<<"-1";
    return 0;
}