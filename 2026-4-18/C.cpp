#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=3010;
int n;
int a[N],cnt[N],ans[N];
bool vis[N];
set<int> s;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int k=1;k<=n;k++)
    {
        s.clear();
        for(int i=0;i<=n+1;i++) s.insert(i),cnt[i]=0,vis[i]=0;
        for(int i=1;i<=k;i++)
        {
            cnt[a[i]]++;
            if(cnt[a[i]]==1) s.erase(a[i]);
        }
        vis[*s.begin()]=1;
        for(int i=k+1;i<=n;i++)
        {
            cnt[a[i-k]]--;
            if(!cnt[a[i-k]]) s.insert(a[i-k]);
            cnt[a[i]]++;
            if(cnt[a[i]]==1) s.erase(a[i]);
            vis[*s.begin()]=1;
        }
        for(int i=0;;i++)
            if(!vis[i])
            {
                ans[k]=i;
                break;
            }
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<' ';

    return 0;
}
